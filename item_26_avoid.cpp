#include "stl_header.h"

using namespace std;

std::multiset<std::string> names; // global data structure

std::string nameFromIdx(int idx)
{
	if (idx == 0) return "000";
	else if (idx == 1) return "111";
	else return "kkk";
}
// corresponding to idx

//void logAndAdd(const std::string& name)
//{
//	names.emplace(name); // add name to global data
//}

void logAndAdd(int idx) // new overload
{
	cout << "call int" << endl;
	names.emplace(nameFromIdx(idx));
}

template<typename T>
void logAndAdd(T&& name)
{
	cout << "call T&&" << endl;
	//names.emplace(std::forward<T>(name));
}

void test_logadd()
{
	std::string petName("Darla");
	logAndAdd(petName); // pass lvalue std::string
	logAndAdd(std::string("Persephone")); // pass rvalue std::string
	logAndAdd("Patty Dog"); // pass string literal

	int s = 1;
	logAndAdd(s);
}

void display()
{
	for (auto it : names)
	{
		cout << "name is :" << it.c_str() << endl;
	}
}


class Person {
public:
	template<typename T>
	explicit Person(T&& n) // perfect forwarding ctor;
		: name(std::forward<T>(n)) 
	{
		cout << "person T&& " << endl;
	} // initializes data member
	explicit Person(int idx) // int ctor
		: name(nameFromIdx(idx)) 
	{
		cout << "person int " << endl;
	}

	Person(const Person& rhs) // copy ctor (compiler-generated)
	{
		cout << "const Person& rhs" << endl;
	}

	Person(Person&& rhs) // move cto (compiler-generated)
	{
		cout << "call Person&& rhs" << endl;
	}

private:
	std::string name;
};

int main()
{
	Person p("panyuanbo");
	short s = 1;
	Person p2(s);

	return 0;
}