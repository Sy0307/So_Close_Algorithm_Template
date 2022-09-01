#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define forall(i, a) for(auto &i : a)

namespace trie
{
    int next[maxn][26], cnt;
    bool vis[maxn], exist[maxn];
    void init()
    {
        memset(next, 0, sizeof next);
        cnt = 1;
    }
    inline void insert(const string &s)
    {
        int cur = 1;
        for (auto &c : s)
        {
            if (!next[cur][c - 'a'])
            {
                next[cur][c - 'a'] = ++cnt;
            }
            cur = next[cur][c - 'a'];
        }
        exist[cur] = true;
    }
    int find(const string &s)
    {
        int ans = -1;
        int cur = 1;
        for (auto &c : s)
        {
            if (!next[cur][c - 'a'])
            {
                return 0;
            }
            cur = next[cur][c - 'a'];
        }
        if (!exist[cur])
        {
            ans =  0;
        }
        else if (!vis[cur])
            ans =  1;
        else
            ans =  2;
        vis[cur] = true;
        return ans;
    }
}