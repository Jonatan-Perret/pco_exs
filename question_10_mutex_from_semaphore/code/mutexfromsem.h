#include <pcosynchro/pcosemaphore.h>
#include <iostream>


class MutexFromSem
{
protected:
    PcoSemaphore sem{1};
    PcoSemaphore guard{1};  // protects the locked flag
    bool locked = false;
public:
    MutexFromSem()
    {
        
    }

    ~MutexFromSem()
    {
    }

    void lock()
    {
        sem.acquire();
        guard.acquire();
        locked = true;
        guard.release();
    }

    void unlock()
    {
        guard.acquire();
        if(!locked) {
            guard.release();
            return;
        }
        locked = false;
        guard.release();
        sem.release();
    }

    //! Returns true if the mutex was successfully acquired, otherwise returns false without waiting if it is already locked
    bool trylock()
    {
        guard.acquire();
        if(locked){
            guard.release();
            return false;
        }
        locked = true;
        guard.release();
        sem.acquire();
        return true;
    }
};
