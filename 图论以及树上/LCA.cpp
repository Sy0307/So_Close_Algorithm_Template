#include<bits/stdc++.h>
using namespace std;
const int N = 500010;

int lg[500010];
int papa[N];
vector<int> edge[N];
int depth[N],fa[N][23];
void dfs(int now,int father)
{
    fa[now][0] = father;
    depth[now] = depth[father]+1;
    for(int i=1;i<=lg[depth[now]];i++)
    {
        fa[now][i] = fa[fa[now][i-1]][i-1];
    }
    for(auto v:edge[now])
        if(v!=father) dfs(v,now);
}

int LCA(int x,int y)
{
    if(depth[x]<depth[y]) swap(x,y);
    while(depth[x]>depth[y])
    {
        x = fa[x][lg[depth[x]-depth[y]]-1];
    }
    if(x==y) return x;
    for(int k=lg[depth[x]]-1;k>=0;k--)
    {
        if(fa[x][k]!=fa[y][k])
        {
            x = fa[x][k];
            y = fa[y][k];
        }
    }
    return fa[x][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        lg[i] = lg[i-1]+((1<<lg[i-1])==i);
    }
    
    dfs(s,0);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
    return 0;
    
}