#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//优化版本的树状数组（差分）
// 区间查询 和 区间修改
int n,m;
int sum1[1000010],sum2[1000010];
int  lowbit(int x)
{
    return x&(-x);
}
void add_node(int x,int val)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        sum1[i]+=val;sum2[i]+=x*val;
    }
}
void add_range(int l,int r,int val)
{
    add_node(l,val);
    add_node(r+1,-val);
}
ll query_node(int x)
{
    ll ans = 0;
    for(int i=x;i;i-=lowbit(i))
    {
        ans+=sum1[i];
      //  ans+=(x+1)*sum1[i] - sum2[i];
      //注释的是因为单点查询不需要这个
    }
    return ans;
}
ll query_range(int l,int r)
{
    return query_node(r)  - query_node(l-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int last = 0;
    for(register int i=1;i<=n;i++)
    {
        int now;
        cin>>now;
        add_node(i,now-last);
        last = now;
    }
    for(register int i=1;i<=m;i++)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            int x,y,z;
            cin>>x>>y>>z;
            add_range(x,y,z);
        }
        else
        {
            int x;
            cin>>x;
        //    cout<<query_range(x,x)<<endl;
            cout<<query_node(x)<<endl;
        }
        
    }
    return 0;
    
    
}