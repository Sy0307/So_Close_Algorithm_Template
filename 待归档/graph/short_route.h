// TIP: 以下实现比大多数裸实现常数要小
#pragma once
#include "../base.h"
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