#include "stl_header.h"

using namespace std;



struct S {
	double operator()(char, int&);
	float operator()(int);
};

struct C {
	double Func(char, int&);
};

//int main()
//{
//	bool ret = std::is_same<int, int>::value;
//	//cout << "ret is :"<< ret << endl;
//
//	// the result of invoking S with char and int& arguments is double
//	std::result_of<S(char, int&)>::type f = 3.14; // f has type double
//
//	int k = 3.14;
//
//
//	ret = std::is_same<decltype(k), int > ::value;
//
//
//	cout << "k:" << ret << endl;
//
//	return 0;
//
//	static_assert(std::is_same<decltype(f), double>::value, "");
//
//	// the result of invoking S with int argument is float
//	std::result_of<S(int)>::type d = 3.14; // f has type float
//	static_assert(std::is_same<decltype(d), float>::value, "");
//
//	// result_of can be used with a pointer to member function as follows
//	std::result_of<decltype(&C::Func)(C, char, int&)>::type g = 3.14;
//	static_assert(std::is_same<decltype(g), double>::value, "");
//
//	return 0;
//}