#include <string>
#include <thread>
using namespace std;

class MultipleThread
{
public:
      void creatThreads();
      void creatThreadA(string fileName);
      void creatThreadB(string fileName);
      void creatThreadC(string fileName);
      void creatThreadD(string fileName);
      string ReadFromFile(string fileName);
      static void creatAndWriteFile(string name,string content);
      void clearfile(string fileName);      
};