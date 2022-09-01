#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e7 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll ansz, ansp;
string a, b;
int z[maxn << 1];
void getz(string s)
{
    int l = 0;
    int n = s.size();
    fr(i, 1, n-1)
    {
        if (l + z[l] > i)
            z[i] = min(z[i - l], l + z[l] - i);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > l + z[l])
            l = i;
    }
    // R(i,0,sz(s)) cout<<z[i]<<" ";cout<<'\n';
}
void solve()
{
    cin >> a >> b;
    getz(b + a);
    ansz ^= 1ll * (b.size() + 1);
    fr(i, 1, b.size()-1) ansz ^= 1ll * (min(z[i], (int)(b.size()) - i) + 1) * (i + 1);
    fr(i, 0, a.size()-1)
    {
        ansp ^= 1ll * (min(z[i + b.size()], (int)b.size()) + 1) * (i + 1);
    }
    cout << ansz << "\n"
         << ansp << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}