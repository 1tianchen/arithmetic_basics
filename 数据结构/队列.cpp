/*#include<iostream>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <stdio.h>
#include<iostream>
#include<cstdio>
#include <string>
//对尾插入 对头弹出
const int N = 2e5 + 10;
int q[N], hh, tt = -1;
using namespace std;

* 插入 q[++t]=x;
* 弹出 hh++
* 是否为空 hh<=tt
* 取出 q[hh]

int main()
{
	string cmd;
	int M; cin >> M;
	int x{};
	while (M--)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> x;
			q[++tt] = x;
		}
		else if (cmd == "pop")
		{
			hh++;
		}
		else if (cmd == "empty")
		{
			if (tt >= hh)
			{
				cout << "NO" << endl;
			}
			else
			{
				cout << "YES" << endl;
			}
		}
		else if (cmd == "query")
		{
			cout << q[hh] << endl;
		}

	}
}*/