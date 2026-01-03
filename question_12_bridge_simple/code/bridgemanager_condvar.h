#ifndef BRIDGEMANAGER_CONDVAR_H
#define BRIDGEMANAGER_CONDVAR_H

#include <pcosynchro/pcomutex.h>
#include <pcosynchro/pcoconditionvariable.h>

const unsigned int CARWEIGHT = 1;
const unsigned int TRUCKWEIGHT = 10;

class BridgeManager
{
private:
    unsigned int maxWeight, currentWeight;
    PcoMutex mutex;
    PcoConditionVariable condition;

public:
    BridgeManager(unsigned int maxWeight) : maxWeight(maxWeight), currentWeight(0)
    {
    }

    ~BridgeManager()
    {
    }

    void carAccess()
    {
        mutex.lock();
        while (currentWeight + CARWEIGHT > maxWeight)
        {
            // can't go through
            condition.wait(&mutex);
        }
        // can continue
        currentWeight += CARWEIGHT;
        mutex.unlock();
    }

    void truckAccess()
    {
        mutex.lock();
        while (currentWeight + TRUCKWEIGHT > maxWeight)
        {
            // can't go through
            condition.wait(&mutex);
        }
        // can continue
        currentWeight += TRUCKWEIGHT;
        mutex.unlock();
    }

    void carLeave()
    {
        mutex.lock();
        currentWeight -= CARWEIGHT;
        mutex.unlock();
        condition.notifyAll();
    }

    void truckLeave()
    {
        mutex.lock();
        currentWeight -= TRUCKWEIGHT;
        mutex.unlock();
        condition.notifyAll();
    }
};

#endif // BRIDGEMANAGER_CONDVAR_H
