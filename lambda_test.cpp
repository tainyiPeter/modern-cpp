#include "stl_header.h"

using namespace std;

using Func = function<bool(int)>;
using FilterContianer = vector <Func>;

void func()
{
	int mode = 5;
	int tag = 98;

	Func f1 = ([&mode](int value) {
		return value % mode == 0; 
	} );
	//Func f2 = ([](int value) { return value % 7 == 0; });
	
	FilterContianer filters;
	filters.emplace_back(f1);
	//v.emplace_back(f2);

	bool ret = f1(85);

	cout << "ret is " << ret << endl;

	vector<int> v;

	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);			
	}

	auto it = find_if(v.begin(), v.end(), ([&](int& a) -> bool { 
		if (a == mode)
		{
			a = mode * 100;
			mode = 7;
			tag = 99;
			return true;
		}
		else
		{
			return false;
		}
		
	}));
	if (it == v.end()) cout << "not find .." << endl;
	else
	{
		cout << "mode :" << mode << " tag:" << tag << endl;
		cout << "ret is:" << *it << endl;
	}
}

int main()
{
	func();

	return 0;
}