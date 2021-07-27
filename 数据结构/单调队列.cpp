/*
#include<iostream>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <stdio.h>
#include<iostream>
#include<cstdio>
#include <string>

#include <queue>
using namespace std;
const int N = 1000010;
//在队列 里面 后面有一个元素比前面小那么前面的数就可以删除 有单调性 
int a[N], q[N];
int n,k;
int main()
{
	scanf("%d %d", &n,&k);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	int hh = 0, tt = -1;
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && q[hh] < i - k + 1)
		{
			hh++;
		}
		while (hh <= tt && a[q[tt]] >= a[i])
		{
			tt--;
		}
		q[++tt] = i;
		if (i >= k - 1)printf("%d ", a[q[hh]]);
	}
	printf("\n");
	hh = 0, tt = -1;
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && q[hh] < i - k + 1)
		{
			hh++;
		}
		while (hh <= tt && a[q[tt]] <= a[i])
		{
			tt--;
		}
		q[++tt] = i;
		if (i >= k - 1)printf("%d ", a[q[hh]]);
	}
	
}*/