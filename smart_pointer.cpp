#include <iostream>

using namespace std;

static const int NameLen = 10;
struct Player {
	Player(__int16 l, const char* n)
		:level(l)
	{
		//strcpy_s(name, _countof(name), n);
		len = strlen(n)+1;
		name = new char[len];
		strcpy_s(name, len, n);
	}
	Player()
	{
		memset(this, 0, sizeof(Player));
	}

	Player(const Player& o)
	{
		level = o.level;
		len = o.len;
		name = new char[len];
		strcpy_s(name, len, o.name);
	}

	~Player()
	{
		level = 0;
		delete[]name;
	}
	__int16 level;
	int len;
	char* name;
};

typedef std::shared_ptr<Player> PlayerPtr;

//int main()
//{
//	cout << "hello " << endl;
//
//
//	//PlayerPtr spPlayer = make_shared<Player>(3, "pynb");
//	
//
//	PlayerPtr tmp;
//
//	{
//		PlayerPtr sp2 = make_shared<Player>(3, "pynb");
//		//tmp = sp2;
//	}
//
//
//	//PlayerPtr sp1 = spPlayer;
//	//sp1->level = 7;
//	//strcpy_s(sp1->name, sp1->len, "dna");
//
//	//cout << sp1->level << ":" << sp1->name << endl;
//	return 0;
//}