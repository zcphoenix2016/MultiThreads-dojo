#pragma once

#include <string>
#include <thread>
#include <mutex>
#include <vector>

class MultipleThread
{
public:
    void        execute();
    std::string readFile(const std::string&);
    static void writeFile(const std::string&, const std::string&);
    void        clearFile(const std::string&);
    static void setCount(int);

private:
    static void threadFunction(int);

    static std::vector<int>         m_status;
    static std::vector<std::mutex>  m_mutexs;
    static std::vector<std::string> m_contents;
    static int                      m_count;
    static int                      m_numOfThreads;
};