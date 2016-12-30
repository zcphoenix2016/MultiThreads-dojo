#include "../Include/MultipleThread.hpp"
#include <fstream>
#include <mutex>

int g_syncTds = 0;

int g_COUNT = 10;
static std::mutex g_mutex;

std::string MultipleThread::readFile(const std::string& p_file)
{
    std::ifstream l_ifs;
    l_ifs.open(p_file);
    if(not l_ifs.is_open())
    {
        return "";
    }
    
    std::string l_output{}, l_str{};
    while(! l_ifs.eof())
    {
        l_ifs >> l_str;
        l_output += l_str;
        l_str.clear();
    }
    l_ifs.close();

    return l_output;
}

void MultipleThread::writeFile(const std::string& p_file, const std::string& p_content)
{
    std::ofstream l_ofs(p_file, std::ios::app);
    if(l_ofs)
    {
        l_ofs << p_content;
        l_ofs.close();
    }
}

void MultipleThread::threadStart(std::string name, std::string content)
{
    while(1)
    {
        std::lock_guard<std::mutex> lck(g_mutex);
        if ("A" == content)
        {
            if (g_syncTds == 0)
            {
                writeFile(name, content);
                g_syncTds = 1;
                g_COUNT--;
            }
        }

        if ("B" == content)
        {
            if (g_syncTds == 1)
            {
                writeFile(name, content);
                g_syncTds = 0;
                g_COUNT--;
            }
        }

        if(g_COUNT <= 1)
            break;
    }
}


void MultipleThread::creatThreads()
{
    std::thread tdA(MultipleThread::threadStart, "test.txt", "A");
    std::thread tdB(MultipleThread::threadStart, "test.txt", "B");
    tdA.join();
    tdB.join();
}

void MultipleThread::creatThreadA(std::string fileName)
{
    std::thread td(MultipleThread::threadStart, fileName, "A");
    td.join();
}

void MultipleThread::creatThreadB(std::string fileName)
{
    std::thread td(MultipleThread::threadStart, fileName, "B");
    td.join();
}

void MultipleThread::creatThreadC(std::string fileName)
{
    std::thread td(MultipleThread::threadStart, fileName, "C");
    td.join();
}

void MultipleThread::creatThreadD(std::string fileName)
{
    std::thread td(MultipleThread::threadStart, fileName, "D");
    td.join();
}
void MultipleThread::clearfile(std::string fileName)
{
    std::ofstream fout(fileName, std::ios::trunc);
    fout.close();
}