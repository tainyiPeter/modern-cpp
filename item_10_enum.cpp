#include "stl_header.h"

using namespace std;




std::vector<std::size_t> primeFactors(std::size_t x) // prime factors of x
{
	vector< std::size_t> v{ 1, 2, 3 };
	
	return v;
}

void func_10()
{
	enum Color {
		black,
		white,
		red
	};

	//enum Color { black, white, red }; // unscoped enum

	Color c = red;
	if (c < 14.5)
	{		// compare Color to double (!)
		auto factors = primeFactors(c); // of a Color (!)
	}
}


//int main()
//{
//	func_10();
//
//	return 0;
//}