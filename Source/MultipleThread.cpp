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

void MultipleThread::creatAndWriteFile(string name,string content)
{
    ofstream fout(name);
    if (fout) 
    {  
        fout << content << endl;
        fout.close();
    }  
} 

void MultipleThread::creatThreads()
{
    thread td(MultipleThread::creatAndWriteFile, "B.txt", "A");
    td.join();
}