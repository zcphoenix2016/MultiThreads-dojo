#include <string>
#include <thread>
using namespace std;

class MultipleThread
{
public:
      void creatThreads();
      string ReadFromFile(string fileName);
      static void creatAndWriteFile(string name,string content); 
};