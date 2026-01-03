/** @file toilets.h
 *  @brief Reader-writer for toilets sharing
 *
 *  Implementation of a reader-writer resource manager for toilets sharing.
 *  Mutual exclusion between classes must be ensured
 *
 *
 *
 *  @author Yann Thoma
 *  @date 25.01.2022
 *  @bug No known bug except it is not implemented
 */

#ifndef TOILETS_H
#define TOILETS_H

#include <pcosynchro/pcosemaphore.h>
#include <pcosynchro/pcomutex.h>
#include <pcosynchro/pcoconditionvariable.h>
#include <pcosynchro/pcohoaremonitor.h>

#include "abstracttoilets.h"


class ToiletASemaphore : public AbstractToilet
{
public:
    ToiletASemaphore(int nbSeats) : AbstractToilet(nbSeats)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

class ToiletAMesa : public AbstractToilet
{
public:
    ToiletAMesa(int nbSeats) : AbstractToilet(nbSeats)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

class ToiletAHoare : public AbstractToilet, public PcoHoareMonitor
{
public:
    ToiletAHoare(int nbSeats) : AbstractToilet(nbSeats)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

class ToiletBSemaphore : public AbstractToilet
{
public:
    ToiletBSemaphore(int nbSeats) : AbstractToilet(nbSeats)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

class ToiletBMesa : public AbstractToilet
{
public:
    ToiletBMesa(int nbSeats) : AbstractToilet(nbSeats)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

class ToiletBHoare : public AbstractToilet, public PcoHoareMonitor
{
public:
    ToiletBHoare(int nbSeats) : AbstractToilet(nbSeats)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

class ToiletCSemaphore : public AbstractToilet
{
public:
    ToiletCSemaphore(int nbSeats) : AbstractToilet(nbSeats)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

class ToiletCMesa : public AbstractToilet
{
public:
    ToiletCMesa(int nbSeats) : AbstractToilet(nbSeats)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

class ToiletCHoare : public AbstractToilet, public PcoHoareMonitor
{
public:
    ToiletCHoare(int nbSeats) : AbstractToilet(nbSeats)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

class ToiletDSemaphore : public AbstractToilet
{
    int N;

public:
    ToiletDSemaphore(int nbSeats, int N = 3) : AbstractToilet(nbSeats), N(N)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

class ToiletDMesa : public AbstractToilet
{
    int N;

public:
    ToiletDMesa(int nbSeats, int N = 3) : AbstractToilet(nbSeats), N(N)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

class ToiletDHoare : public AbstractToilet, public PcoHoareMonitor
{
    int N;

public:
    ToiletDHoare(int nbSeats, int N = 3) : AbstractToilet(nbSeats), N(N)
    {}

    void manAccessing() override {
    }

    void manLeaving() override {
    }

    void womanAccessing() override {
    }

    void womanLeaving() override {
    }
};

#endif // TOILETS_H
