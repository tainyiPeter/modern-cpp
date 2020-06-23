#include "stl_header.h"
#include "Widget.h"

using namespace std;

class Widget {
public:
	Widget(Widget&& rhs)
		: s(std::move(rhs.s))
	{
		++moveCtorCalls;
	}

private:
	static std::size_t moveCtorCalls;
	std::string s;
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
	string s("ssss");
	return s;
}

//
//int main()
//{
//	Widget k = getWidget();
//	logAndProcess(k);
//
//	return 0;
//}