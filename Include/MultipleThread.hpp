#pragma once

#include <string>
#include <thread>
#include <mutex>
#include <vector>

class MultipleThread
{
public:
    void        execute();
    void        clearFile(const std::string&);
    std::string readFile(const std::string&);
    static void writeFile(const std::string&, const std::string&);
    static void setCount(int);

private:
    static void threadFunction(int);

    static int                      m_count;
    static int                      m_numOfThreads;
    static std::vector<int>         m_statusOfFiles;
    static std::vector<std::mutex>  m_mutexs;
    static std::vector<std::string> m_contents;
};
