#include "stl_header.h"


using namespace std;

template<class T1, class T2>
void print_is_same() {
	std::cout << std::is_same<T1, T2>::value << '\n';
}

//int main()
//{
//	using ReturnType = typename remove_reference<int&>::type&&;
//
//	print_is_same<int&&, ReturnType>();
//	return 0;
//}