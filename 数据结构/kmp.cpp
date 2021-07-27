/*
#include<iostream>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <stdio.h>
#include<iostream>
#include<cstdio>
#include <string>


using namespace std;

const int N = 10010, M = 100010;
int n, m;
char p[N], s[M];
int ne[N];
int main()
{

	cin >> n >> p + 1 >> m >> s + 1;

	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j && p[i] != p[j + 1])
		{
			j = ne[j];
		}
		if (p[i] == p[j + 1])
		{
			j++;
		}
		ne[i] = j;
	}
	0 1 2 3 4 5 6 7 8
	* S	a b a b a b c a b
	* P a b a b a b a b
	* ne0 0 1 3 4 5 6
	
	for (int i = 0, j = 0; i <= m; i++)
	{
		while (j && s[i] != p[j + 1])
		{
			j = ne[j];
		}
		if (s[i] == p[j + 1])
		{
			j++;
		}
		if (j == n)
		{
			printf("%d ", i - n);
			j = ne[j];
		}
	}


}*/


/*
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
const int N = 200;
int ne[N];
char s[N], p[N];
int main()
{
	cin >> s + 1;
	cin>> p + 1;
	int plen = strlen(p+1);// + 1;
	int slen = strlen(s+1);
	for (int i = 2, j = 0; i <= plen; i++)
	{
		while (j && p[i] != p[j + 1])
		{
			j = ne[j];
		}
		if (p[i] == p[j + 1])
		{
			j++;
		}
		ne[i] = j;
	}
	for (int i = 0, j = 0; i <= slen; i++)
	{
		while (j && s[i] != p[j + 1])
		{
			j = ne[j];
		}
		if (s[i]==p[j + 1])
		{
			j++;
		}
		if (j == plen)
		{
			printf("%d\n", i - plen+1);
			j = ne[j];
		}
	}
	for (int i = 1; i <=plen; i++)
	{
		printf("%d ", ne[i]);
	}
}*/