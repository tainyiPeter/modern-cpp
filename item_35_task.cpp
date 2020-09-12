#include "stl_header.h"
#include <windows.h>
using namespace std;

void doAsyncWork(const string& s)
{
	//DWORD gap = chrono::seconds(1);

	cout << "the param is:" << s.c_str() << endl;

	for (int i =0; i < 6; ++ i)
	{
		cout << "doAsyncwork..."<< i << endl;
		//Sleep(1000);
		std::this_thread::sleep_for(1s);
		
		//Sleep(gap);
	}
}

//int main()
//{
//	//thread t(doAsyncWork);
//	//t.join();
//
//	auto fut = std::async(std::launch::async|std::launch::deferred, \
//		doAsyncWork, "hahaha ...");
//
//	cout << "fut.get..." << endl;
//
//	return 0;
//
//	//fut.get();
//	auto wStatus = fut.wait_for(2s);
//	if (std::future_status::ready == wStatus)
//	{
//		cout << "the status :" << (int)wStatus << endl;
//	}
//
//	cout << "finish ..." << endl;
//	return 0;
//}