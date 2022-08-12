#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// this supports plus and multiply
int a[1000010];

struct node
{
    ll x, y, l, r, mul, sum,add;
} t[1000010];

int n, m, mod;

void build(ll p, ll l, ll r)
{
    t[p].l = l;
    t[p].r = r;
    t[p].mul = 1;
    if (l == r)
    {
        t[p].sum = a[l] % mod;
        return;
    }
    ll mid = (l + r) >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
}

void spread(ll p)
{
    t[p * 2].sum = (ll)(t[p].mul * t[p * 2].sum + ((t[p * 2].r - t[p * 2].l + 1) * t[p].add) % mod) % mod;
    t[p * 2 + 1].sum = (ll)(t[p].mul * t[p * 2 + 1].sum + ((t[p * 2 + 1].r - t[p * 2 + 1].l + 1) * t[p].add) % mod) % mod;

    t[p * 2].mul = (ll)(t[p * 2].mul * t[p].mul) % mod;
    t[p * 2 + 1].mul = (ll)(t[p * 2 + 1].mul * t[p].mul) % mod;

    t[p * 2].add = (ll)(t[p * 2].add * t[p].mul + t[p].add) % mod;
    t[p * 2 + 1].add = (ll)(t[p * 2 + 1].add * t[p].mul + t[p].add) % mod;

    t[p].mul = 1;
    t[p].add = 0;
}

void add(ll p, ll l, ll r, ll k)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        t[p].add = (t[p].add + k) % mod;
        t[p].sum = (ll)(t[p].sum + k * (t[p].r - t[p].l + 1)) % mod;

        return;
    }
    spread(p);
    t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
    ll mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
        add(p * 2, l, r, k);
    if (r > mid)
        add(p * 2 + 1, l, r, k);
    t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
}
void mul(ll p, ll l, ll r, ll k)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        t[p].add = (t[p].add * k) % mod;
        t[p].mul = (t[p].mul * k) % mod;
        t[p].sum = (ll)(t[p].sum * k) % mod;
        return;
    }

    spread(p);
    t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
    ll mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
        mul(p * 2, l, r, k);
    if (r > mid)
        mul(p * 2 + 1, l, r, k);
    t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
}

ll ask(ll p, ll l, ll r)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        return t[p].sum;
    }
    spread(p);
    ll val = 0;
    ll mid = (t[p].l + t[p].r) >> 1;
    if (mid >= l)
        val = (val + ask(p * 2, l, r)) % mod;
    if (mid < r)
        val = (val + ask(p * 2 + 1, l, r)) % mod;

    return val;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);

    int x, y, k;
    for (int i = 1; i <= m; i++)
    {

        int tmp;
        cin >> tmp;
        if (tmp == 1)
        {
            cin >> x >> y >> k;
            mul(1, x, y, k);
        }
        else if (tmp == 2)
        {
            cin >> x >> y >> k;
            add(1, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << ask(1, x, y) << endl;
        }
    }

    return 0;
}
