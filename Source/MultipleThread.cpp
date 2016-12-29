#include "../Include/MultipleThread.hpp"
#include <fstream> 

string MultipleThread::ReadFromFile(string fileName)
{
    ifstream myFile;
    myFile.open(fileName);
    char output[100];

    if(myFile.is_open()) 
    {
        while(!myFile.eof()) 
        {
            myFile >> output;
        }
    }
    myFile.close();
    return output;
 #if 0   
    ifstream infile; 
    infile.open(file.data()); //将文件流对象与文件连接起来 
    assert(infile.is_open()); //若失败,则输出错误消息,并终止程序运行 

    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
    infile.close(); //关闭文件输入流 
#endif

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