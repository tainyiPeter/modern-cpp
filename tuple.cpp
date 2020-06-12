#include <iostream>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::get;
using std::tuple;
using std::vector;
using std::find_if;

using namespace std;

//int main(int, char**)
//{
//	int needle = 2;
//	vector< tuple< int, int, int > > haystack;
//
//	haystack.emplace_back(1, 2, 5);
//	haystack.emplace_back(7, 3, 1);
//
//	auto position = find_if(haystack.begin(), haystack.end(),
//		[=](auto item)
//	{
//		return get< 0 >(item) == needle;
//	});
//
//	if (position not_eq haystack.end())
//	{
//		cout << "position :"<<  get<0>(*position) << endl;
//		cout << "position :" << get<1>(*position) << endl;
//		cout << "position :" << get<2>(*position) << endl;
//		haystack.erase(position);
//	}
//
//	return EXIT_SUCCESS;
//};

