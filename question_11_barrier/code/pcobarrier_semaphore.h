#ifndef PCOBARRIERSEMAPHORE_H
#define PCOBARRIERSEMAPHORE_H

#include "pcosynchro/pcosemaphore.h"

class PcoBarrierSemaphore
{
private:
    PcoSemaphore barrier, mutex{1};
    size_t waiting = 0;
    size_t maxWaitCount;

public:
    PcoBarrierSemaphore(unsigned int nbToWait) : barrier(0), maxWaitCount(nbToWait)
    {
    }

    ~PcoBarrierSemaphore()
    {
        for (int i = 0; i < waiting; i++)
        {
            barrier.release();
        }
    }

    void arrive()
    {
        mutex.acquire();
        this->waiting++;
        mutex.release();
        mutex.acquire();
        if (this->waiting == this->maxWaitCount)
        {
            // release N - 1
            for (int i = 0; i < (this->waiting - 1); i++)
            {
                barrier.release();
            }
            this->waiting = 0;
            return;
        }
        mutex.release();
        barrier.acquire();
    }
};

#endif // PCOBARRIERSEMAPHORE_H
