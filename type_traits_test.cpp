#include "stl_header.h"

#include <type_traits> // std::is_same

using namespace std;

template<class T1, class T2>
void print_is_same() {
	std::cout << std::is_same<T1, T2>() << '\n';
}

//int main()
//{
//	using ReturnType = typename remove_reference<int&>::type&&;
//
//	print_is_same<int&&, ReturnType>();
//	return 0;
//}