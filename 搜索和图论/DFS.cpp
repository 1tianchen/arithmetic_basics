//排列数字
/*#include<iostream>
using namespace std;
const int N = 10;
int path[N];
int state[N];
int n;
void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!state[i])
        {
            path[u] = i;
            state[i] = 1;
            dfs(u + 1);
            state[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
}*/
//n皇后问题 全排列搜索
/*#include<iostream>
using namespace std;
const int N = 20;
char g[N][N];
bool col[N], dg[N], udg[N];
int n;//dg 正对角线 反对角线
void dfs(int u)
{

    if (u == n)
    {
        for (int i = 0; i < n; i++)
        {
            puts(g[i]);
        }
        puts("");
        return ;
    }
    for (int i = 0; i <n; i++)
    {
        if (!col[i] && !dg[i + u] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < n; j++)
        {
            g[i][j] = '.';
        }
    }
    dfs(0);
}*/
//2
/*#include <iostream>
using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i++)
        if (!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    dfs(0);

    return 0;
}*/

//dfs不要前重复的如 3 12 7
/*
#include<iostream>
#include <string>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <stdio.h>
using namespace std;
int n, k;
int sum = 0;
const int N = 21;
long long  f[N];
long long path[N];
bool status[N];
bool isprime(long long val)
{
    if (val <= 3 || val == 5 || val == 7)return true;
    else if (!val & 1)return false;
    //val==1 return false;
    for (int i = 3; i <= pow(val, 1 / 2); i++)
    {
        if (val % i == 0)return false;
    }
    return true;

}
int last = 0;
void dfs(int len)
{
    if (len > k)
    {
        long long val = 0;
        for (int i = 1; i < len; i++)
        {
            val += path[i];
            cout << path[i] << " ";
        }
        if (isprime(val))
        {
            sum++;
        }
    }
    else
    {
        for (int i = last + 1; i <= n; i++)
        {
            if (!status[i])
            {
                path[len] = f[i];
                status[i] = true;
                last = i;
                dfs(len + 1);
                status[i] = false;
            }
        }
    }
}
int main()
{

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
    }
    dfs(1);
    cout << sum;
    return 0;
}
*/

//记忆话搜索
/*
#include<iostream>
#include <string>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <stdio.h>
using namespace std;
int t1, t2, t3;
long long f[25][25][25];
int function(long long x1, long long x2, long long x3)
{
    if (x1 <= 0 || x2 <= 0 || x3 <= 0)return 1;
    else if (x1 > 20 || x2 > 20 || x3 > 20)return function(20, 20, 20);
    else if (f[x1][x2][x3] != 0)return f[x1][x2][x3];
    else if (x1 < x2 && x2 < x3)
    {
        f[x1][x2][x3] = function(x1, x2, x3 - 1) + function(x1, x2 - 1, x3 - 1) - function(x1, x2 - 1, x3);
    }
    else
    {
        f[x1][x2][x3] = function(x1 - 1, x2, x3) + function(x1 - 1, x2 - 1, x3) + function(x1 - 1, x2, x3 - 1) - function(x1 - 1, x2 - 1, x3 - 1);
    }
    return f[x1][x2][x3];
}
int main()
{
    while(1)
    {
        cin >> t1 >> t2 >> t3;
        int temp=function(t1, t2, t3);
        if (t1 == -1 && t2 == -1 && t3 == -1)break;
        cout << "w(" << t1 << ", " << t2 << ", " << t3 << ") = " <<temp<< endl;
    }
    return 0;
}
*/