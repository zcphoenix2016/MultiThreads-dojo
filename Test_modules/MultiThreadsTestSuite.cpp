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
        m_mt.clearfile("test.txt"); 
    }
    MultipleThread m_mt;
};

TEST_F(MultiThreadsTestSuite, CreateAndWriteFile)
{   
    m_mt.creatAndWriteFile("test.txt","ABCD");
    EXPECT_EQ("ABCD",m_mt.ReadFromFile("test.txt"));
}


TEST_F(MultiThreadsTestSuite, SingleThreadShouldWriteSingleChar)
{   
    g_COUNT = 1;
    m_mt.creatThreadA("test.txt");
    EXPECT_EQ("A",m_mt.ReadFromFile("test.txt"));
    
}

TEST_F(MultiThreadsTestSuite, create2ThreadsWriteABIntoTheSameFile)
{
    g_COUNT = 2;
    m_mt.creatThreads();
    EXPECT_EQ("AB",m_mt.ReadFromFile("test.txt"));
}

TEST_F(MultiThreadsTestSuite, create2ThreadsWriteServeralABsIntoTheSameFile)
{
    g_COUNT = 10;
    m_mt.creatThreads();
    EXPECT_EQ("ABABABABAB",m_mt.ReadFromFile("test.txt"));
}
