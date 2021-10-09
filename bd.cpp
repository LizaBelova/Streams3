#include "bd.h"

void BD::Read(int Wait)
{
    //MVC.lock();
    unique_lock<mutex> lock(MVC);
    while(CountW > 0)
    {
        //MVC.unlock();
        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(60));
        //MVC.lock();
        lock.lock();
    }
    CountR++;
    //MVC.unlock();
    lock.unlock();
    cout << "Reading" << endl;
    this_thread::sleep_for(chrono::milliseconds(Wait));
    //MVC.lock();
    lock.lock();
    CountR--;
    //MVC.unlock();
    lock.unlock();
}

void BD::BlockedRead(int Wait)
{
    //MWr.lock();
    unique_lock<mutex> lock(MWr);
    cout << "Reading" << endl;
    this_thread::sleep_for(chrono::milliseconds(Wait));
    //MWr.unlock();
    lock.unlock();
}

void BD::Write(int Wait)
{
    //MWr.lock();
    unique_lock<mutex> lock(MWr);
    //MVC.lock();
    unique_lock<mutex> lock(MVC);
    CountW++;
    while(CountR > 0)
    {
        //MVC.unlock();
        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(60));
        //MVC.lock();
        lock.lock();
    }
    //MVC.unlock();
    lock.unlock();
    cout << "Writing" << endl;
    this_thread::sleep_for(chrono::milliseconds(Wait));
    //MVC.lock();
    lock.lock();
    CountW--;
    //MVC.unlock();
    lock.unlock();
    //MWr.unlock();
    lock.unlock();
}

BD::BD()
{
}

BD::~BD()
{
}
