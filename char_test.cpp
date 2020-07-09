#include "stl_header.h"
#include <exception>
#include <windows.h>

using namespace std;

typedef lock_guard<std::recursive_mutex>		LockGuardType;

void kk(int& cnt, __int64 data[])
{
	cnt = 4;
	for (int i =0;i<cnt;i++)
	{
		data[i] = i * 10 + 1;
	}
}

class TSubWinsMgr
{
public:
	TSubWinsMgr()
	{
		m_req[1] = "sss";
		m_req[3] = "dsasss";
		m_req[2] = "dfs";
	}

	void func1()
	{
		LockGuardType lk(m_mutex);
		Sleep(1000 * 100);

		cout << "func 1...." << endl;
	}

	void func2()
	{
		//LockGuardType lk(m_mutex);
		Sleep(10);
		cout << "func 2...." << endl;
		m_req.erase(1);
	}

	std::recursive_mutex	m_mutex;
	map<int, string> m_req;
};

TSubWinsMgr  g_mgr;

std::recursive_mutex	m_mutex;

int main()
{	
	thread t([] {
		for (int i = 0; ; i++)
		{
			//LockGuardType lk(m_mutex);
			//cout << "thread .." << i << endl;
			//Sleep(10);

			g_mgr.func1();

		}

	});


	thread t2([] {
		for (int i = 0; ; i++)
		{
			//LockGuardType lk(m_mutex);
			//cout << "ddddthread .." << i << endl;
			g_mgr.func2();
			//Sleep(10);
		}

	});
	t.join();
	t2.join();

	Sleep(1000 * 10);
	cout << "finish ..." << endl;
	
	return 0;
}