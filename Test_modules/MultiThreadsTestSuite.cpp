#include "gtest/gtest.h"
#include "../Include/MultipleThread.hpp"

TEST(MultiThreadsTestSuite, CreateAndWriteFile)
{   
    MultipleThread l_mt;
    l_mt.creatAndWriteFile("A.txt","ABCD");
    ASSERT_EQ("ABCD",l_mt.ReadFromFile("A.txt"));
}


TEST(MultiThreadsTestSuite, SingleThreadShouldWriteSingleChar)
{   
    MultipleThread l_mt;
    l_mt.creatThreads();
    ASSERT_EQ("A",l_mt.ReadFromFile("B.txt"));
}