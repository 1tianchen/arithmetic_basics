//��������1�ĸ���
/*#include <iostream>
using namespace std;

n>>k&1x
lowbi(x) x&-x==x&~x+1 ����ͳ��x��1�ĸ���
10110
01010
------
10
int lowbi(int x)
{
	return x & -x; ��x�����һλ��
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
	