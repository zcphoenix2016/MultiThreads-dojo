#pragma once

#include <string>
#include <thread>
#include <mutex>
//#include <map>

extern int g_syncTds;
extern int g_COUNT;

class MultipleThread
{
public:
    static void threadStart(std::string, std::string);
    void creatThreadA(std::string);
    void creatThreadB(std::string);
    void creatThreads();
    void execute();
    std::string readFile(const std::string&);
    static void writeFile(const std::string&, const std::string&);
    void clearFile(const std::string&);
    static void setCount(int);

private:
    static void threadFunction(int);
    static int         m_statusOfFileA;
    static int         m_statusOfFileB;
    static int         m_statusOfFileC;
    static int         m_statusOfFileD;
    static std::mutex  m_mutexs[4];
    static std::string m_contents[4];
    static int         m_count;
};