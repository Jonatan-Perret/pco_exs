#ifndef PCOBARRIERHOAREMONITOR_H
#define PCOBARRIERHOAREMONITOR_H

#include "pcosynchro/pcohoaremonitor.h"

class PcoBarrierHoareMonitor : public PcoHoareMonitor
{
private:
    size_t waiting, maxWaitCount;
    Condition barrierCondition;
public:
    PcoBarrierHoareMonitor(unsigned int nbToWait): waiting(0), maxWaitCount(nbToWait)
    {
    }

    ~PcoBarrierHoareMonitor()
    {
    }

    void arrive()
    {
        monitorIn();
        waiting++;
        if(waiting < maxWaitCount){
            wait(barrierCondition);
        }
        else{
            for(size_t i = 0; i < waiting - 1; i ++){
                signal(barrierCondition);
            }
            waiting = 0;
        }

        monitorOut();
    }
};

#endif // PCOBARRIERHOAREMONITOR_H
