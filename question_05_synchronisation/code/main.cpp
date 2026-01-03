#include <iostream>
#include <gtest/gtest.h>

#include <pcosynchro/pcologger.h>
#include <pcosynchro/pcomutex.h>
#include <pcosynchro/pcosemaphore.h>
#include <pcosynchro/pcothread.h>

static int nbRuns = 0;
static PcoMutex mutex;
static PcoSemaphore semaphore;
static PcoMutex mutex_1, mutex_2;

void taskRunSemaphore(int id) {
    semaphore.acquire();

    mutex.lock();
    nbRuns ++;
    mutex.unlock();
    logger() << "Tache" << id << "executes" << '\n';
}

TEST(Synchro, Semaphore)
{
    const int NB_THREADS = 2;
    std::vector<std::unique_ptr<PcoThread>> threads(NB_THREADS);

    nbRuns = 0;

    for (int i = 0; i < NB_THREADS; i++) {
        threads[i] = std::make_unique<PcoThread>(taskRunSemaphore, i);
    }

    PcoThread::usleep(1000000);

    EXPECT_EQ(nbRuns, 0);

    // TODO : Release the threads
    semaphore.release();
    semaphore.release();
    


    for (int i = 0; i < NB_THREADS; i++) {
        threads[i]->join();
    }

    EXPECT_EQ(nbRuns, NB_THREADS);
}

void taskRunMutex(int id) {
    // TODO : Wait here to start
    if (id == 0) {
        mutex_1.lock();
        mutex_1.unlock();
    } else {
        mutex_2.lock();
        mutex_2.unlock();
    }

    mutex.lock();
    nbRuns ++;
    mutex.unlock();
    logger() << "Tache" << id << "executes" << '\n';
}

TEST(Synchro, Mutex)
{
    const int NB_THREADS = 2;
    std::vector<std::unique_ptr<PcoThread>> threads(NB_THREADS);

    nbRuns = 0;

    mutex_1.lock();
    mutex_2.lock();

    for (int i = 0; i < NB_THREADS; i++) {
        threads[i] = std::make_unique<PcoThread>(taskRunMutex, i);
    }

    PcoThread::usleep(1000000);

    EXPECT_EQ(nbRuns, 0);

    // TODO : Release the threads
    mutex_1.unlock();
    mutex_2.unlock();

    for (int i = 0; i < NB_THREADS; i++) {
        threads[i]->join();
    }

    EXPECT_EQ(nbRuns, NB_THREADS);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    logger().initialize(argc, argv);
    return RUN_ALL_TESTS();
}

