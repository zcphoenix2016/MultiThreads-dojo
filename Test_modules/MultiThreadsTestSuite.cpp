#include "gtest/gtest.h"
#include "../Include/MultipleThread.hpp"

TEST(MultiThreadsTestSuite, TheContentsOfFilesShouldBeWhatWrittenByMultiThreads)
{
    MultipleThread::setCount(4);
    MultipleThread l_mt;

    l_mt.clearFile("A.txt");
    l_mt.clearFile("B.txt");
    l_mt.clearFile("C.txt");
    l_mt.clearFile("D.txt");

    l_mt.execute();

    EXPECT_EQ("ABCDABCDABCDABCD", l_mt.readFile("A.txt"));
    EXPECT_EQ("BCDABCDABCDABCDA", l_mt.readFile("B.txt"));
    EXPECT_EQ("CDABCDABCDABCDAB", l_mt.readFile("C.txt"));
    EXPECT_EQ("DABCDABCDABCDABC", l_mt.readFile("D.txt"));
}
