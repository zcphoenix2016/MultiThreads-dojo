#include "gtest/gtest.h"
#include "../Include/MultipleThread.hpp"

TEST(MultiThreadsTestSuite, TheContentsOfFilesShouldBeWhatWrittenByMultiThreads)
{
    MultipleThread l_mt;

    l_mt.clearFile("A.txt");
    l_mt.clearFile("B.txt");
    l_mt.clearFile("C.txt");
    l_mt.clearFile("D.txt");

    l_mt.execute();

    EXPECT_EQ("ABCDABCD", l_mt.readFile("A.txt"));
    EXPECT_EQ("BCDABCDA", l_mt.readFile("B.txt"));
    EXPECT_EQ("CDABCDAB", l_mt.readFile("C.txt"));
    EXPECT_EQ("DABCDABC", l_mt.readFile("D.txt"));
}
