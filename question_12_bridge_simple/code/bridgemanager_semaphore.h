#ifndef BRIDGEMANAGER_SEMAPHORE_H
#define BRIDGEMANAGER_SEMAPHORE_H

#include <pcosynchro/pcosemaphore.h>
#include <pcosynchro/pcomutex.h>

const unsigned int CARWEIGHT = 1;
const unsigned int TRUCKWEIGHT = 10;

class BridgeManager
{
private:
    unsigned int maxWeight;
    PcoSemaphore semaphore;
    PcoMutex mutex;

public:
    BridgeManager(unsigned int maxWeight) 
        : maxWeight(maxWeight), semaphore(maxWeight), mutex()
    {
    }

    ~BridgeManager()
    {
    }

    void carAccess()
    {
        semaphore.acquire();
    }

    void truckAccess()
    {
        mutex.lock();
        for (unsigned int i = 0; i < TRUCKWEIGHT; i++)
        {
            semaphore.acquire();
        }
        mutex.unlock();
    }

    void carLeave()
    {
        semaphore.release();
    }

    void truckLeave()
    {
        for (unsigned int i = 0; i < TRUCKWEIGHT; i++)
        {
            semaphore.release();
        }
    }
};

#endif // BRIDGEMANAGER_SEMAPHORE_H
