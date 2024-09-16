#include <list>
#include <iostream>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>


using namespace std;


//int main()
//{
//	list< tuple< int, string, int > >  l;
//	
//	l.push_back(make_tuple(3, "abc", 5));
//	l.push_back(make_tuple(13, "kuna", 5));
//	//l.push_back(4);
//	//l.push_back(41);
//	//l.push_back(24);
//	//l.erase(v.erase(std::remove_if(v.begin(), v.end(), [](int n) { return (n % 4) == 0; }), v.end());
//	//print(v) )
//
//	l.erase(std::remove_if(l.begin(), l.end(), 
//		[](auto item)
//	{
//		return (get<0>(item) == 123);
//	}));
//
//	auto it = find_if(l.begin(), l.end(),
//		[=](auto item)
//	{
//		return ( get<0>(item) == 13);
//	});
//
//	//auto& itr = find_if(l.begin(), l.end(),
//	//	[&](auto item)
//	//{
//	//	return (get<0>(item) == 13);
//	//});
//
//
//	if (it == l.end())
//	{
//		cout << "not find" << endl;
//		return 0;
//	}
//
//	
//
//	cout << get<1>(*it) << endl;
//	return 0;
//}