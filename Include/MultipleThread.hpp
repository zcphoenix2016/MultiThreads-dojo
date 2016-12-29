#include <string>
#include <thread>
using namespace std;

extern int g_syncTds;
extern int g_COUNT;

class MultipleThread
{
public:
      static void threadStart(string name, string content);
      void creatThreadA(string fileName);
      void creatThreadB(string fileName);
      void creatThreadC(string fileName);
      void creatThreadD(string fileName);
      void creatThreads();
      string ReadFromFile(string fileName);
      static void creatAndWriteFile(string name,string content);
      void clearfile(string fileName);      
};