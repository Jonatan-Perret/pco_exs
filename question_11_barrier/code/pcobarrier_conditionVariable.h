#ifndef PCOBARRIERCONDITIONVARIABLE_H
#define PCOBARRIERCONDITIONVARIABLE_H

#include "pcosynchro/pcoconditionvariable.h"

class PcoBarrierConditionVariable
{
private:
    size_t waiting, maxWaitCount;
    PcoConditionVariable barrierCondition;
    PcoMutex mutex;

public:
    PcoBarrierConditionVariable(unsigned int nbToWait): waiting(0), maxWaitCount(nbToWait)
    {
    }

    ~PcoBarrierConditionVariable()
    {
    }

    void arrive()
    {
        mutex.lock();
        this->waiting++;
        if(this->waiting < this->maxWaitCount){
            barrierCondition.wait(&mutex);
            mutex.unlock();
            return;
        }
        this->barrierCondition.notifyAll();
        waiting = 0;
        mutex.unlock();
    }
};

#endif // PCOBARRIERCONDITIONVARIABLE_H
