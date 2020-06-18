#include "Lazy.hpp"

#include <iostream>
#include <memory>

using namespace std;

struct BigObject
{
	BigObject()
	{
		std::cout << "lazy load big object" << std::endl;
	}
};

struct MyStruct
{
	MyStruct()
	{
		auto lm = ([] {return std::make_shared<BigObject>(); });
		m_obj = lazy(lm);
	}

	void Load()
	{
		m_obj.Value();
	}

	Lazy<std::shared_ptr<BigObject>> m_obj;
};

int Foo(int x)
{
	return x * 2;
}

float FooK(int x, float y) {

	return 3 * x + y;
}

int FooN() 
{
	return 13;
}

using Func = function<bool(int)>;

using FunN = function<int()>;

void TestLazy()
{
	////带参数的普通函数
	//int y = 4;
	//auto lazyer1 = lazy(FooK, y, 3.14);
	//std::cout << lazyer1.Value() << std::endl;

	////my 不带参数的普通函数
	//auto lazy1 = lazy(FooN);
	//std::cout << lazy1.Value() << std::endl;

	//不带参数的lamda
	//int mode = 8;
	//Func f1 = ([&mode](int value) {
	//	return value % mode == 0;
	//});

	//FunN f2 = ([]() {
	//	return 777;
	//} );

	//Lazy<int> lazyer2 = lazy([] {return 12; });
	//auto lazyer2 = lazy([]()->int {return 12; });
	//auto lazyer2 = lazy(f2);

	//auto lm = ([]()->int {
	//	return 888;
	//});
	//auto lazyer2 = lazy([]()->int {
	//	return 888;
	//});

	//std::cout << lazyer2.Value() << std::endl;

	////带参数的fucntion
	//std::function < int(int) > f = [](int x) {return x + 3; };
	//auto lazyer3 = lazy(f, 3);
	//std::cout << lazyer3.Value() << std::endl;

	//延迟加载大对象
	MyStruct t;
	t.Load();
}


int main(void)
{
	TestLazy();

	//system("pause");
	return 0;
}