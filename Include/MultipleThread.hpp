#pragma once

#include <string>
#include <thread>
#include <mutex>

extern int g_syncTds;
extern int g_COUNT;

class MultipleThread
{
public:
    static void threadStart(std::string, std::string);
    void creatThreadA(std::string);
    void creatThreadB(std::string);
    void creatThreads();
    void createThreadAB();
    std::string readFile(const std::string&);
    static void writeFile(const std::string&, const std::string&);
    void clearFile(const std::string&);

private:
    static void funcA();
    static void funcB();
    static std::string m_statusOfFileA;
    static std::string m_statusOfFileB;
    static std::mutex m_mutexs[4];
};