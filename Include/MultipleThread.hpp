#pragma once

#include <string>
#include <thread>
#include <mutex>

class MultipleThread
{
public:
    void        execute();
    std::string readFile(const std::string&);
    static void writeFile(const std::string&, const std::string&);
    void        clearFile(const std::string&);
    static void setCount(int);

private:
    static void        threadFunction(int);

    static int         m_status[4];
    static std::mutex  m_mutexs[4];
    static std::string m_contents[4];
    static int         m_count;
    static int         m_numOfThreads;
};