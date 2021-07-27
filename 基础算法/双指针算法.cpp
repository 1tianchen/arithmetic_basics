//最长连续不重复只序列
/*#include <iostream>
using namespace std;
const int N = 100010;
int a[N];
int s[N];
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int res = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		s[a[i]]++;
		while (s[a[i] > 1])
		{
			s[a[j]]--;
			j++;
		}
		res = max(res, i - j + 1);
	}
	cout << res;

}*/

//数组元素的目标和
/*#include <iostream>
using namespace std;
const int N = 100010;
int a[N];
int b[N];
int n, m, val;
int main()	
{
	cin >> n >> m >> val;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	int sum = 0;
	for (int i = 0,j=m-1; i < n; i++)
	{
		while (j >= 0 && a[i] + b[j] > val)j--;
		if (a[i] + b[j] == val)
		{
			cout << i << " " << j;
			break;
		}

			
		
	}
}*/

//判断子序列 
/*#include <iostream>
const int N = 1e5+10;
int a[N], b[N];
int main()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)std::cin >> b[i];
	int j = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[j] == b[i])
		{
			j++;
		}
	}
	if (j == n)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "NO";
	}
}*/
