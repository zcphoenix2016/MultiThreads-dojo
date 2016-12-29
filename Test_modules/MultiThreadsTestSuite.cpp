#include "gtest/gtest.h"
#include "../Include/MultipleThread.hpp"

TEST(MultiThreadsTestSuite, CreateAndWriteFile)
{   
    MultipleThread l_mt;
    l_mt.creatAndWriteFile("test.txt","ABCD");
    ASSERT_EQ("ABCD",l_mt.ReadFromFile("test.txt"));
    l_mt.clearfile("test.txt");
}


TEST(MultiThreadsTestSuite, SingleThreadShouldWriteSingleChar)
{   
    g_COUNT = 1;
    MultipleThread l_mt;
    l_mt.creatThreadA("test.txt");
    ASSERT_EQ("A",l_mt.ReadFromFile("test.txt"));
    l_mt.clearfile("test.txt");
    
}
#if 0
TEST(MultiThreadsTestSuite, create2ThreadsWriteABIntoTheSameFile)
{
    MultipleThread l_mt;
    l_mt.creatThreadA("test.txt");
    l_mt.creatThreadB("test.txt");
    ASSERT_EQ("AB",l_mt.ReadFromFile("test.txt"));
    l_mt.clearfile("test.txt");
}
#endif
TEST(MultiThreadsTestSuite, create2ThreadsWriteServeralABsIntoTheSameFile)
{
    g_COUNT = 10;
    MultipleThread l_mt;
    g_syncTds = 0;
    l_mt.creatThreads();
    ASSERT_EQ("ABABABABAB",l_mt.ReadFromFile("test.txt"));
    l_mt.clearfile("test.txt");
}
