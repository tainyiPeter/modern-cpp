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

void func_lambda_11()
{
	
}

int g_k;
int g_l;

void func_lambda_10()
{
	int mode = 5;
	int kv = 99;

	Func f1 = ([mode, &kv](int value) -> bool {
		//mode = 100;
		g_k = mode;
		g_l = kv;
		kv = 44;
		return value % mode == 0;
	});

	auto ret = f1(58);
	cout << "call func_10:" << ret \
		<< " mode:" << mode \
		<< " g_k:" << g_k \
		<< " g_l:" << g_l \
		<< " kv:" << kv \
		<< endl;
}

//int main()
//{
//	func_lambda_10();
//
//	return 0;
//}

