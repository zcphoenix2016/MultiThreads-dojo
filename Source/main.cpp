#include <iostream>
#include <thread>

void hello()
{
    std::cout << "Hello Concurrent World." << std::endl;
}

#ifndef UNIT_TEST
int main(int argc, char** argv)
#else
int ut_main(int argc, char** argv)
#endif
{
    std::thread t(hello);

    t.join();

    return 0;
}
