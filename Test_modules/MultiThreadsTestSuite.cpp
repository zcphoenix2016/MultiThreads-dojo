#include "gtest/gtest.h"
#include "../Include/MultipleThread.hpp"

TEST(MultiThreadsTestSuite, CreateAndWriteFile)
{   
    MultipleThread l_mt;
    l_mt.creatAndWriteFile("A.txt","ABCD");
    ASSERT_EQ("ABCD",l_mt.ReadFromFile("A.txt"));
}
