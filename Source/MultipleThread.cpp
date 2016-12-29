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
    infile.open(file.data()); //���ļ����������ļ��������� 
    assert(infile.is_open()); //��ʧ��,�����������Ϣ,����ֹ�������� 

    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
    infile.close(); //�ر��ļ������� 
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