// TIP: 以下实现比大多数裸实现常数要小
// 目前仅包含 Dijkstra 和SPFA 算法 
#pragma once
#pragma once
#include <bits/stdc++.h>
#define sf(T) sizeof(T)
#define inl inline
#define stc static
#define con const
#define cer constexpr
#define ret return
#define whi(c) while(c)
using namespace std;
using is = int;
using il = long long;
using us = unsigned int;
using ul = unsigned long long;
using fs = float;
using fl = double;
#define ix __int128
using fx = long double;
cer ul ULINF = UINT64_MAX, LINF = 0x3f3f3f3f3f3f3f3f;
cer us USINF = UINT32_MAX, SINF = 0x3f3f3f3f;
con string ANS[2] = {"NO", "YES"};
extern con ul MOD;
extern con us MAX;
template<class T>
inl void mem(T *arr, us b, us n) { memset(arr, b, n * sf(T)); }
// 使用CFS<MAXN, MAXE, EI>::E的w做边权

template<class G, class T> // G=CFS<MAXN, MAXE, EI> 为了简略使用模板
inl void dij(G &g, us s, bool *vis, T *dis) {
    mem(dis, 0xff, g.n);
    mem(vis, 0, g.n);
    using pdu = pair<T, us>;
    priority_queue<pdu, vector<pdu>, greater<pdu>> que;
    que.push({dis[s] = 0, s}); T ds; typename G::E *ei;
    for(us u, v; !que.empty();) {
        u = que.top().second; que.pop();
        if(vis[u]) continue; vis[u] = 1;
        for(us e = g.hd[u]; ~e; g.next(e))
            if(ei = &g[e], (ds = dis[u] + ei->w) < dis[v = ei->v])
                que.push({dis[v] = ds, v});
    }
}

// 慎用，随机数据下良好，但是会被菊花图卡
template<class G, class T>
inl void spfa(G &g, us s, bool *vis, T *dis) {
    mem(dis, 0xff, g.n); dis[s] = 0;
    mem(vis, 0, g.n); vis[s] = 1;
    queue<us> que; que.push(s);
    T ds; typename G::E *ei;
    for(us u, v; !que.empty();) {
        u = que.front(); que.pop(); vis[u] = 0;
        for(us e = g.hd[u]; ~e; g.next(e))
            if(ei = &g[e], (ds = dis[u] + ei->w) < dis[v = ei->v])
                if(dis[v] = ds, !vis[v]) que.push(v), vis[v] = 1;
    }
}