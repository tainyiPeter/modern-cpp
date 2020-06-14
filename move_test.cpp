#include "stl_header.h"

using namespace std;

template <typename T>
decltype (auto) my_move(T&& param)
{
	cout << "my_move" << endl;
	using RetType = remove_reference<T>&&;
	return static_cast<RetType>(param);
}

class my_string {
public:
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
	cout << "call func ..." << endl;
}

int main()
{

	my_string  s("s");

	auto r = my_move(s);
	func(  r );

	return 0;

}