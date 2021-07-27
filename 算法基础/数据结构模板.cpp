//������
/*
// head�洢����ͷ��e[]�洢�ڵ��ֵ��ne[]�洢�ڵ��nextָ�룬idx��ʾ��ǰ�õ����ĸ��ڵ�
int head, e[N], ne[N], idx;

// ��ʼ��
void init()
{
    head = -1;
    idx = 0;
}

// ������ͷ����һ����a
void insert(int a)
{
    e[idx] = a, ne[idx] = head, head = idx ++ ;
   
}

// ��ͷ���ɾ������Ҫ��֤ͷ������
void remove()
{
    head = ne[head];
}
*/
//˫���� 
/*
// e[]��ʾ�ڵ��ֵ��l[]��ʾ�ڵ����ָ�룬r[]��ʾ�ڵ����ָ�룬idx��ʾ��ǰ�õ����ĸ��ڵ�
int e[N], l[N], r[N], idx;

// ��ʼ��
void init()
{
    //0����˵㣬1���Ҷ˵�
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// �ڽڵ�a���ұ߲���һ����x
void insert(int a, int x)
{
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx ++ ;
}

// ɾ���ڵ�a
void remove(int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

*/
//ջ
/*
// tt��ʾջ��
int stk[N], tt = 0;

// ��ջ������һ����
stk[ ++ tt] = x;

// ��ջ������һ����
tt -- ;

// ջ����ֵ
stk[tt];

// �ж�ջ�Ƿ�Ϊ��
if (tt > 0)
{

}
*/
//��ͨ����
/*
// hh ��ʾ��ͷ��tt��ʾ��β
int q[N], hh = 0, tt = -1;

// ���β����һ����
q[ ++ tt] = x;

// �Ӷ�ͷ����һ����
hh ++ ;

// ��ͷ��ֵ
q[hh];

// �ж϶����Ƿ�Ϊ��
if (hh <= tt)
{

}
*/
//ѭ������
/*
// hh ��ʾ��ͷ��tt��ʾ��β�ĺ�һ��λ��
int q[N], hh = 0, tt = 0;

// ���β����һ����
q[tt ++ ] = x;
if (tt == N) tt = 0;

// �Ӷ�ͷ����һ����
hh ++ ;
if (hh == N) hh = 0;

// ��ͷ��ֵ
q[hh];

// �ж϶����Ƿ�Ϊ��
if (hh != tt)
{

}

*/
//����ջ 
/*
����ģ�ͣ��ҳ�ÿ���������������ı�����/С����
int tt = 0;
for (int i = 1; i <= n; i ++ )
{
    while (tt && check(stk[tt], i)) tt -- ;
    stk[ ++ tt] = i;
}
*/
//��������
/*
����ģ�ͣ��ҳ����������е����ֵ/��Сֵ
int hh = 0, tt = -1;
for (int i = 0; i < n; i ++ )
{
    while (hh <= tt && check_out(q[hh])) hh ++ ;  // �ж϶�ͷ�Ƿ񻬳�����
    while (hh <= tt && check(q[tt], i)) tt -- ;
    q[ ++ tt] = i;
}
*/
//KMP 
/*
// s[]�ǳ��ı���p[]��ģʽ����n��s�ĳ��ȣ�m��p�ĳ���
��ģʽ����Next���飺
for (int i = 2, j = 0; i <= m; i ++ )
{
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j ++ ;
    ne[i] = j;
}

// ƥ��
for (int i = 1, j = 0; i <= n; i ++ )
{
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j ++ ;
    if (j == m)
    {
        j = ne[j];
        // ƥ��ɹ�����߼�
    }
}
*/
//Trie�� 
/*
int son[N][26], cnt[N], idx;
// 0�ŵ���Ǹ��ڵ㣬���ǿսڵ�
// son[][]�洢����ÿ���ڵ���ӽڵ�
// cnt[]�洢��ÿ���ڵ��β�ĵ�������

// ����һ���ַ���
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

// ��ѯ�ַ������ֵĴ���
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

*/
//���ز��鼯
/*
int p[N]; //�洢ÿ��������ڽڵ�

    // ����x�����ڽڵ�
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // ��ʼ�����ٶ��ڵ�����1~n
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    // �ϲ�a��b���ڵ��������ϣ�
    p[find(a)] = find(b);
*/
//ά��size�Ĳ��鼯
/*
int p[N], size[N];
    //p[]�洢ÿ��������ڽڵ�, size[]ֻ�����ڽڵ�������壬��ʾ���ڽڵ����ڼ����еĵ������

    // ����x�����ڽڵ�
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // ��ʼ�����ٶ��ڵ�����1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        size[i] = 1;
    }

    // �ϲ�a��b���ڵ��������ϣ�
    size[find(b)] += size[find(a)];
    p[find(a)] = find(b);
*/
//ά�������ڽڵ����Ĳ��鼯
/*
int p[N], d[N];
    //p[]�洢ÿ��������ڽڵ�, d[x]�洢x��p[x]�ľ���

    // ����x�����ڽڵ�
    int find(int x)
    {
        if (p[x] != x)
        {
            int u = find(p[x]);
            d[x] += d[p[x]];
            p[x] = u;
        }
        return p[x];
    }

    // ��ʼ�����ٶ��ڵ�����1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        d[i] = 0;
    }

    // �ϲ�a��b���ڵ��������ϣ�
    p[find(a)] = find(b);
    d[find(a)] = distance; // ���ݾ������⣬��ʼ��find(a)��ƫ����
*/
//��
/*
// h[N]�洢���е�ֵ, h[1]�ǶѶ���x���������2x, �Ҷ�����2x + 1
// ph[k]�洢��k������ĵ��ڶ��е�λ��
// hp[k]�洢�����±���k�ĵ��ǵڼ��������
int h[N], ph[N], hp[N], size;

// ���������㣬����ӳ���ϵ
void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

// O(n)����
for (int i = n / 2; i; i -- ) down(i);
*/
//һ���ϣ������
/*
 int h[N], e[N], ne[N], idx;

    // ���ϣ���в���һ����
    void insert(int x)
    {
        int k = (x % N + N) % N;
        e[idx] = x;
        ne[idx] = h[k];
        h[k] = idx ++ ;
    }

    // �ڹ�ϣ���в�ѯĳ�����Ƿ����
    bool find(int x)
    {
        int k = (x % N + N) % N;
        for (int i = h[k]; i != -1; i = ne[i])
            if (e[i] == x)
                return true;

        return false;
    }

*/
//��ϣ����Ѱַ��
/*
 int h[N];

    // ���x�ڹ�ϣ���У�����x���±ꣻ���x���ڹ�ϣ���У�����xӦ�ò����λ��
    int find(int x)
    {
        int t = (x % N + N) % N;
        while (h[t] != null && h[t] != x)
        {
            t ++ ;
            if (t == N) t = 0;
        }
        return t;
    }
*/
//�ַ�����ϣ 
/*
����˼�룺���ַ�������P��������P�ľ���ֵ��131��13331��ȡ������ֵ�ĳ�ͻ���ʵ�
С���ɣ�ȡģ������2^64������ֱ����unsigned long long�洢������Ľ������ȡģ�Ľ��

typedef unsigned long long ULL;
ULL h[N], p[N]; // h[k]�洢�ַ���ǰk����ĸ�Ĺ�ϣֵ, p[k]�洢 P^k mod 2^64

// ��ʼ��
p[0] = 1;
for (int i = 1; i <= n; i ++ )
{
    h[i] = h[i - 1] * P + str[i];
    p[i] = p[i - 1] * P;
}

// �����Ӵ� str[l ~ r] �Ĺ�ϣֵ
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
*/
//C++ STL���
/*
vector, �䳤���飬������˼��
    size()  ����Ԫ�ظ���
    empty()  �����Ƿ�Ϊ��
    clear()  ���
    front()/back()
    push_back()/pop_back()
    begin()/end()
    []
    ֧�ֱȽ����㣬���ֵ���

pair<int, int>
    first, ��һ��Ԫ��
    second, �ڶ���Ԫ��
    ֧�ֱȽ����㣬��firstΪ��һ�ؼ��֣���secondΪ�ڶ��ؼ��֣��ֵ���

string���ַ���
    size()/length()  �����ַ�������
    empty()
    clear()
    substr(��ʼ�±꣬(�Ӵ�����))  �����Ӵ�
    c_str()  �����ַ��������ַ��������ʼ��ַ

queue, ����
    size()
    empty()
    push()  ���β����һ��Ԫ��
    front()  ���ض�ͷԪ��
    back()  ���ض�βԪ��
    pop()  ������ͷԪ��

priority_queue, ���ȶ��У�Ĭ���Ǵ����
    size()
    empty()
    push()  ����һ��Ԫ��
    top()  ���ضѶ�Ԫ��
    pop()  �����Ѷ�Ԫ��
    �����С���ѵķ�ʽ��priority_queue<int, vector<int>, greater<int>> q;

stack, ջ
    size()
    empty()
    push()  ��ջ������һ��Ԫ��
    top()  ����ջ��Ԫ��
    pop()  ����ջ��Ԫ��

deque, ˫�˶���
    size()
    empty()
    clear()
    front()/back()
    push_back()/pop_back()
    push_front()/pop_front()
    begin()/end()
    []

set, map, multiset, multimap, ����ƽ��������������������̬ά����������
    size()
    empty()
    clear()
    begin()/end()
    ++, -- ����ǰ���ͺ�̣�ʱ�临�Ӷ� O(logn)

    set/multiset
        insert()  ����һ����
        find()  ����һ����
        count()  ����ĳһ�����ĸ���
        erase()
            (1) ������һ����x��ɾ������x   O(k + logn)
            (2) ����һ����������ɾ�����������
        lower_bound()/upper_bound()
            lower_bound(x)  ���ش��ڵ���x����С�����ĵ�����
            upper_bound(x)  ���ش���x����С�����ĵ�����
    map/multimap
        insert()  ���������һ��pair
        erase()  ����Ĳ�����pair���ߵ�����
        find()
        []  ע��multimap��֧�ִ˲����� ʱ�临�Ӷ��� O(logn)
        lower_bound()/upper_bound()

unordered_set, unordered_map, unordered_multiset, unordered_multimap, ��ϣ��
    ���������ƣ���ɾ�Ĳ��ʱ�临�Ӷ��� O(1)
    ��֧�� lower_bound()/upper_bound()�� ��������++��--

bitset, �Rλ
    bitset<10000> s;
    ~, &, |, ^
    >>, <<
    ==, !=
    []

    count()  �����ж��ٸ�1

    any()  �ж��Ƿ�������һ��1
    none()  �ж��Ƿ�ȫΪ0

    set()  ������λ�ó�1
    set(k, v)  ����kλ���v
    reset()  ������λ���0
    flip()  �ȼ���~
    flip(k) �ѵ�kλȡ��
*/



