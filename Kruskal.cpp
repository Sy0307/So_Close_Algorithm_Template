#include<bits/stdc++.h>
using namespace std;
//并查集思想
const int N  = 1e6+2;
int fa[100010];
int ans = 0;
int n,m;
int find(int x)
{
    return x==fa[x]?x:fa[x] = find(fa[x]);
}
void merge(int x,int y)
{
    int xx = find(x);
    int yy = find(y);
    if(xx==yy) return ;
    fa[yy] = xx;
}
struct node
{
    int u,v,w;
};
int cnt = 0;// 边权数组的长度
int sum = 0;// 现在已经取得的边权
node g[N];
bool cmp (node a,node b)
{
    return a.w<b.w;
}

void add(int a,int b,int c)
{
    g[++cnt].u = a;
    g[cnt].v = b;
    g[cnt].w = c;
}
int num = 0; //树节点的个数

void Kruskal()
{
    for(int i=1;i<=cnt;i++)
    {
        int x = find(g[i].v);
        int y = find(g[i].u);
        if(x==y) continue;
        fa[x] = y;
        ans +=g[i].w;
        if(++ sum==n-1) return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fa[i] = i;
    }
    while(m--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        add(x,y,w);
        add(y,x,w);
    }
    sort(g+1,g+cnt+1,cmp);
    Kruskal();
    if(sum==n-1) cout<<ans<<endl;
    else cout<<"orz"<<endl;
    return 0;

}
