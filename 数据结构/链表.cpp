//������
/*
#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node* next;
};//ÿ�ζ���Ҫnew �ǳ���

//������=>�ڽӱ� n������ �洢����ͼ
//˫����=> �Ż�һЩ����

//head ͷ���±�
//v[i] ��ʾ�ڵ��ֵ
//ne[i] ��ʾ�ڵ�i��nextָ���Ƕ���
//inx ��ǰʹ�õ��Ǹ���
const int N = 10;
int head, e[N], ne[N],idx;
void init()
{
	head = -1;
	idx = 0;//Ϊ1����ֱ�ӵĵ�
}

//���� ͷ�巨
void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx++ ;
}
//���� �±�Ϊk�ĵ�
void add(int k, int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}
//���±���k�ĵ� ����ĵ�ɾ��
void remove(int k)//�����0��ʼ ɾ�� ��k+1����
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
			if (!key)head = ne[head];//ɾ��ͷ�ڵ�
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

//˫����
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
//���±���k�ĵ���ұ� ����x  ���ֱ�� l[k]����
void add(int k, int x)
{
	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;

	l[r[k]] = idx;//��
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