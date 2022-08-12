#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int head[maxn],to[maxn],next[maxn],edge[maxn];
int cnt,n,m;
void add(int x, int y, int w) 
{     
    to[++cnt] = y; edge[cnt] = w;
    next[cnt] = head[x];   
    head[x] = cnt;       
}
 
int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        add(x, y, w);
    }
    //第一层for循环是找每一个点，依次遍历点1~n
    for (int i = 1; i <= m; i++)
    for (int k = head[i]; ~k; k = next[k]) //第二层for循环是遍历以i为起点的所有边
        cout << i << " " << to[k] << " " << edge[k] << endl;
}