#include <iostream>
using namespace std;


class Investment {
public:

};

class Stock : public Investment {
public:

};

class Bond : public Investment {
public:

};

class RealEstate : public Investment {
public:

};

template <typename ... Ts>
unique_ptr<Investment> makeInvestment(Ts&&... param)
{
	return nullptr;
}

//int main()
//{
//	auto spInves = makeInvestment("sf");
//	if (nullptr == spInves) {
//		cout << "sp is nullptr" << endl;
//	}
//	return 0;
//}