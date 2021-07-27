//单链表
/*
#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node* next;
};//每次都需要new 非常慢

//单链表=>邻接表 n个链表 存储树和图
//双链表=> 优化一些问题

//head 头的下标
//v[i] 表示节点的值
//ne[i] 表示节点i的next指针是多少
//inx 当前使用到那个点
const int N = 10;
int head, e[N], ne[N],idx;
void init()
{
	head = -1;
	idx = 0;//为1就是直接的点
}

//插入 头插法
void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx++ ;
}
//插入 下标为k的点
void add(int k, int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}
//将下标是k的点 后面的点删除
void remove(int k)//如果从0开始 删除 第k+1个点
{

	ne[k] = ne[ne[k]];

}
int main()
{

	init();
	int M; cin >> M;
	while(M--)
	{
		char cmd;
		cin >>cmd;
		int key=0,x=0;
		if (cmd == 'H')
		{
			cin >> x;
			add_to_head(x);
		}
		else if(cmd=='D')
		{
			cin >> key;
			if (!key)head = ne[head];//删除头节点
			remove(key-1);
		}
		else
		{
			cin >> key >> x;
			add(key-1, x);
		}
	}
	for (int i = head; i != -1; i = ne[i])cout << e[i] << " ";

}*/

//双链表
/*
#include<iostream>
#include <string>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <stdio.h>
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 20;
int m;
int e[N], l[N], r[N], idx;
void Init()
{
	r[0] = 1;
	l[0] = -1;
	r[1] = -1;
	l[1] = 0;
	idx = 2;
}
//在下标是k的点的右边 插入x  左边直接 l[k]插入
void add(int k, int x)
{
	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;

	l[r[k]] = idx;//先
	r[k] = idx;
	idx++;
}
void remove(int k)
{
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}
int main()
{
	Init();
	int M; cin >> M;
	string cmd;
	int k{}, x{};
	for (int i = 1; i <= M; i++)
	{
		cin >> cmd;
		if (cmd == "R")
		{
			cin >> x;
			add(l[1], x);
		}
		else if(cmd=="L")
		{
			cin >> x;
			add(0, x);
		}
		else if (cmd == "D")
		{
			cin >> k;
			remove(k+1);
		}
		else if (cmd == "IL")
		{
			cin >> k >> x;
			add(l[k+1], x);
		}
		else if(cmd=="IR")
		{
			cin >> k >> x;
			add(k+1, x);
		}
	}
	for (int i = r[0];; i = r[i])
	{
		if (i == 1)break;
		cout << e[i]<<" ";
	}
	return 0;
}
*/