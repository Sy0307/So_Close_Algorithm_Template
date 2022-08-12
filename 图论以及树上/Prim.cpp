#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

struct node{
    int nex,w;
};
int cnt=  0; //记录连通的节点数
vector<node> g[5010];
void add(int x,int y,int w)
{
    g[x].push_back(node{y,w});
    g[y].push_back(node{x,w});
}
bool vis[5010];
int dist[5010];
int sum = 0;
int n,m;
void prim()
{
    priority_queue<pii,vector<pii>,greater<pii>> q;
    vis[1] = 0;
    q.push(make_pair(0,1));
    memset(dist,127,sizeof(dist));
    while(q.size()&&cnt<n)
    {
        auto now = q.top();
        int d = now.first;
        int u = now.second;
        q.pop();
        if(vis[u]) continue; //need to be checked
        cnt++;
        sum+=d;
        vis[u] = 1;
        for(auto &k:g[u])
        {
            if(vis[k.nex])continue;
            if(dist[k.nex]>k.w)
            {
                dist[k.nex] = k.w; 
                q.push(make_pair(dist[k.nex],k.nex));
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        add(x,y,w);
    }
    prim();
    if(cnt==n)
    {
        cout<<sum<<endl;
    }
    else cout<<"orz"<<endl;
    

    return 0;
}