#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1000005;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int fa[maxn][22];
int n,m,dep[maxn];
char s[maxn];
void solve()
{
    cin>>(s+1);
    n = strlen(s+1);
    fa[0][0]= fa[1][0] = 0;
    dep[1] = 1;
    for(int i = 2 , j = 0;i<=n;i++)
    {
        while(j!=0&&s[j+1]!=s[i])
        {
            j = fa[j][0];
        }
        if(s[j+1]==s[i])
            j++;
        fa[i][0] = j,dep[i] = dep[j]+1;
    }   
    //kmp 
    fr(i,1,21)
    {
        fr(j,1,n)
        {
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(dep[x]<dep[y]) swap(x,y);
        ford(i,21,0)
        {
            if(dep[fa[x][i]]>=dep[y])
            {
                x = fa[x][i];
            }    
        }
        ford(i,21,0)
        if(fa[x][i]!=fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
        cout<<fa[x][0]<<endl;
    }
    



    //LCA

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}