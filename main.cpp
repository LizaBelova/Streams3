#include <QCoreApplication>
#include <iostream>
#include <thread>
#include <ctime>
#include "bd.h"

using namespace std;

BD SuperBD;
/*
void Reading()
{
    SuperBD.Read();
}

void Writing()
{
    SuperBD.Write();
}
*/

void Creating()
{
    srand(time(NULL));
    for (int i=0; i<5; i++)
    {
        int Wait=rand()%5101+450;            //определяем длительность чтения/записи
        if(rand()%5==3) SuperBD.Write(Wait); //случайное кол-во чтение/запись
        else SuperBD.Read(Wait);
             //SuperBD.BlockedRead(Wait);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    thread t1(Creating);
    thread t2(Creating);
    thread t3(Creating);
    thread t4(Creating);
    thread t5(Creating);

    t1.detach();
    t2.detach();
    t3.detach();
    t4.detach();
    t5.join();

    unsigned int time = clock();
    cout << "Time working: " << time << endl;
    return a.exec();
}
