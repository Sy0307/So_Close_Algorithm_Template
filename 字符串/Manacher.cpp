#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 51000100;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

char s[maxn], a[maxn];
int n;
int d[maxn];

void init()
{
    s[0] = '!';
    s[1] = '#';
    fr(i, 1, n)
    {
        s[i * 2] = a[i - 1];
        s[i * 2 + 1] = '#';
    }
    n = n * 2 + 1;
}
void manacher()
{
    int maxr = 0, mid = 0;
    d[1] = 1;
    fr(i, 1, n)
    {
        if (i <= maxr)
        {
            d[i] = min(d[(mid << 1) - i], maxr-i + 1);
        }
        while (s[i + d[i]] == s[i - d[i]])
        {
            d[i]++;
        }
        if (d[i] + i > maxr)
        {
            maxr = d[i] + i - 1;
            mid = i;
        }
    }
}
void solve()
{
    cin >> (a);
    n = strlen(a);
    init();
    manacher();
    int ans = 0;
 //   cout << s << endl;
    fr(i, 1, n)
    {
        ans = max(ans, d[i]);
    }
    cout << ans-1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}