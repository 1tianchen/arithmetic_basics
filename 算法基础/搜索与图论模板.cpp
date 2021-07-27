//����ͼ�Ĵ洢
/*
����һ�������ͼ����ͼ�Ĵ洢��ʽ��ͬ��
��������ͼ�еı�ab���洢���������a->b, b->a��
������ǿ���ֻ��������ͼ�Ĵ洢��

(1) �ڽӾ���g[a][b] �洢��a->b

(2) �ڽӱ�

// ����ÿ����k����һ���������洢k���п����ߵ��ĵ㡣h[k]�洢����������ͷ���
int h[N], e[N], ne[N], idx;

// ���һ����a->b
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// ��ʼ��
idx = 0;
memset(h, -1, sizeof h);
*/
//����ͼ�ı���
/*
ʱ�临�Ӷ� O(n+m)O(n+m), nn ��ʾ������mm ��ʾ����
(1) ������ȱ��� ���� ģ���� AcWing 846. ��������

int dfs(int u)
{
    st[u] = true; // st[u] ��ʾ��u�Ѿ���������

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}
(2) ������ȱ��� ���� ģ���� AcWing 847. ͼ�е�Ĳ��

queue<int> q;
st[1] = true; // ��ʾ1�ŵ��Ѿ���������
q.push(1);

while (q.size())
{
    int t = q.front();
    q.pop();

    for (int i = h[t]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true; // ��ʾ��j�Ѿ���������
            q.push(j);
        }
    }
}
*/
//�������� 
/*
ʱ�临�Ӷ� O(n+m)O(n+m), nn ��ʾ������mm ��ʾ����
bool topsort()
{
    int hh = 0, tt = -1;

    // d[i] �洢��i�����
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }

    // ������е㶼����ˣ�˵�������������У����򲻴����������С�
    return tt == n - 1;
}
*/
//����dijkstra�㷨
/*
ʱ�临���� O(n2+m)O(n2+m), nn ��ʾ������mm ��ʾ����
int g[N][N];  // �洢ÿ����
int dist[N];  // �洢1�ŵ㵽ÿ�������̾���
bool st[N];   // �洢ÿ��������·�Ƿ��Ѿ�ȷ��

// ��1�ŵ㵽n�ŵ�����·������������򷵻�-1
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i ++ )
    {
        int t = -1;     // �ڻ�δȷ�����·�ĵ��У�Ѱ�Ҿ�����С�ĵ�
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        // ��t����������ľ���
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
*/
//���Ż���dijkstra 
/*
ʱ�临�Ӷ� O(mlogn)O(mlogn), nn ��ʾ������mm ��ʾ����
typedef pair<int, int> PII;

int n;      // �������
int h[N], w[N], e[N], ne[N], idx;       // �ڽӱ�洢���б�
int dist[N];        // �洢���е㵽1�ŵ�ľ���
bool st[N];     // �洢ÿ�������̾����Ƿ���ȷ��

// ��1�ŵ㵽n�ŵ����̾��룬��������ڣ��򷵻�-1
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});      // first�洢���룬second�洢�ڵ���

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
*/
//Bellman-Ford�㷨
/*
ʱ�临�Ӷ� O(nm)O(nm), nn ��ʾ������mm ��ʾ����
ע����ģ��������Ҫ�������ģ�������޸ģ����ϱ������飬�����ģ���⡣

int n, m;       // n��ʾ������m��ʾ����
int dist[N];        // dist[x]�洢1��x�����·����

struct Edge     // �ߣ�a��ʾ���㣬b��ʾ��㣬w��ʾ�ߵ�Ȩ��
{
    int a, b, w;
}edges[M];

// ��1��n�����·���룬����޷���1�ߵ�n���򷵻�-1��
int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // �����n�ε�����Ȼ���ɳ����ǲ���ʽ����˵������һ��������n+1�����·�����ɳ���ԭ��·�������ٴ���������ͬ�ĵ㣬˵��ͼ�д��ڸ�Ȩ��·��
    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j < m; j ++ )
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if (dist[b] > dist[a] + w)
                dist[b] = dist[a] + w;
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}
*/
//spfa �㷨
/*
ʱ�临�Ӷ� ƽ������� O(m)O(m)�������� O(nm)O(nm), nn ��ʾ������mm ��ʾ����
int n;      // �ܵ���
int h[N], w[N], e[N], ne[N], idx;       // �ڽӱ�洢���б�
int dist[N];        // �洢ÿ���㵽1�ŵ����̾���
bool st[N];     // �洢ÿ�����Ƿ��ڶ�����

// ��1�ŵ㵽n�ŵ�����·���룬�����1�ŵ��޷��ߵ�n�ŵ��򷵻�-1
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])     // ����������Ѵ���j������Ҫ��j�ظ�����
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
*/
//spfa�ж�ͼ���Ƿ���ڸ��� 
/*
ʱ�临�Ӷ��� O(nm)O(nm), nn ��ʾ������mm ��ʾ����
int n;      // �ܵ���
int h[N], w[N], e[N], ne[N], idx;       // �ڽӱ�洢���б�
int dist[N], cnt[N];        // dist[x]�洢1�ŵ㵽x����̾��룬cnt[x]�洢1��x�����·�о����ĵ���
bool st[N];     // �洢ÿ�����Ƿ��ڶ�����

// ������ڸ������򷵻�true�����򷵻�false��
bool spfa()
{
    // ����Ҫ��ʼ��dist����
    // ԭ�����ĳ�����·������n���㣨�����Լ�������ô�����Լ�֮��һ����n+1���㣬�ɳ���ԭ��һ������������ͬ�����Դ��ڻ���

    queue<int> q;
    for (int i = 1; i <= n; i ++ )
    {
        q.push(i);
        st[i] = true;
    }

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;       // �����1�ŵ㵽x�����·�а�������n���㣨�������Լ�������˵�����ڻ�
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}
*/
//floyd�㷨
/*
ʱ�临�Ӷ��� O(n3)O(n3), nn ��ʾ����
��ʼ����
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

// �㷨������d[a][b]��ʾa��b����̾���
void floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
*/
//���ذ�prim�㷨
/*
ʱ�临�Ӷ��� O(n2+m)O(n2+m), nn ��ʾ������mm ��ʾ����
int n;      // n��ʾ����
int g[N][N];        // �ڽӾ��󣬴洢���б�
int dist[N];        // �洢�����㵽��ǰ��С�������ľ���
bool st[N];     // �洢ÿ�����Ƿ��Ѿ�����������


// ���ͼ����ͨ���򷵻�INF(ֵ��0x3f3f3f3f), ���򷵻���С������������Ȩ��֮��
int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}
*/
//Kruskal�㷨
/*
ʱ�临�Ӷ��� O(mlogm)O(mlogm), nn ��ʾ������mm ��ʾ����
int n, m;       // n�ǵ�����m�Ǳ���
int p[N];       // ���鼯�ĸ��ڵ�����

struct Edge     // �洢��
{
    int a, b, w;

    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[M];

int find(int x)     // ���鼯���Ĳ���
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges, edges + m);

    for (int i = 1; i <= n; i ++ ) p[i] = i;    // ��ʼ�����鼯

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b)     // ���������ͨ�鲻��ͨ������������ͨ��ϲ�
        {
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}��
*/
//Ⱦɫ���б����ͼ 
/*
ʱ�临�Ӷ��� O(n+m)O(n+m), nn ��ʾ������mm ��ʾ����
int n;      // n��ʾ����
int h[N], e[M], ne[M], idx;     // �ڽӱ�洢ͼ
int color[N];       // ��ʾÿ�������ɫ��-1��ʾδȾɫ��0��ʾ��ɫ��1��ʾ��ɫ

// ������u��ʾ��ǰ�ڵ㣬c��ʾ��ǰ�����ɫ
bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (color[j] == -1)
        {
            if (!dfs(j, !c)) return false;
        }
        else if (color[j] == c) return false;
    }

    return true;
}

bool check()
{
    memset(color, -1, sizeof color);
    bool flag = true;
    for (int i = 1; i <= n; i ++ )
        if (color[i] == -1)
            if (!dfs(i, 0))
            {
                flag = false;
                break;
            }
    return flag;
}
*/
//�������㷨
/*
ʱ�临�Ӷ��� O(nm)O(nm), nn ��ʾ������mm ��ʾ����
int n1, n2;     // n1��ʾ��һ�������еĵ�����n2��ʾ�ڶ��������еĵ���
int h[N], e[M], ne[M], idx;     // �ڽӱ�洢���бߣ��������㷨��ֻ���õ��ӵ�һ������ָ��ڶ������ϵıߣ���������ֻ�ô�һ������ı�
int match[N];       // �洢�ڶ��������е�ÿ���㵱ǰƥ��ĵ�һ�������еĵ����ĸ�
bool st[N];     // ��ʾ�ڶ��������е�ÿ�����Ƿ��Ѿ���������

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

// �����ƥ����������ö�ٵ�һ�������е�ÿ�����ܷ�ƥ��ڶ��������еĵ�
int res = 0;
for (int i = 1; i <= n1; i ++ )
{
    memset(st, false, sizeof st);
    if (find(i)) res ++ ;
}
*/