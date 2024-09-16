#include "stl_header.h"
using namespace std;


template <typename... Args>
void f(Args... args)
{
	cout << "args:" << sizeof...(args) << endl;
	
}

//void f()
//{
//	cout << "call f ..." << endl;
//}


template<typename T, typename ...  Args>
T* Instance(Args&& ... args)
{
	//return new T(std::forward<Args>(args)…);
	return new T(std::forward<Args>(args) ...);
}


class B {
public:
	B(int p1, float p2) {
		cout << "call b int... p1:" << p1	\
			<< " p2 "<< p2 << endl;
	}
};

template <typename T, typename ... Args>
void f(T t, Args ... args)
{
	cout << "t is:" << t << endl;
	f(args...);
}

//==========================================================
//delegate 
//==========================================================
template <class T, class R, typename... Args>
class  MyDelegate
{
public:
	MyDelegate(T* t, R(T::*f)(Args...)) :m_t(t), m_f(f) {}

	R operator()(Args&&... args)
	{
		return (m_t->*m_f)(std::forward<Args>(args) ...);
	}

private:
	T* m_t;
	R(T::*m_f)(Args...);
};

template <class T, class R, typename... Args>
MyDelegate<T, R, Args...> CreateDelegate(T* t, R(T::*f)(Args...))
{
	return MyDelegate<T, R, Args...>(t, f);
}

struct A
{
	void Fun(int i) { cout << i << endl; }
	void Fun1(int i, double j) { cout << i + j << endl; }
};

//int main()
//{
//	int&& i = 0;
//
//	return 0;
//
//	A a;
//	auto d = CreateDelegate(&a, &A::Fun); //创建委托
//	d(1); //调用委托，将输出1
//
//	auto d1 = CreateDelegate(&a, &A::Fun1); //创建委托
//	d1(1, 2.5); //调用委托，将输出3.5
//}