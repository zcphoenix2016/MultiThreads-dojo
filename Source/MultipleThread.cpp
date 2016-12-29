#include "../Include/MultipleThread.hpp"
#include <fstream> 

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

void MultipleThread::creatThreadA(string fileName)
{
    thread td(MultipleThread::creatAndWriteFile, fileName, "A");   
    td.join();
}

void MultipleThread::creatThreadB(string fileName)
{
    thread td(MultipleThread::creatAndWriteFile, fileName, "B");
    td.join();
}

void MultipleThread::creatThreadC(string fileName)
{
    thread td(MultipleThread::creatAndWriteFile, fileName, "C");
    td.join();
}

void MultipleThread::creatThreadD(string fileName)
{
    thread td(MultipleThread::creatAndWriteFile, fileName, "D");
    td.join();
}
void MultipleThread::clearfile(string fileName)
{
    ofstream fout(fileName, ios::trunc);
    fout.close();
}