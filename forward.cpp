#include "stl_header.h"
#include "Widget.h"

using namespace std;

class Widget {
public:
	//template<typename T>
	//void setName(T&& newName) // universal reference
	//{
	//	name = std::move(newName);
	//} // compiles, but is// bad, bad, bad!


	void setName(const std::string& newName) // set from
	{
		cout << "setNmae const .." << endl;
		name = newName;
	} // const lvalue

	void setName(std::string&& newName) // set from
	{
		cout << "setNmae && .." << endl;
		name = std::move(newName);
	}

	void print_name()
	{
		cout << "the name is:" << name.c_str() << endl;
	}

private:
	std::string name;
	//std::shared_ptr<SomeDataStructure> p;
};

void process(const Widget& lvalArg)
{
	cout << "process lvalues " << endl;
}

void process(Widget&& rvalArg)
{
	cout << "process rvalues " << endl;
}

template<typename T> // template that passes
void logAndProcess(T&& param) // param to process
{
//	auto now = std::chrono::system_clock::now();
	//makeLogEntry("Calling 'process'", now);
	
	process(std::forward<T>(param));
}

string getWidgetName()
{
	string s;
	s = "haha";

	return s;
}

void test_widget()
{
	Widget w;
	auto n = getWidgetName(); // n is local variable
	cout << "n is " << n.c_str() << endl;
	w.setName("niu yuue");
}



//int main()
//{
//	test_logadd();
//
//	return 0;
//}