#include "../Include/MultipleThread.hpp"
#include <fstream> 
#include <mutex> 

int g_syncTds = 0;

int g_COUNT = 10;
static mutex g_mutex;

string MultipleThread::ReadFromFile(string fileName)
{
    ifstream myFile;
    myFile.open(fileName);
    string output;

    if(myFile.is_open()) 
    {
        while(!myFile.eof()) 
        {
            myFile >> output;
        }
        myFile.close();
    }
    return output;

}

void MultipleThread::creatAndWriteFile(string name, string content)
{
    ofstream fout(name, ios::app);
    if (fout) 
    {  
        fout << content;
        fout.close();
    }
} 

void MultipleThread::threadStart(string name, string content)
{
    while(1)
    {
        lock_guard<mutex> lck(g_mutex);
        if ("A" == content)
        {
            if (g_syncTds == 0)
            {
                creatAndWriteFile(name, content);  
                g_syncTds = 1;
                g_COUNT--;
            }
        }
        
        if ("B" == content)
        {
            if (g_syncTds == 1)
            {
                creatAndWriteFile(name, content);  
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
    thread tdA(MultipleThread::threadStart, "test.txt", "A");   
    thread tdB(MultipleThread::threadStart, "test.txt", "B");
    tdA.join();
    tdB.join();
}

void MultipleThread::creatThreadA(string fileName)
{
    thread td(MultipleThread::threadStart, fileName, "A");   
    td.join();
}

void MultipleThread::creatThreadB(string fileName)
{
    thread td(MultipleThread::threadStart, fileName, "B");
    td.join();
}

void MultipleThread::creatThreadC(string fileName)
{
    thread td(MultipleThread::threadStart, fileName, "C");
    td.join();
}

void MultipleThread::creatThreadD(string fileName)
{
    thread td(MultipleThread::threadStart, fileName, "D");
    td.join();
}
void MultipleThread::clearfile(string fileName)
{
    ofstream fout(fileName, ios::trunc);
    fout.close();
}