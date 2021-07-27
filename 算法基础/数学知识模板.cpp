//�Գ����ж�����
/*
bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}
*/
//�Գ����ֽ������� 
/*
void divide(int x)
{
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;
            cout << i << ' ' << s << endl;
        }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}
*/
//����ɸ��������
/*
int primes[N], cnt;     // primes[]�洢��������
bool st[N];         // st[x]�洢x�Ƿ�ɸ��

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}
*/
//����ɸ��������
/*
int primes[N], cnt;     // primes[]�洢��������
bool st[N];         // st[x]�洢x�Ƿ�ɸ��

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
*/
//�Գ���������Լ��
/*
vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end());
    return res;
}
*/
//Լ��������Լ��֮��
/*
��� N = p1^c1 * p2^c2 * ... *pk^ck
Լ�������� (c1 + 1) * (c2 + 1) * ... * (ck + 1)
Լ��֮�ͣ� (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
*/
//ŷ������㷨
/*
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

*/
//ŷ������ 
/*
int phi(int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);

    return res;
}
*/
//ɸ����ŷ������
/*
int primes[N], cnt;     // primes[]�洢��������
int euler[N];           // �洢ÿ������ŷ������
bool st[N];         // st[x]�洢x�Ƿ�ɸ��


void get_eulers(int n)
{
    euler[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            primes[cnt ++ ] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0)
            {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}
*/
//������
/*
�� m^k mod p��ʱ�临�Ӷ� O(logk)��

int qmi(int m, int k, int p)
{
    int res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}
*/
//��չŷ������㷨
/*
// ��x, y��ʹ��ax + by = gcd(a, b)
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;
    return d;
}

*/
//��˹��Ԫ
/*
// a[N][N]���������
int gauss()
{
    int c, r;
    for (c = 0, r = 0; c < n; c ++ )
    {
        int t = r;
        for (int i = r; i < n; i ++ )   // �ҵ�����ֵ������
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps) continue;

        for (int i = c; i <= n; i ++ ) swap(a[t][i], a[r][i]);      // ������ֵ�����л������
        for (int i = n; i >= c; i -- ) a[r][i] /= a[r][c];      // ����ǰ�е���λ���1
        for (int i = r + 1; i < n; i ++ )       // �õ�ǰ�н��������е�������0
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j -- )
                    a[i][j] -= a[r][j] * a[i][c];

        r ++ ;
    }

    if (r < n)
    {
        for (int i = r; i < n; i ++ )
            if (fabs(a[i][n]) > eps)
                return 2; // �޽�
        return 1; // ����������
    }

    for (int i = n - 1; i >= 0; i -- )
        for (int j = i + 1; j < n; j ++ )
            a[i][n] -= a[i][j] * a[j][n];

    return 0; // ��Ψһ��
}
*/
//�ݹ鷨�������
/*
// c[a][b] ��ʾ��a��ƻ����ѡb���ķ�����
for (int i = 0; i < N; i ++ )
    for (int j = 0; j <= i; j ++ )
        if (!j) c[i][j] = 1;
        else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
*/
//ͨ��Ԥ������Ԫ�ķ�ʽ�������
/*
����Ԥ��������н׳�ȡģ������fact[N]���Լ����н׳�ȡģ����Ԫinfact[N]
���ȡģ�����������������÷���С��������Ԫ
int qmi(int a, int k, int p)    // ������ģ��
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

// Ԥ����׳˵������ͽ׳���Ԫ������
fact[0] = infact[0] = 1;
for (int i = 1; i < N; i ++ )
{
    fact[i] = (LL)fact[i - 1] * i % mod;
    infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
}
*/
//Lucas����
/*
��p��������������������� 1 <= m <= n���У�
    C(n, m) = C(n % p, m % p) * C(n / p, m / p) (mod p)

int qmi(int a, int k, int p)  // ������ģ��
{
    int res = 1 % p;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int C(int a, int b, int p)  // ͨ�������������C(a, b)
{
    if (a < b) return 0;

    LL x = 1, y = 1;  // x�Ƿ��ӣ�y�Ƿ�ĸ
    for (int i = a, j = 1; j <= b; i --, j ++ )
    {
        x = (LL)x * i % p;
        y = (LL) y * j % p;
    }

    return x * (LL)qmi(y, p - 2, p) % p;
}

int lucas(LL a, LL b, int p)
{
    if (a < p && b < p) return C(a, b, p);
    return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
*/
//�ֽ���������������� 
/*
��������Ҫ������������ʵֵ�����Ƕ�ĳ����������ʱ���ֽ��������ķ�ʽ�ȽϺ��ã�
    1. ɸ�������Χ�ڵ���������
    2. ͨ�� C(a, b) = a! / b! / (a - b)! �����ʽ���ÿ�������ӵĴ����� n! ��p�Ĵ����� n / p + n / p^2 + n / p^3 + ...
    3. �ø߾��ȳ˷����������������

int primes[N], cnt;     // �洢��������
int sum[N];     // �洢ÿ�������Ĵ���
bool st[N];     // �洢ÿ�����Ƿ��ѱ�ɸ��


void get_primes(int n)      // ����ɸ��������
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}


int get(int n, int p)       // ��n���еĴ���
{
    int res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}


vector<int> mul(vector<int> a, int b)       // �߾��ȳ˵;���ģ��
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }

    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }

    return c;
}

get_primes(a);  // Ԥ����Χ�ڵ���������

for (int i = 0; i < cnt; i ++ )     // ��ÿ���������Ĵ���
{
    int p = primes[i];
    sum[i] = get(a, p) - get(b, p) - get(a - b, p);
}

vector<int> res;
res.push_back(1);

for (int i = 0; i < cnt; i ++ )     // �ø߾��ȳ˷����������������
    for (int j = 0; j < sum[i]; j ++ )
        res = mul(res, primes[i]);
*/
//��������
/*
����n��0��n��1�����ǰ���ĳ��˳���ųɳ���Ϊ2n�����У���������ǰ׺��0�ĸ�����������1�ĸ��������е�����Ϊ�� 
Cat(n) = C(2n, n) / (n + 1)

*/
//NIM��Ϸ
/*
����N����Ʒ����i����Ʒ��Ai����������������ж���ÿ�ο�����ѡһ�ѣ�ȡ����������Ʒ���ɰ�һ��ȡ�⣬�����ܲ�ȡ��ȡ�����һ����Ʒ�߻�ʤ�����˶���ȡ���Ų��ԣ��������Ƿ��ʤ��

���ǰ�������Ϸ��ΪNIM���ġ�����Ϸ���������ٵ�״̬��Ϊ���档������Ϸ��һ���ж��ĳ�Ϊ���֣��ڶ����ж��ĳ�Ϊ���֡�����ĳһ���������۲�ȡ�����ж������������Ϸ����Ƹþ���ذܡ�
��ν��ȡ���Ų�����ָ������ĳһ�����´���ĳ���ж���ʹ���ж���������ٱذܾ��棬�����Ȳ�ȡ���ж���ͬʱ�������ľ��汻��Ϊ��ʤ���������۵Ĳ�������һ�㶼ֻ������������������˾���ʧ�󣬶���ȡ���Ų����ж�ʱ��Ϸ�Ľ����
NIM���Ĳ�����ƽ�֣�ֻ�����ֱ�ʤ�����ֱذ����������

���� NIM�������ֱ�ʤ�����ҽ��� A1 ^ A2 ^ �� ^ An != 0
*/
//��ƽ�����ϷICG
/*
��һ����Ϸ���㣺
��������ҽ����ж���
����Ϸ���̵�����ʱ�̣�����ִ�еĺϷ��ж����ֵ���������޹أ�
�����ж�������и���
��Ƹ���ϷΪһ����ƽ�����Ϸ��
NIM�������ڹ�ƽ�����Ϸ�����ǽ���������Ϸ������Χ�壬�Ͳ��ǹ�ƽ�����Ϸ����ΪΧ�彻ս˫���ֱ�ֻ������ӺͰ��ӣ�ʤ���ж�Ҳ�Ƚϸ��ӣ�����������2������3��
*/
//����ͼ��Ϸ
/*
����һ�������޻�ͼ��ͼ����һ��Ψһ����㣬������Ϸ���һö���ӡ�������ҽ���ذ���ö����������߽����ƶ���ÿ�ο����ƶ�һ�����޷��ƶ����и�������Ϸ����Ϊ����ͼ��Ϸ��
�κ�һ����ƽ�����Ϸ������ת��Ϊ����ͼ��Ϸ�����巽���ǣ���ÿ�����濴��ͼ�е�һ���ڵ㣬���Ҵ�ÿ�����������źϷ��ж��ܹ��������һ������������ߡ�
*/
//Mex����
/*
��S��ʾһ���Ǹ��������ϡ�����mex(S)Ϊ��������ڼ���S����С�Ǹ����������㣬����
mex(S) = min{x}, x������Ȼ������x������S
*/
//SG����
/*
������ͼ��Ϸ�У�����ÿ���ڵ�x�����x��������k������ߣ��ֱ𵽴�ڵ�y1, y2, ��, yk������SG(x)Ϊx�ĺ�̽ڵ�y1, y2, ��, yk ��SG����ֵ���ɵļ�����ִ��mex(S)����Ľ��������
SG(x) = mex({SG(y1), SG(y2), ��, SG(yk)})
�ر�أ���������ͼ��ϷG��SG����ֵ������Ϊ����ͼ��Ϸ���s��SG����ֵ����SG(G) = SG(s)��
*/
//����ͼ��Ϸ�ĺ� 
/*
��G1, G2, ��, Gm ��m������ͼ��Ϸ����������ͼ��ϷG�������ж���������ѡĳ������ͼ��ϷGi������Gi���ж�һ����G����Ϊ����ͼ��ϷG1, G2, ��, Gm�ĺ͡�
����ͼ��Ϸ�ĺ͵�SG����ֵ�����������ĸ�������ϷSG����ֵ�����ͣ�����
SG(G) = SG(G1) ^ SG(G2) ^ �� ^ SG(Gm)
*/
//����
/*
����ͼ��Ϸ��ĳ�������ʤ�����ҽ����þ����Ӧ�ڵ��SG����ֵ����0��
����ͼ��Ϸ��ĳ������ذܣ����ҽ����þ����Ӧ�ڵ��SG����ֵ����0
*/