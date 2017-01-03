#include "../Include/MultipleThread.hpp"
#include <fstream>
#include <algorithm>

std::vector<int>         MultipleThread::m_statusOfFiles{0, 1, 2, 3};
std::vector<std::string> MultipleThread::m_contents{"A", "B", "C", "D"};
std::vector<std::mutex>  MultipleThread::m_mutexs(4);
int                      MultipleThread::m_count = 2;
int                      MultipleThread::m_numOfThreads = 4;

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
    std::ofstream l_ofs(p_file, std::ios::trunc);

    if(l_ofs)
    {
        l_ofs.close();
    }
}

void MultipleThread::threadFunction(int p_id)
{
    std::vector<int> l_countOfLetters{0, 0, 0, 0};
    std::vector<std::string> l_fileNames{"A.txt", "B.txt", "C.txt", "D.txt"};
    while(std::any_of(l_countOfLetters.begin(), l_countOfLetters.end(), [](int p_count){return m_count > p_count;}))
    {
        for(int l_index = 0; l_index < 4; ++ l_index)
        {
            if(m_count > l_countOfLetters[l_index])
            {
                if(p_id == m_statusOfFiles[l_index])
                {
                    if(m_mutexs[l_index].try_lock())
                    {
                        writeFile(l_fileNames[l_index], m_contents[p_id]);
                        l_countOfLetters[l_index] ++;
                        m_statusOfFiles[l_index] = (m_statusOfFiles[l_index] + 1) % m_numOfThreads;
                    }
                    m_mutexs[l_index].unlock();
                }
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