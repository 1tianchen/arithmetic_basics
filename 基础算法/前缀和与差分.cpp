//前缀
//1
/*#include<iostream>
using namespace std;
const int N = 100010;
int n, m;
int a[N], s[N];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
	int r, l;
	while (m--)
	{
		scanf("%d%d", &l, & r);
		printf("%d\n", s[r] - s[l - 1]);
	}
}*/
//二维
/*#include<iostream>
using namespace std;
const int N = 1010;
int n, m, q;
int a[N][N], s[N][N];
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	//初始化前缀和数组
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
	while (q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
	}
}*/
//差分
//1维
/*#include<iostream>
const int N = 100010;
int a[N], b[N];
int n, m;
void insert(int l, int r, int c) {
	b[l] += c;
	b[r + 1] -= c;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)insert(i, i, a[i]);
	while (m--)
	{
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		insert(l, r, c);
	}
	for (int i = 1; i <= n; i++)b[i] += b[i - 1];
	for (int i = 1; i <= n; i++)printf("%d ", b[i]);
}*/
//二维
