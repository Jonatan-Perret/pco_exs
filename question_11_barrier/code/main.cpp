

#include <iostream>
#include <thread>
#include <mutex>

#include <gtest/gtest.h>

#include <pcosynchro/pcologger.h>

#include "pcobarrier_conditionVariable.h"
#include "pcobarrier_hoareMonitor.h"
#include "pcobarrier_semaphore.h"

class Checker
{
public:
    Checker(int nbThreads) : nbThreads(nbThreads) {}

    void arriving(int id)
    {
        mutex.lock();
        EXPECT_LT(id, nbThreads);
        nbArrived ++;
        EXPECT_LE(nbArrived, nbThreads);
        mutex.unlock();
    }

    void leaving(int /*id*/)
    {
        mutex.lock();
        EXPECT_EQ(nbArrived, nbThreads);
        nbLeaved ++;
        EXPECT_LE(nbLeaved, nbThreads);
        mutex.unlock();
    }

private:
    std::mutex mutex;
    int nbThreads;
    int nbArrived{0};
    int nbLeaved{0};
};

class PcoBarrierConditionVariableTest : public ::testing::Test
{

public:

    static const int NB_THREADS = 4;

    static void task(PcoBarrierConditionVariable *barrier, Checker *checker, int id) {
        checker->arriving(id);
        logger() << "Thread " << id << " arriving" << '\n';
        barrier->arrive();
        checker->leaving(id);
        logger() << "Thread " << id << " leaving" << '\n';
    }

    void testPcoBarrierTest(int nbThreads, PcoBarrierConditionVariable *barrier)
    {
        auto checker = std::make_unique<Checker>(nbThreads);
        std::vector<std::unique_ptr<std::thread> > threads(nbThreads);
        for(int i = 0; i < nbThreads; i++) {
            threads[i] = std::make_unique<std::thread>(task, barrier, checker.get(), i);
        }
        for(int i = 0; i < nbThreads; i++) {
            threads[i]->join();
        }
    }
};

const int PcoBarrierConditionVariableTest::NB_THREADS;

class PcoBarrierHoareMonitorTest : public ::testing::Test
{

public:

    static const int NB_THREADS = 4;

    static void task(PcoBarrierHoareMonitor *barrier, Checker *checker, int id) {
        checker->arriving(id);
        logger() << "Thread " << id << " arriving" << '\n';
        barrier->arrive();
        checker->leaving(id);
        logger() << "Thread " << id << " leaving" << '\n';
    }

    void testPcoBarrierTest(int nbThreads, PcoBarrierHoareMonitor *barrier)
    {
        auto checker = std::make_unique<Checker>(nbThreads);
        std::vector<std::unique_ptr<std::thread> > threads(nbThreads);
        for(int i = 0; i < nbThreads; i++) {
            threads[i] = std::make_unique<std::thread>(task, barrier, checker.get(), i);
        }
        for(int i = 0; i < nbThreads; i++) {
            threads[i]->join();
        }
    }
};

const int PcoBarrierHoareMonitorTest::NB_THREADS;

class PcoBarrierSemaphoreTest : public ::testing::Test
{

public:

    static const int NB_THREADS = 4;

    static void task(PcoBarrierSemaphore *barrier, Checker *checker, int id) {
        checker->arriving(id);
        logger() << "Thread " << id << " arriving" << '\n';
        barrier->arrive();
        checker->leaving(id);
        logger() << "Thread " << id << " leaving" << '\n';
    }

    void testPcoBarrierTest(int nbThreads, PcoBarrierSemaphore *barrier)
    {
        auto checker = std::make_unique<Checker>(nbThreads);
        std::vector<std::unique_ptr<std::thread> > threads(nbThreads);
        for(int i = 0; i < nbThreads; i++) {
            threads[i] = std::make_unique<std::thread>(task, barrier, checker.get(), i);
        }
        for(int i = 0; i < nbThreads; i++) {
            threads[i]->join();
        }
    }
};

const int PcoBarrierSemaphoreTest::NB_THREADS;


TEST_F(PcoBarrierConditionVariableTest, ConditionVariable) {
    auto barrier = std::make_unique<PcoBarrierConditionVariable>(NB_THREADS);
    testPcoBarrierTest(NB_THREADS, barrier.get());
}

TEST_F(PcoBarrierHoareMonitorTest, HoareMonitor) {
    auto barrier = std::make_unique<PcoBarrierHoareMonitor>(NB_THREADS);
    testPcoBarrierTest(NB_THREADS, barrier.get());
}

TEST_F(PcoBarrierSemaphoreTest, Semaphore) {
    auto barrier = std::make_unique<PcoBarrierSemaphore>(NB_THREADS);
    testPcoBarrierTest(NB_THREADS, barrier.get());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    logger().initialize(argc, argv);
    return RUN_ALL_TESTS();
}
