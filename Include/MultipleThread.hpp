#pragma once

#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <fstream>

class MultipleThread
{
public:
    void        execute();
    void        clearFile(const std::string&);
    std::string readFile(const std::string&);
    static void writeFile(std::ofstream&, const std::string&);
    static void setCount(int);

private:
    static void threadFunction(int);

    static int                        m_count;
    static int                        m_numOfThreads;
    static std::vector<int>           m_statusOfFiles;
    static std::vector<std::mutex>    m_mutexs;
    static std::vector<std::string>   m_contents;
    static std::vector<std::ofstream> m_ofs;
};
