/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e7 + 10;
int n;
int q[N];
void quick_sort(int q[], int l, int r)
{
    if (l >= r)return;
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j)swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}
int main()
{
    ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);//����ʹ��scanf
    cin >> n;
    for (int i = 0; i < n; i++)cin >> q[i];
    quick_sort(q, 0, n - 1);//��ʼ�±�ͽ����±�
    for (int i = 0; i < n; i++)cout << q[i] << " ";
    return 0;
}*/