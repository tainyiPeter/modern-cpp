#include <iostream>
#include <type_traits>
#include <memory>

using namespace std;

template <class T>
struct Construct
{
	typedef typename std::remove_reference<T>::type U;
	Construct() : m_ptr(new U) {}

	typename std::add_lvalue_reference<U>::type Get() const
	{
		*m_ptr = 565;  //特意加的一行，以防*m_ptr是个未定义的值
		return *m_ptr.get();
	}

private:
	std::unique_ptr<U> m_ptr;
};

struct MinReq
{
	__int64 km = 11;
	char name[100];

};

//int main(void)
//{
//	Construct<int> c;
//	int a = c.Get();
//
//	Construct<MinReq> mc;
//	MinReq req = mc.Get();
//
//	cout << req.km << endl;
//
//	// system("pause");
//	return 0;
//}