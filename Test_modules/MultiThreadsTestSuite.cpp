#include "gtest/gtest.h"
#include "../Include/MultipleThread.hpp"

class MultiThreadsTestSuite : public ::testing::Test
{
public:
    void SetUp()
    {
        g_syncTds = 0;
    }

    void TearDown()
    {
        m_mt.clearFile("test.txt");
    }

    MultipleThread m_mt;
};

TEST_F(MultiThreadsTestSuite, TheContentOfTheFileShouldBeWhatWrittenIntoIt)
{
    m_mt.writeFile("test.txt", "ABCD");
    EXPECT_EQ("ABCD", m_mt.readFile("test.txt"));
}

TEST_F(MultiThreadsTestSuite, SingleThreadShouldWriteSingleChar)
{
    g_COUNT = 1;
    m_mt.creatThreadA("test.txt");
    EXPECT_EQ("A", m_mt.readFile("test.txt"));
}

TEST_F(MultiThreadsTestSuite, create2ThreadsWriteABIntoTheSameFile)
{
    g_COUNT = 2;
    m_mt.creatThreads();
    EXPECT_EQ("AB", m_mt.readFile("test.txt"));
}

TEST_F(MultiThreadsTestSuite, create2ThreadsWriteServeralABsIntoTheSameFile)
{
    g_COUNT = 10;
    m_mt.creatThreads();
    EXPECT_EQ("ABABABABAB", m_mt.readFile("test.txt"));
}

TEST_F(MultiThreadsTestSuite, ThreadsABWriteABsIntoFilesAB)
{
    m_mt.clearFile("A.txt");
    m_mt.clearFile("B.txt");
    
    //g_COUNT = 10;
    m_mt.createThreadAB();

    EXPECT_EQ("ABAB", m_mt.readFile("A.txt"));
    EXPECT_EQ("BABA", m_mt.readFile("B.txt"));
}
