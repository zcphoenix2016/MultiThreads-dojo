#include <iostream>
#include <thread>
#include <chrono>
#include "../Include/MultipleThread.hpp"

#ifndef UNIT_TEST
int main(int argc, char** argv)
#else
int ut_main(int argc, char** argv)
#endif
{
    MultipleThread::setCount(10000);

    MultipleThread l_mt;
    
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    l_mt.execute();
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
     
    std::cout << "\n\n----Printing took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << "ms.\n";

    return 0;
}
