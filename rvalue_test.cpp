#include "stl_header.h"
using namespace std;



class A
{
public:
	A() :m_ptr(new int(0)) {
		cout << "default construct" << endl;
	}
	A(const A& a) :m_ptr(new int(*a.m_ptr)) //深拷贝的拷贝构造函数
	{
		cout << "copy construct" << endl;
	}

	A(A&& a) :m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
		cout << "move construct" << endl;
	}

	~A() { 
		cout << "call destroy A()" << endl;
		delete m_ptr; 
	}
private:
	int* m_ptr;
};

const A Get(bool b)
{
	const A ret;
	return ret;
}

void test_move() {
	A a1; A a2; A a3;
	const std::list< A> tokens{ a1, a2, a3 };
	//tokens.push_back(a1);
	//tokens.push_back(a2);
	//tokens.push_back(a3);
	std::list< A> t = std::move(tokens);  //这里没有拷贝
	cout << "now tokens :" << tokens.size() << " t :" << t.size() << endl;
}

void processValue(int& a) { cout << "lvalue" << endl; }
void processValue(int&& a) { cout << "rvalue" << endl; }

template <typename T>
void forwardValue(T&& val)
{
	//processValue(std::forward<T>(val)); //照参数本来的类型进行转发。
	processValue(val); //照参数本来的类型进行转发。
}

void Testdelcl()
{
	int i = 0;
	forwardValue(i); //传入左值 
	forwardValue(0);//传入右值 
}


//int main() {
//	A a = Get(false);
//
//	//Testdelcl();
//
//	return 0;
//}