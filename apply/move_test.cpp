#include "stl_header.h"


using namespace std;

//template <typename T>
//decltype (auto) my_move(T&& param)
//{
//	cout << "my_move 1" << endl;
//	using RetType = remove_reference_t<T>&&;
//	return static_cast<RetType>(param);
//}

template<typename T> // in namespace std
typename remove_reference<T>::type&&
my_move(T&& param)
{
	cout << "my_move 2" << endl;
	using ReturnType = typename remove_reference<T>::type&&; // see Item 9
	return static_cast<ReturnType>(param);
}

struct MoveValue {
	MoveValue()
	{
		strcpy_s(str_, _countof(str_), "haha...");
		v_.push_back(10);
		v_.push_back(7);
		v_.push_back(19);
	}
	char str_[100];
	int value_ = 99;
	vector<int> v_;
};



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

using stringType = my_string;
class Annotation {
public:
	explicit Annotation(stringType&& text)
		:value(std::move(text))
	{

	}

	stringType value;
};

void test_my_move()
{
	int k = 3;
	int&& m = std::forward<int>(k);

	cout << "k :" << k << " m :" << m << endl;

	k = 4;
	cout << "now k :" << k << " m :" << m << endl;
}

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
//	test_my_move();
//	return 0;
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