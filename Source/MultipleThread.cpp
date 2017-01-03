#include "../Include/MultipleThread.hpp"
#include <fstream>

int g_syncTds = 0;

int g_COUNT = 10;
static std::mutex g_mutex;

int MultipleThread::m_statusOfFileA = 0;
int MultipleThread::m_statusOfFileB = 1;
int MultipleThread::m_statusOfFileC = 2;
int MultipleThread::m_statusOfFileD = 3;
std::mutex MultipleThread::m_mutexs[4];

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

void MultipleThread::clearFile(const std::string& p_file)
{
    std::ofstream fout(p_file, std::ios::trunc);
    fout.close();
}

void MultipleThread::threadStart(std::string p_file, std::string p_content)
{
    do
    {
        std::lock_guard<std::mutex> lck(g_mutex);
        if("A" == p_content)
        {
            if(g_syncTds == 0)
            {
                writeFile(p_file, p_content);
                g_syncTds = 1;
                g_COUNT--;
            }
        }

        if("B" == p_content)
        {
            if(g_syncTds == 1)
            {
                writeFile(p_file, p_content);
                g_syncTds = 0;
                g_COUNT--;
            }
        }
    }while(1 < g_COUNT);
}

void MultipleThread::creatThreads()
{
    std::thread tdA(MultipleThread::threadStart, "test.txt", "A");
    std::thread tdB(MultipleThread::threadStart, "test.txt", "B");
    tdA.join();
    tdB.join();
}

void MultipleThread::funcA()
{
    int l_countFileA = 0, l_countFileB = 0;
    while(4 > l_countFileA || 4 > l_countFileB)
    {
        if(4 > l_countFileA)
        {
            if(m_mutexs[0].try_lock())
            {
                if(0 == m_statusOfFileA)
                {
                    writeFile("A.txt", "A");
                    l_countFileA ++;
                    m_statusOfFileA = 1;
                }
                m_mutexs[0].unlock();
            }
        }

        if(4 > l_countFileB)
        {
            if(m_mutexs[1].try_lock())
            {
                if(0 == m_statusOfFileB)
                {
                    writeFile("B.txt", "A");
                    l_countFileB ++;
                    m_statusOfFileB = 1;
                }
                m_mutexs[1].unlock();
            }
        }
    }
}

void MultipleThread::funcB()
{
    int l_countFileA = 0, l_countFileB = 0;
    while(4 > l_countFileA || 4 > l_countFileB)
    {
        if(4 > l_countFileA)
        {
            if(m_mutexs[0].try_lock())
            {
                if(1 == m_statusOfFileA)
                {
                    writeFile("A.txt", "B");
                    l_countFileA ++;
                    m_statusOfFileA = 0;
                }
                m_mutexs[0].unlock();
            }
        }

        if(4 > l_countFileB)
        {
            if(m_mutexs[1].try_lock())
            {
                if(1 == m_statusOfFileB)
                {
                    writeFile("B.txt", "B");
                    l_countFileB ++;
                    m_statusOfFileB = 0;
                }
                m_mutexs[1].unlock();
            }
        }
    }
}

void MultipleThread::createThreadAB()
{
    std::thread l_A(MultipleThread::funcA);
    std::thread l_B(MultipleThread::funcB);

    l_A.join();
    l_B.join();
}

void MultipleThread::creatThreadA(std::string p_file)
{
    std::thread td(MultipleThread::threadStart, p_file, "A");
    td.join();
}

void MultipleThread::creatThreadB(std::string fileName)
{
    std::thread td(MultipleThread::threadStart, fileName, "B");
    td.join();
}