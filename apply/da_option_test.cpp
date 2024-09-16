#include "optional.hpp"
#include "stl_header.h"

using namespace std;

struct MyStruct
{
	MyStruct() {}
	MyStruct(int a, int b) : m_a(a), m_b(b) {}
	int m_a;
	int m_b;
};

void TestOptional()
{
	Optional<std::string> a("ok");
	Optional<std::string> b("ok");
	Optional<std::string> c("aa");

	c = a;

	Optional<MyStruct> op;
	op.emplace(1, 2);
	MyStruct t;

	if (op)  //判断op是否被初始化
	{
		t = *op;
	}

	op.emplace(3, 4);
	t = *op;
}

struct Foo {
	int i;
	float f;
	char c;
};

struct Empty {

};

struct alignas(4) Empty64 { int k; char c; };

//====================================================================
//template <typename T>
//T* GetFunction(const std::string& funcName)
//{
//	HANDLE m_hMod = nullptr;
//	auto addr = GetProcAddress(m_hMod, funcName.c_str());
//	return (T*)(addr);
//}
//
//template <typename T, typename... Args>
//typename std::result_of<std::function<T>(Args...)>::type
//ExcecuteFunc(const std::string& funcName, Args&&... args)
//{
//	auto f = GetFunction<T>(funcName);
//
//	if (f == nullptr)
//	{
//		std::string s = "can not find this function " + funcName;
//		throw std::exception(s.c_str());
//	}
//
//	return f(std::forward<Args>(args)...);
//}
//
//int main(void)
//{
//
//	TestOptional();
//
//	system("pause");
//	return 0;
//}