#include <iostream>
#include <thread>
#include "../Include/MultipleThread.hpp"

#ifndef UNIT_TEST
int main(int argc, char** argv)
#else
int ut_main(int argc, char** argv)
#endif
{
    MultipleThread l_mt;

    l_mt.createThreadAB();
    
    l_mt.clearFile("A.txt");
    l_mt.clearFile("B.txt");

    return 0;
}
