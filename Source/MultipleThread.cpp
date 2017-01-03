#include "../Include/MultipleThread.hpp"
#include <fstream>

int g_syncTds = 0;

int g_COUNT = 10;
static std::mutex g_mutex;

int MultipleThread::m_statusOfFileA = 0;
int MultipleThread::m_statusOfFileB = 1;
int MultipleThread::m_statusOfFileC = 2;
int MultipleThread::m_statusOfFileD = 3;
std::string MultipleThread::m_contents[4] = {"A", "B", "C", "D"};
std::mutex MultipleThread::m_mutexs[4];
int MultipleThread::m_count = 2;

void MultipleThread::setCount(int p_count)
{
    m_count = p_count;
}

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

void MultipleThread::threadFunction(int p_id)
{
    int l_countOfFileA = 0, l_countOfFileB = 0, l_countOfFileC = 0, l_countOfFileD = 0;
    while(m_count > l_countOfFileA 
         || m_count > l_countOfFileB
         || m_count > l_countOfFileC
         || m_count > l_countOfFileD)
    {
        if(m_count > l_countOfFileA)
        {
            if(m_mutexs[0].try_lock())
            {
                if(p_id == m_statusOfFileA)
                {
                    writeFile("A.txt", m_contents[p_id]);
                    l_countOfFileA ++;
                    m_statusOfFileA = (m_statusOfFileA + 1) % 4;
                }
                m_mutexs[0].unlock();
            }
        }

        if(m_count > l_countOfFileB)
        {
            if(m_mutexs[1].try_lock())
            {
                if(p_id == m_statusOfFileB)
                {
                    writeFile("B.txt", m_contents[p_id]);
                    l_countOfFileB ++;
                    m_statusOfFileB = (m_statusOfFileB + 1) % 4;
                }
                m_mutexs[1].unlock();
            }
        }
        
        if(m_count > l_countOfFileC)
        {
            if(m_mutexs[2].try_lock())
            {
                if(p_id == m_statusOfFileC)
                {
                    writeFile("C.txt", m_contents[p_id]);
                    l_countOfFileC ++;
                    m_statusOfFileC = (m_statusOfFileC + 1) % 4;
                }
                m_mutexs[2].unlock();
            }
        }
        
        if(m_count > l_countOfFileD)
        {
            if(m_mutexs[3].try_lock())
            {
                if(p_id == m_statusOfFileD)
                {
                    writeFile("D.txt", m_contents[p_id]);
                    l_countOfFileD ++;
                    m_statusOfFileD = (m_statusOfFileD + 1) % 4;
                }
                m_mutexs[3].unlock();
            }
        }
    }
}

void MultipleThread::execute()
{
    std::thread l_A(MultipleThread::threadFunction, 0);
    std::thread l_B(MultipleThread::threadFunction, 1);
    std::thread l_C(MultipleThread::threadFunction, 2);
    std::thread l_D(MultipleThread::threadFunction, 3);

    l_A.join();
    l_B.join();
    l_C.join();
    l_D.join();
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