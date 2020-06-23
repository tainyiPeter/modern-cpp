#include "Lazy.hpp"
#include "Any.hpp"
#include <functional>
#include <type_traits>
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

using FunI = function<int(int)>;

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

template<typename T>
class Task;

template<typename R, typename...Args>
class Task<R(Args...)>
{
public:
	Task(std::function<R(Args...)>&& f) : m_fn(std::move(f)) 
	{
		cout << "call && " << endl;
	}

	Task(std::function<R(Args...)>& f) : m_fn(f) 
	{
		cout << "call & " << endl;
	}

	template<typename... Args>
	R Run(Args&&... args)
	{
		return m_fn(std::forward<Args>(args)...);
	}

	template<typename F>
	auto Then(F& f)->Task<typename std::result_of<F(R)>::type(Args...)>
	{
		using return_type = typename std::result_of<F(R)>::type;

		auto func = std::move(m_fn);

		return Task<return_type(Args...)>([func, f](Args&&... args)
		{return f(func(std::forward<Args>(args)...)); });
	}

private:
	std::function<R(Args...)> m_fn;
};


void TestTask()
{
	Func  f = ([](int i) {
		cout << "define f " << i << endl;
		return true;
	}
	);

	Task<int(int)> task1 = FunI([](int i) { return i; });
	//auto result = task.Then([](int i) {return i + 1; }).Then([](int i) {
	//	return i + 2; }).Then([](int i) {return i + 3; }).Run(1);
	//	std::cout << result << std::endl;  // 7
}

void TestAny()
{
	Any n = 3;

	n = 4;

	
	cout << "1 is " << n.IsNull() << " type:" << n.Is<float>() << endl;
	std::string s1 = "hello";
	n = s1;
	cout << "2 is " << n.IsNull() << endl;
	//n = "world";
	//n.AnyCast<int>();  //can not cast int to string
	//Any n1 = 1;
	//n1.Is<int>(); //true

}


int any_main(void)
{
	TestAny();

	return 0;
}


int drive_main(void)
{
	TestTask();

	return 0;
}


//
//int main(void)
//{
//	//return any_main();
//
//	//TestLazy();
//	//system("pause");
//	return 0;
//}