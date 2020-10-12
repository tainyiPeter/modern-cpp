#include <iostream>
using namespace std;

#include <iostream>
#include <memory>
#include <utility>

struct A 
{
    A(int&& n) { std::cout << "rvalue overload, n=" << n << "\n"; }
    A(int& n) { std::cout << "lvalue overload, n=" << n << "\n"; }
};

class B 
{
public:
    template<class T1, class T2, class T3>
    B(T1&& t1, T2&& t2, T3&& t3) :
        a1_{ static_cast<T1&&>(t1) },
        a2_{ static_cast<T2&&>(t2) },
        a3_{ static_cast<T3&&>(t3) }
    {
    }

private:
    A a1_, a2_, a3_;
};

template<class T, class U>
std::unique_ptr<T> make_unique1(U&& u)
{
    return std::unique_ptr<T>(new T(std::forward<U>(u)));
}

template<class T, class... U>
std::unique_ptr<T> make_unique2(U&&... u)
{
    return std::unique_ptr<T>(new T(std::forward<U>(u)...));
}


struct Student {
    int age;
    bool gender;
    string s;
};


union T {
    Student s;
    int id;
    char name[10];
};

void SunOfFloat(int count, ...)
{

}

class Person {
public:
    template < typename T
        ,
        typename = typename std::enable_if<
        !std::is_same<Person, typename std::decay<T>::type>::value \
        >::type

        //!std::is_same<Person, T>::value
    >
    explicit Person(T&& t)
    {
        cout << "call construct Person(T&&) " << endl;
    }

    Person(int i)
    {
        cout << "call construct Person(int) " << endl;
    }

    Person()
    {
        cout << "call construct Person() " << endl;
    }
};

typename std::enable_if<true, std::string>::type t; //ÕýÈ·

int main()
{
    //t = "string";
    //bool ret = std::is_same<std::enable_if<true, int>::type, int>::value;

    //cout << "ret:" << ret << endl;

    Person p();

    cout << "---------------" << endl;
    short k = 0;
    Person p2(k);


    return 0;
}