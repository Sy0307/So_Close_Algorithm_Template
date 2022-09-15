#include <bits/stdc++.h>
#define maxn 2000001
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

struct Trie
{
    int son[26], flag, fail, ans;
    void clear()
    {
        memset(son, 0, sizeof(son));
        flag = fail = 0;
    }
} trie[maxn];
int n, cnt, ans;
int MAP[maxn], in[maxn];
int vis[maxn];
char s[maxn];
char T[maxn];
queue<int> q;
void insert(char *s, int num)
{
    int u = 1, len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        int v = s[i] - 'a';
        if (!trie[u].son[v])
            trie[u].son[v] = ++cnt;
        u = trie[u].son[v];
    }
    if (!trie[u].flag)
        trie[u].flag = num; // 标记单词编号
    MAP[num] = trie[u].flag;
}
void getFail()
{
    for (int i = 0; i < 26; i++)
        trie[0].son[i] = 1; //初始化0的所有儿子都是1
    q.push(1);
    trie[1].fail = 0; //将根压入队列
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {                            //遍历所有儿子
            int v = trie[u].son[i];  //处理u的i儿子的fail，这样就可以不用记父亲了
            int Fail = trie[u].fail; //就是fafail，trie[Fail].son[i]就是和v值相同的点
            if (!v)
            {
                trie[u].son[i] = trie[Fail].son[i];
                continue;
            }                                 //不存在该节点，第二种情况
            trie[v].fail = trie[Fail].son[i]; //第三种情况，直接指就可以了
            in[trie[v].fail]++;
            q.push(v); //存在实节点才压入队列
        }
    }
}
void topu()
{
    for (int i = 1; i <= cnt; ++i)
        if (in[i] == 0)
            q.push(i); //将入度为0的点全部压入队列里
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[trie[u].flag] = trie[u].ans; //如果有flag标记就更新vis数组
        int v = trie[u].fail;
        in[v]--;                    //将唯一连出去的出边fail的入度减去（拓扑排序的操作）
        trie[v].ans += trie[u].ans; //更新fail的ans值
        if (in[v] == 0)
            q.push(v); //拓扑排序常规操作
    }
}
void query(char *s)
{
    int u = 1, len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        int v = s[i] - 'a';
        u = trie[u].son[v]; //到下一个儿子
        trie[u].ans++;      //更新ans值
    }
}
void solve()
{
    cnt = 1; //代码实现细节，编号从1开始
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        insert(s, i);
    }
    getFail();
    cin >> T;
    query(T);
    topu();
    fr(i, 1, n)
    {
        cout << vis[MAP[i]] << endl;
    }
}
void clear()
{
    for (int i = 0; i <= cnt; i++)
        trie[i].clear();
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    cnt = 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while (T--)
    {
        cin >> n;
        // if (!n)
        //     return 0;
        clear();
        solve();
    }
    return 0;
}