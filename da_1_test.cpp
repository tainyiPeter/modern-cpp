#include <iostream>
#include <functional>

using namespace std;

using std::placeholders::_1;

class A
{
public:
    int i_ = 0;

    void output(int x, int y)
    {
        std::cout << x << " " << y << std::endl;
    }



};



enum {
    IL_QuickSale = 1 << 9,           //�����ź�,����
    IL_PullUp = 1 << 10,              //�����ź�,����
    IL_StarB = 1 << 11,               //�����ź�,����B
    IL_StarS = 1 << 12,               //�����ź�,����S

};

int main(void)
{
    int cnt = 10;
    for (int i = 0 ; i < cnt; i ++)
    {
        int r = rand();

        int k1 = r + 256;
        int k2 = r << 4;

        cout << k1 << "  " << k2 << endl;
    }

    return 0;
}