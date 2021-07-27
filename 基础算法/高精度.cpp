//高精度加
/*#include <iostream>
#include <cstring>
#include <algorithm>
#include  <vector>
using namespace std;
vector<int> add(vector<int>& A, vector<int>& B)  // C = A + B, A >= 0, B >= 0
{
    vector<int>C;
    if (A.size() < B.size())return add(B, A);
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        t = t + A[i];
        if (i < B.size())t = t + B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)C.push_back(1);//因为二个数加起来不可能大于20
    return C;
}
int main()
{
    string a, b;
    cin >> a >> b;
    vector<int>A, B;
    for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--)printf("%d", C[i]);
}*/

//高精度减
/*#include <iostream>
#include <cstring>
#include <algorithm>
#include  <vector>
using namespace std;
bool cmp(vector<int>& A, vector<int>& B)
{
    if (A.size() != B.size())return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}
vector<int> sub(vector<int>& A, vector<int>& B)  // C = A + B, A >= 0, B >= 0
{
    vector<int>C;
    for (int i = 0, t = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size())t = t - B[i];
        C.push_back((t + 10) % 10);
        if (t < 0)t = 1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0)C.pop_back();
    return C;
}
int main()
{
    string a, b;
    cin >> a >> b;
    vector<int>A, B;
    for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
    if (cmp(A, B))
    {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--)printf("%d", C[i]);
    }
    else
    {
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i--)printf("%d", C[i]);
    }
}*/

//高精度乘
/*#include <iostream>
#include <cstring>
#include <algorithm>
#include  <vector>
using namespace std;
vector<int>mul(vector<int>A, long long  b)
{
    vector<int>C;
    long long t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())t += A[i] * b;
        C.push_back(t % 10);
        t = t / 10;
    }
    while (C.size() > 1 && C.back() == 0)C.pop_back();
    return C;
}
int main()
{
    string a; long long B;
    cin >> a >> B;
    vector<int>A;
    for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
    auto C = mul(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
    {
        cout << C[i];
    }
    return 0;
}*/

//高精度除法
/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include  <vector>
using namespace std;
vector<int>div(vector<int>& A, long long  b, long long& r)
{   
    vector<int>C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {//A 987654321
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0)C.pop_back();
    return C;
}    

int main()
{//123456789
    string a; long long B;
    cin >> a >> B;
    vector<int>A;
    for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
    long long r;
     auto C = div(A, B,r);
    for (int i = C.size() - 1; i >= 0; i--)
    {
        cout << C[i];
    }
    //cout << endl << r << endl;
    return 0;
}*/
