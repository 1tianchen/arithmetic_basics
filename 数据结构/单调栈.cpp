/*
#include<iostream>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <stdio.h>
#include<iostream>
#include<cstdio>
#include <string>
//对尾插入 对头弹出
using namespace std;
const int N = 100010;
int n;
int stk[N], tt;
//不会输出 a3>>a5
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		while (tt&&stk[tt]>=x)
		{//那么栈顶元素就不可能使用到
			tt--;
		}
		if (tt)
		{
			cout << stk[tt] <<" ";
		}
		else
		{
			cout << -1 <<" ";
		}
		stk[++tt] = x;
	}
}*/