#pragma once

#include <string>
#include <thread>

extern int g_syncTds;
extern int g_COUNT;

class MultipleThread
{
public:
    static void threadStart(std::string, std::string);
    void creatThreadA(std::string);
    void creatThreadB(std::string);
    void creatThreadC(std::string);
    void creatThreadD(std::string);
    void creatThreads();
    std::string readFile(std::string);
    static void writeFile(std::string,std::string);
    void clearfile(std::string);
};