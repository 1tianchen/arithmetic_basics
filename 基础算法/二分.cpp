/*#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 1e6 + 10;
int q[N], n, m;

using namespace std;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)scanf("%d", &q[i]);

    while (m--)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = r + l >> 1;
            if (q[mid] >= x)r = mid;
            else l = mid + 1;
        }
        if (q[l] != x)printf("-1 -1\n");
        else
        {
            cout << l << " ";
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= x)l = mid;
                else r = mid - 1;
            }
            cout << r << endl;
        }
    }
    return 0;
}*/

/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{//1 2 3 4 5 6 7 8 9 10 11
    double l = -10000, r = 10000;
    double x; cin >> x;
    while (r - l > 1e-8)
    {
        double mid = (r + l) / 2;
        if (mid * mid * mid>= x)
        {
            r = mid;
        }
        else l = mid;
    }
    printf("%lf\n", l);
    return 0;
}
*/