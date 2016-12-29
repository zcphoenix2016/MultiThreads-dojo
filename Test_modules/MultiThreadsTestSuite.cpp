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
    MultipleThread l_mt;
    l_mt.creatThreadA("test.txt");
    ASSERT_EQ("A",l_mt.ReadFromFile("test.txt"));
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