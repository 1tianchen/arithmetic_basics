/*模拟散列表
#include<iostream>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <stdio.h>
#include<iostream>
#include<cstdio>
#include <string>
#include <iostream>

using namespace std;
/*
const int N = 200003;
int h[N];
int e[N], ne[N], idx;
void insert(int x)
{
	int k = (x % N + N) % N;
	e[idx] = x;//OK
	
	ne[idx] = h[k];///OK
	
	h[k] = idx++;//OK
}
bool find(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i!=-1; i=ne[i])
	{
		if (e[i] == x)
		{
			return true;
		}
	}
	return false;
}


const int N = 200003;
const int null = 0x3f3f3f3f;
int h[N];
int find(int x)
{
	int k = (x % N + N) % N;
	while (h[k]!=null&&h[k]!=x)
	{
		k++;
		if (k == N)k = 0;
	}
	return k;
}

int main()		
{
	int n;
	scanf("%d", &n);
	memset(h, 0x3f, sizeof h);
	while (n--)
	{
		char op[2];
		int x;
		scanf("%s%d", op, &x);
		int k = find(x);
		if (*op == 'I')
		{
			
			h[k] = x;
		}
		else
		{
			if (h[k]!=null)
			{
				cout << "Yes" << std::endl;
			}
			else
			{
				cout << "No" << std::endl;
			}

		}
	}


	/*
	int n;
	scanf("%d", &n);
	memset(h, -1, sizeof h);
	while (n--)
	{
		char op[2];
		int x;
		scanf("%s%d", op, &x);
		if (*op == 'I')insert(x);
		else
		{
			if (find(x))
			{
				cout << "Yes" << std::endl;
			}
			else
			{
				cout << "No" << std::endl;
			}

		}
	}
	


}*/


//字符串哈希
/*
#include<iostream>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <stdio.h>

#include<iostream>
#include<cstdio>
#include <string>
#include <iostream>
using namespace std;
//=131 13331 Q=2^64  可能不会重新冲突
const int N = 100010,P=131;
typedef unsigned long long ULL;
int n, m;
char str[N];
ULL h[N], p[N];
ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];//区间和公式
}
int main()
{
	scanf("%d%d%s", &n, &m, str + 1);
	p[0] = 1;
	for (int i = 1; i <=n; i++)
	{
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + str[i];//前缀和公式
	}

	while (m--)
	{
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if (get(l1, r1) == get(l2, r2))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}*/