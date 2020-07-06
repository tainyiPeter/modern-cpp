#include "stl_header.h"
#include <exception>

using namespace std;

int main()
{
	char szBuf[10] = { 0 };
	try
	{
		//sprintf_s(szBuf, _countof(szBuf), "qazxswedcvfrtgb");
		snprintf(szBuf, _countof(szBuf), "qazxswedcvfrtgb");

	}

	catch (...)
	{
		cout << "3" << endl;
	}
	
	
	cout << "resutl :" << szBuf << endl;
	return 0;
}