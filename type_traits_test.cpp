#include "stl_header.h"


using namespace std;

template<class T1, class T2>
void print_is_same() {
	std::cout << std::is_same<T1, T2>::value << '\n';
}

void test_same()
{
	using ReturnType = typename remove_reference<int&>::type&&;

	print_is_same<int&&, ReturnType>();
}

template <typename T>
struct GetLeftSize : std::integral_constant<int, 7>
{

};

template <typename T, T v>
struct my_constant
{
	static const T value = v;


	//typedef T value_type;
	//typedef my_constant<T, v>::type

	using value_type = T;
	using type = my_constant;

	operator value_type() { return value; }
};

struct A {
	A operator ()(int i)
	{
		cout << "operator " << endl;
		return A();
	}
};

//int main()
//{
//	//cout << "k:" << GetLeftSize<string>::value << endl;
//
//	bool ret = std::is_convertible<int, string>::value;
//
//	cout << "ret :" << ret << endl;
//
//
//	//std::result_of<A(int)>::type 
//
//
//	return 0;
//}