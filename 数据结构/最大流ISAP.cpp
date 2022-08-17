// ISAP
//luogu 评测 44ms
#include <bits/stdc++.h>
using namespace std;

class ISAP
{
    long long maxflow;
    const static int MAXN = 505;    //点数
    const static int MAXM = 100010; //边数
                                    // cnt:第CNT条边head[i]:第i个点属于第几条边
                                    // n个点m条边s:源点t:汇点
    int cnt = 1, head[MAXN];
    int n, m, s, T;
    int f, e, q[MAXM];
    int t[MAXM], val[MAXM], nex[MAXM];
    int dep[MAXN], gap[MAXN], cur[MAXN]; // dep[i]表示节点i的深度，gap[i]表示深度为i的点的数量

    inline void addedge(int a, int b, int c)
    {
        t[++cnt] = b, val[cnt] = c, nex[cnt] = head[a], head[a] = cnt;
    }
    inline void bfs()
    {
        memset(dep, -1, sizeof(dep));
        memset(gap, 0, sizeof(gap));
        dep[T] = 0, gap[0] = 1;
        f = e = 1, q[1] = T;
        while (f <= e)
        {
            int u = q[f++];
            for (int p = head[u]; p; p = nex[p])
            {
                int v = t[p];
                if (dep[v] != -1)
                    continue;
                q[++e] = v;
                dep[v] = dep[u] + 1;
                gap[dep[v]]++;
            }
        }
        return;
    }
    int dfs(int u, int flow)
    {
        if (u == T)
        {
            maxflow += flow;
            return flow;
        }
        int used = 0;
        for (int p = cur[u]; p; p = nex[p])
        {
            cur[u] = p;
            int v = t[p];
            if (val[p] && dep[v] + 1 == dep[u])
            {
                int mi = dfs(v, min(flow - used, val[p]));
                if (mi)
                {
                    val[p] -= mi;
                    val[p ^ 1] += mi;
                    used += mi;
                }
                if (used == flow)
                    return used;
            }
        }
        if (--gap[dep[u]] == 0)
            dep[s] = n + 1;
        dep[u]++;
        gap[dep[u]]++;
        return used;
    }
    //如果已经到了这里，说明该点出去的所有点都已经流过了
    //并且从前面点传过来的流量还有剩余
    //则此时，要对该点更改dep
    //使得该点与该点出去的点分隔开

public:
    void init()
    {
        cin >> n;
        cin >> m;
        cin >> s;
        cin >> T;
        int u, v, w;
        for (int i = 1; i <= m; i++)
        {
            cin >> u;
            cin >> v;
            cin >> w;
            addedge(u, v, w); //正向边
            addedge(v, u, 0); //反向边
        }
    }
    long long solve()
    {
        maxflow = 0;
        bfs();
        while (dep[s] < n)
            memcpy(cur, head, sizeof(head)), dfs(s, INT_MAX); //每走一遍增广路,s的层数会加1,如果一直没有出现断层,最多跑n-dep(刚bfs完时s的深度)条增广路共有n个点
        return maxflow;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    //    cout<<"SUC"<<endl;
    ISAP isap;
    isap.init();
    cout<<isap.solve()<<endl;
    return 0;
}