#include "stl_header.h"


using namespace std;

template <typename T>
decltype (auto) my_move(T&& param)
{
	cout << "my_move" << endl;
	using RetType = remove_reference_t<T>&&;
	return static_cast<RetType>(param);
}

class my_string {
public:
	my_string()
	{
		cout << "call default" << endl;
	}
	my_string(const char* c)
	{
		cout << "call c " << endl;
	}

	my_string(const my_string& rhs)
	{
		cout << "1.." << endl;
	}

	my_string(string&& rhs)
	{
		cout << "2.." << endl;
	}
};




void func(my_string&& m)
{
	cout << "call func &&..." << endl;
}

void func(const my_string& m)
{
	cout << "call func const ..." << endl;
}

//void func(my_string m)
//{
//	cout << "call func ..." << endl;
//}

class Annotation {
public:
	explicit Annotation(my_string text)
	{
		cout << "Annotation call ..." << endl;
	}
};


template <typename T>
void func(T&& param)
{
	cout << "call T&& ..." << endl;
}

template <typename T>
void func(T& param)
{
	cout << "call T& ..." << endl;
}

//int main()
//{
//	//my_string s;
//	//my_string k(my_move(s));
//
//	//func(my_move(s));
//
//	int a = 3;
//
//	func(move(a));
//
//	return 0;
//}