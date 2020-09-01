#include "stl_header.h"
#include <windows.h>

using namespace std;

void TestAsync()
{
    std::future<int> f1 = std::async(std::launch::async, []() {
        cout << "call " << endl;
        return 8;
    });

    std::cout << f1.get() << std::endl; //output: 8

    std::future<void> f2 = std::async(std::launch::async, []() {
        cout << "call void :";
        std::cout << 8 << std::endl; return;
    });

    f2.wait(); //output: 8

    std::future<int> future = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return 8;
    });

    std::cout << "waiting...\n";
    std::future_status status;

    do {
        status = future.wait_for(std::chrono::seconds(1));

        if (status == std::future_status::deferred)
        {
            std::cout << "deferred\n";
        }
        else if (status == std::future_status::timeout)
        {
            std::cout << "timeout\n";
        }
        else if (status == std::future_status::ready)
        {
            std::cout << "ready!\n";
        }
    } while (status != std::future_status::ready);

    std::cout << "result is " << future.get() << '\n';
}

int thread_da_5(const char* c)
{
    for (int i = 0; i < 10; i ++ )
    {
        cout << "param:" << c;
        cout << "call thread da: "<<i << endl;
    }
    
    return 0;
}

bool is_prime(int x)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    cout << "call is prime, x: " << x << endl;
    for (int i = 2; i < x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

void da_5_thread_test()
{
    std::future < bool > fut = std::async(is_prime, 44444444);

    // do something while waiting for function to set future:
    std::cout << "checking, please wait" << endl;
    std::chrono::milliseconds span(1000);

    while (1)
    {
        if (fut.wait_for(span) == std::future_status::timeout)
        {
            cout << "timeout ..." << endl;
        }
        else if (fut.wait_for(span) == std::future_status::ready)
        {
            cout << " ready ..." << endl;
            break;
        }
        else if (fut.wait_for(span) == std::future_status::deferred)
        {
            cout << " deferred ..." << endl;
        }
    }

    bool x = fut.get();         // retrieve return value

    std::promise<int> pr;

    std::thread t([](std::promise<int>& p)
    {
        cout << "mmm" << endl;
        p.set_value_at_thread_exit(9);
    }, std::ref(pr));

    std::future<int> f = pr.get_future();
    auto r = f.get();

    cout << "r is:" << r << endl;


    std::cout << "\n444444443 " << (x ? "is" : "is not") << " prime.\n";
}

int main()
{
    TestAsync();

    return 0;
}


//int main()
//{
//    //thread t(thread_da_5, "hello,");
//
//    cout << "main start ..." << endl;
//    __int64 tick = GetTickCount();
//    cout << "tick :" << tick << endl;
//    this_thread::sleep_for(chrono::seconds(3));
//    cout << "tick gap:" << GetTickCount() - tick << endl;
//
//    cout << "time out" << endl;
//
//    thread t([](int a) {
//        cout << "call thread proc ..."<< a << endl;
//    }, 4);
//   // t.join();
//    t.detach();
//
//    cout << "exit main() ..." << endl;
//
//    int i = 0;
//    cin >> i;
//
//    return 0;
//}