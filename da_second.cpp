#include "type_name.h"
#include <string>
#include <set>
#include <map>
#include <vector>
#include "ObjectPool.hpp"

using namespace std;

int C;

class C {
private:
	int i[2];
public:
	static int f() {
		return sizeof(C);
	}
};

int f()
{
	return sizeof(C);
}


class Player {
public:
	Player(int age) { age_ = age; }

	int age_;
};

struct MyObject {
	MyObject() 
	{ 
		cout << "MyObject " << endl;
	}
	MyObject(int a) { cout << "MyObject int" << endl; }

	MyObject(const int& a, const int& b) { cout << "MyObject int int" << endl; }

	void display(const string& s) {
		cout << "display:" << s.c_str() << endl;
	}
};

void display(shared_ptr<MyObject> sp, const string& s) 
{
	if (nullptr != sp)
	{
		sp->display(s);
	}
}

void TestObjPool() 
{
	ObjectPool<MyObject> pool;
	pool.Init(3);
	{
		auto p = pool.Get();
		display(p, "p");
		auto p2 = pool.Get();
		display(p2, "p2");
	}

	auto p = pool.Get();
	display(p, "p");
}

//int main()
//{
//	TestObjPool();
//
//	return 0;
//}