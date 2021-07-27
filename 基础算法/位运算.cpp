//二进制中1的个数
/*#include <iostream>
using namespace std;

n>>k&1x
lowbi(x) x&-x==x&~x+1 可以统计x中1的个数
10110
01010
------
10
int lowbi(int x)
{
	return x & -x; 求x的最后一位数
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		int res = 0;
		cin >> x;
		while (x)
		{
			x -= lowbi(x);
			res++;
		}
		cout << res<<" ";
	}
	return 0;
}*/
	