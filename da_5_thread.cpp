#include "stl_header.h"
#include <windows.h>

using namespace std;

int thread_da_5(const char* c)
{
    for (int i = 0; i < 10; i ++ )
    {
        cout << "param:" << c;
        cout << "call thread da: "<<i << endl;
    }
    
    return 0;
}

int main()
{
    //thread t(thread_da_5, "hello,");

    cout << "main start ..." << endl;
    __int64 tick = GetTickCount();
    cout << "tick :" << tick << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "tick gap:" << GetTickCount() - tick << endl;

    cout << "time out" << endl;

    thread t([](int a) {
        cout << "call thread proc ..."<< a << endl;
    }, 4);
   // t.join();
    t.detach();

    cout << "exit main() ..." << endl;

    int i = 0;
    cin >> i;

    return 0;
}