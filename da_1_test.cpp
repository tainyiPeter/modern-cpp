#include <iostream>
#include <functional>

using std::placeholders::_1;


class B
{
public:
    B(const char* sz)
    {

    }

    int operator ()(const char* sz)
    {

        return 0;
    }
    B()
    { }


    char szBuf[100];

};

class A
{
public:
    
    int i_ = 0;
    B b;

    void output(int x, int y)
    {
        std::cout << x << " " << y << std::endl;
    }

};

//int main(void)
//{
//    A a;
//
//    //std::function<void(int, int)> fr =
//    //    std::bind(&A::output, &a, std::placeholders::_1, std::placeholders::_2);
//    //fr(1, 2);  //��� 1 2
//
//    //return 0;
//
//    std::function<int (char*)> fr_i = std::bind(&A::b, &a, std::placeholders::_1);  //vs13��bug���󶨳�Ա����Ҫ����
//
//   // fr_i() = 123;
//
//
//    std::cout << a.i_ << std::endl;  //��� 123
//
//    return 0;
//}