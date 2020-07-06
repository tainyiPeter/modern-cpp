#include "stl_header.h"
#include <windows.h>

using namespace std;


//constexpr auto tenMillion = 10000000; // see Item 15

constexpr auto tenMillion = 10'000'000; // C++14
// for constexpr
bool doWork(std::function<bool(int)> filter, // returns whether
	int maxVal = tenMillion) // computation was
{
	std::vector<int> goodVals; // values that
	// satisfy filter
	std::thread t([&filter, maxVal, &goodVals] // populate
	{ // goodVals
		for (auto i = 0; i <= maxVal; ++i)
		{
			if (filter(i)) goodVals.push_back(i);
		}
	});
	auto nh = t.native_handle(); // use t's native


	//if (conditionsAreSatisfied()) 
	//{
	//	t.join(); // let t finish
	//	performComputation(goodVals);
	//	return true; // computation was
	//} // performed


	return false; // computation was
}

using Fn = std::function<bool(int)>;

map<int, string> m;

//int main()
//{
//	m[1] = "ss";
//
//	Fn f = ( [](int param) -> bool {
//		cout << "the param is:" << param << endl;
//		return true;
//	} );
//	//auto ret = f(3);
//	//cout << "result is " << ret << endl;
//	thread t([] {
//		for (int i = 0; i<10;i++)
//		{
//			cout << "thread .."<< i << endl;
//			cout << m.begin()->second.c_str() << endl;
//			Sleep(1000);
//			
//		}
//		
//	});
//	//t.join();
//
//	cout << "joinable :" << t.joinable();
//
//	m.erase(11);
//
//	cout << "-------------------------------" << endl;
//	Sleep(1000 * 3);
//	t.join();
//	cout << "joinable :" << t.joinable();
//
//	return 0;
//}