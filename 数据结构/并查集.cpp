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
const int N = 1e5;
int F[N];
int W[N];
int find(int x)
{
	if (x != F[x])
	{
		return F[x] = find(F[x]);
	}
	return x;

}
int main()
{
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= n; i++)F[i] = i;
	char cmd;
	for (int i = 0; i < m; i++)
	{
		cin >> cmd;
		cin >> a >> b;
		if (cmd == 'M')
		{

			F[find(a)] = find(b);
		}
		else
		{
			if (find(a) == find(b))
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
const int N = 1e5;
int F[N];
int wsize[N];
int find(int x)
{
	if (x != F[x])
	{
		return  F[x] = find(F[x]);
	}
	return x;
}
int n,m;
int main()
{

	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= n; i++)\
	{
		F[i] = i; wsize[i] = 1;
	}
	string cmd;
	while (m--)
	{
		cin >> cmd >> a;
		if (cmd == "C")
		{
			cin >> b;
			if (a == b)continue;
			wsize[find(b)] = wsize[find(a)] + wsize[find(b)];
			F[find(a)] = find(b);
		}
		else if (cmd == "Q1")
		{
			cin >> b;
			if (find(a) == find(b))
			{
				cout << "Yes" << endl;
				continue;
			}
			cout << "No" << std::endl;
		}
		else
		{
			cout << wsize[find(a)] << std::endl;
		}
	}
}*/

// Ê³ÎïÁ´
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
const int N = 1e5;
int F[N];
int wsize[N];
int find(int x)
{
	if (x != F[x])
	{
		return  F[x] = find(F[x]);
	}
	return x;
}
int main()
{

}
*/

