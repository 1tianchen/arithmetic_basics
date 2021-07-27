

//快速的存储和查找字符串集合的数据结构
/* 字典树
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
const int  N = 10010;
int son[N][26],cnt[N],idx;//cnt是用这个结尾的有多少个  idx 0即是根节点是空节点
char str[N];
void insert(char str[])
{
	int p = 0;
	for (int i = 0; i < str[i]; i++)
	{
		int u = str[i] - 'a';//0~25
		if (!son[p][u])son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;
}
int query(char str[])
{
	int p{};
	for (int i = 0; i < str[i]; i++)
	{
		int u = str[i] - '0';
		if (!son[p][u])return 0;
		p = son[p][u];
	}
	return cnt[p];
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		char op[2];
		scanf("%s%s", op,str);
		if (op[0] == 'I')
		{
			insert(str);
		}
		else
		{
			printf("%d", query(str));
		}
	}

}*/


/*
int T, n;
const int N = 100010,M = 30000000;;
int a[N];
int son[M][2];
int idx;
void insert(int x)
{
	int p = 0;
	for (int i = 30; ~i; i--)
	{
		int& s = son[p][x >> i & 1];//引用
		if (!s)s = ++idx;
		p = s;
	}
}
//i>=0 ~i ~-1=0
int query(int x)
{
	int res = 0, p = 0;
	for (int i = 30; ~i; i--)
	{
		int s = x >> i & 1;
		if (son[p][!s])
		{
			res += 1 << i;
			p = son[p][!s];
		}
		else
		{
			p = son[p][s];
		}
	}
	return res;
}
int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		insert(a[i]);
	}
	int res = 0;

	for (int i = 0; i < n; i++)
	{
		res = max(res, query(a[i]));
	}
	cout << res;
}*/