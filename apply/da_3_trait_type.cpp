#include "stl_header.h"

using namespace std;


template <class T, T v>
struct my_int_constant
{
    static const T value = v;
    typedef T value_type;
    typedef my_int_constant<T, v> type;
    operator value_type() { return value; }
};

/* test  operator value_type() { return value; }

    example  
    {
    typedef my_int_constant<int, 7> true_type;
    true_type a;
    int j = a;
    }

*/


//int main()
//{
//    typedef my_int_constant<int, 8> T1;
//    typedef my_int_constant<int, 5> T2;
//
//    cout << "is " << std::is_same<T1, T2>::value << endl;
//
//
//    return 0;
//}