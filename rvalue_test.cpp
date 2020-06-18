#include "stl_header.h"
using namespace std;



class A
{
public:
	A() :m_ptr(new int(0)) {
		cout << "default construct" << endl;
	}
	A(const A& a) :m_ptr(new int(*a.m_ptr)) //����Ŀ������캯��
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
	std::list< A> t = std::move(tokens);  //����û�п���
	cout << "now tokens :" << tokens.size() << " t :" << t.size() << endl;
}

void processValue(int& a) { cout << "lvalue" << endl; }
void processValue(int&& a) { cout << "rvalue" << endl; }

template <typename T>
void forwardValue(T&& val)
{
	//processValue(std::forward<T>(val)); //�ղ������������ͽ���ת����
	processValue(val); //�ղ������������ͽ���ת����
}

void Testdelcl()
{
	int i = 0;
	forwardValue(i); //������ֵ 
	forwardValue(0);//������ֵ 
}


//int main() {
//	A a = Get(false);
//
//	//Testdelcl();
//
//	return 0;
//}