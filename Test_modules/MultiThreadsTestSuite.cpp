#include "gtest/gtest.h"
#include "../Include/MultipleThread.hpp"
#if 0
TEST(MultiThreadsTestSuite, CreateAndWriteFile)
{   
    MultipleThread l_mt;
    l_mt.creatAndWriteFile("test.txt","ABCD");
    ASSERT_EQ("ABCD",l_mt.ReadFromFile("test.txt"));
    l_mt.clearfile("test.txt");
}


TEST(MultiThreadsTestSuite, SingleThreadShouldWriteSingleChar)
{   
    MultipleThread l_mt;
    l_mt.creatThreadA("test.txt");
    ASSERT_EQ("AAAA",l_mt.ReadFromFile("test.txt"));
    l_mt.clearfile("test.txt");
    
}

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
    MultipleThread l_mt;
    g_syncTds = 0;
    l_mt.creatThreads();
    ASSERT_EQ("ABABABABAB",l_mt.ReadFromFile("test.txt"));
    l_mt.clearfile("test.txt");
}
