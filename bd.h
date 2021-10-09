#ifndef BD_H
#define BD_H
#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
#include "time.h"

using namespace std;

class BD
{
private:
    mutex MWr;
    mutex MVC;

    int CountR = 0;
    int CountW = 0;
public:
    void Read(int Wait);
    void BlockedRead(int Wait);
    void Write(int Wait);
    BD();
    ~BD();
};

#endif // BD_H
