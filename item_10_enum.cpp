#include "stl_header.h"

using namespace std;


struct Player {
	int			cMarket;		// 市场信息
	char 		szCode[16];		// 股票代码

	Player()
	{
		memset(this, 0, sizeof(Player));
	}

	Player(int c, const char* sz)
		: cMarket(c)
	{
		memcpy(szCode, sz, sizeof(szCode));
	}

	bool operator  < (const Player& r) const
	{
		if (this->cMarket < r.cMarket) return true;
		else if (this->cMarket > r.cMarket) return false;
		else
		{
			int ret = strcmp(szCode, r.szCode);

			if (ret >= 0) 	return true;
			else	return false;
		}
	}
};



void map_test()
{
	map<int, string> ms;
	ms.insert(make_pair(1, "huzhongsan"));
	int i = 2;
	while (i--)
	{
		//map<int, string>::iterator it = ms.find(i);//在这里，当i的值为0时，没有找到，会返回ms.end()
		//if (ms.end() == it)
		//	int k = 0;
		//else
		//	int k = 11;
		//ms.erase(it);//如果it为ms.end() ,在这里就会出现意外，在这里会阻塞，阻的死死的，程序就会停在这里。

		map<int, string>::iterator it = ms.end();
		ms.erase(it);
	}
	return;

}

using PlayerMapType = map< Player, __int64>;
int main()
{


	PlayerMapType m;
	Player pid_0(10, "zhang");
	Player pid_1(10, "zhang");
	Player pid_2(10, "zsahang");

	m[pid_0] = 77;
	m[pid_1] = 99;
	m[pid_2] = 955;

	cout << "cnt:" << m.size() << endl;

	Player pd(10, "zhang2");

	//PlayerMapType::iterator it = m.find(pd);
	m.erase(pd);
	//m.erase(it);
	cout << "after cnt:" << m.size() << endl;

	return 0;
}


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
