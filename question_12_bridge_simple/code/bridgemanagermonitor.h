
#ifndef BRIDGEMANAGER_MONITOR_H
#define BRIDGEMANAGER_MONITOR_H

#include <pcosynchro/pcohoaremonitor.h>

const unsigned int CARWEIGHT = 1;
const unsigned int TRUCKWEIGHT = 10;

class BridgeManager : public PcoHoareMonitor
{
private:
    unsigned int maxWeight, currentWeight;
    Condition bridgeCondition;

public:
    BridgeManager(unsigned int maxWeight) : maxWeight(maxWeight), currentWeight(0)
    {
    }

    ~BridgeManager()
    {
    }

    void carAccess()
    {
        monitorIn();
        while (currentWeight + CARWEIGHT > maxWeight)
        {
            // can't go through
            wait(bridgeCondition);
        }
        // can go through
        currentWeight += CARWEIGHT;

        monitorOut();
    }

    void truckAccess()
    {
        monitorIn();
        while (currentWeight + TRUCKWEIGHT > maxWeight)
        {
            // can't go through
            wait(bridgeCondition);
        }

        // can go through
        currentWeight += TRUCKWEIGHT;

        monitorOut();
    }

    void carLeave()
    {
        monitorIn();
        currentWeight -= CARWEIGHT;
        signal(bridgeCondition);
        monitorOut();
    }

    void truckLeave()
    {
        monitorIn();
        currentWeight -= TRUCKWEIGHT;
        signal(bridgeCondition);
        monitorOut();
    }
};

#endif // BRIDGEMANAGER_MONITOR_H
