//ģ��ջ
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
const int N = 100010;
int stk[N], tt;
//����stk[++tt]=x;
//���� tt-
//empty tt>=1
//ջtop stk[tt]

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
			stk[++tt] = x;
		}
		else if (cmd == "pop")
		{
			tt--;
		}
		else if(cmd=="query")
		{
			cout << stk[tt] << endl;
		}
		else if (cmd == "empty")
		{
			if (tt >0)
			{
				cout << "NO" << endl;
			}
			else
			{
				cout << "YES" << endl;
			}
		}
	}

}*/

//���ʽ��ֵ
/*#include<iostream>
#include <string>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <stdio.h>
#include<iostream>
#include<cstdio>
#include <unordered_map>
#include <stack>
using namespace std;

stack<int>num;
stack<char>op;
void eval()
{
	auto b = num.top(); num.pop();
	auto a = num.top(); num.pop();//������д
	auto c = op.top(); op.pop();
	int x;
	if (c == '+')x = a + b;
	else if (c == '-')x = a - b;
	else if (c == '*')x = a * b;
	else x = a / b;
	num.push(x);
}
int main()
{
	unordered_map<char, int> pr{ {'+',1},{'-',1},{'*',2},{'/',2} };//���ȼ�
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		auto c = str[i];
		if (isdigit(c))
		{
			int x{}, j = i;
			while (j < str.size() && isdigit(str[j]))
			{
				x = x * 10 + str[j++] - '0';//�����ǰ����
			}
			i = j - 1;
			num.push(x);
		}
		else if (c == '(')op.push(c);
		else if (c == ')')
		{
			while (op.top() != '(')
			{
				eval();//ĩβ������� ���� ĩβ����
			}
			op.pop();
		}
		else
		{
			while (op.size() && pr[op.top()] >= pr[c])
			{
				eval();
			}
			op.push(c);
		}
	}

	while (op.size())
	{
		eval();
	}
	cout << num.top();
}*/