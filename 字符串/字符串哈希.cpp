#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull; //自然溢出
//速度快但是容易被卡
namespace str_hash
{
    //从1开始计数
    const static int mod = 23233331;
    const static int maxn = 2e6 + 7;
    ull base = 100071; //经验值
    ull p[maxn];
    char s[maxn];
    unordered_map<ull, ull> rv;
    unordered_map<ull, ull> hs;
    int n;
    void init(string &str)
    {
        n = str.length();
        for (int i = 1; i <= n; i++)
            s[i] = str[i - 1];
        p[0] = 1; //注意
        for (int i = 1; i <= n; i++)
        {
            hs[i] = (hs[i - 1] * base + s[i]) % mod;
            p[i] = p[i - 1] * base;
        }
        for (int i = n; i; --i)
            rv[i] = (rv[i + 1] * base + s[i]) % mod;
    }
    ull que(ull l, ull r)
    {
        return (hs[r] - hs[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
    ull rev(ull l, ull r)
    {
        return (rv[l] - rv[r + 1] * p[r - l + 1] % mod + mod) % mod;
    }
    // rev(L,R) = que(L,R) 说明是回文
}

//字符串双哈希 ，绝大多数时候不会被卡
//但是速度很慢，慎用

namespace str_double_hash
{
    //从1开始计数
    const static int t1 = 998244353;
    const static int t2 = 1019260817;
    const int maxn = 2e6 + 7;
    ull base = 131; //经验值
    ull p1[maxn];
    ull p2[maxn];
    char s[maxn];
    unordered_map<ull, ull> rv1;
    unordered_map<ull, ull> rv2;
    unordered_map<ull, ull> hs1;
    unordered_map<ull, ull> hs2;
    int n;
    void pre()
    {

        p1[0] = 1;
        p2[0] = 1;
        for (int i = 1; i <= maxn - 1; i++)
        {
            p1[i] = p1[i - 1] * base % t1;
            p2[i] = p2[i - 1] * base % t2;
        }
    }
    void init(string &str)
    {
        n = str.length();
        for (int i = 1; i <= n; i++)
            s[i] = str[i - 1];
        for (int i = 1; i <= n; i++)
        {

            hs1[i] = (hs1[i - 1] * base % t1 + s[i] + t1) % t1;
            hs2[i] = (hs2[i - 1] * base % t2 + s[i] + t2) % t2;
        }
        for (int i = n; i; --i)
        {
            rv1[i] = (rv1[i + 1] * base % t1 + s[i] + t1) % t1;
            rv2[i] = (rv2[i + 1] * base % t2 + s[i] + t2) % t2;
        }
    }
    ull que(ull l, ull r)
    {
        auto h1 = (hs1[r] - hs1[l - 1] * p1[r - l + 1] % t1 + t1) % t1;
        auto h2 = (hs2[r] - hs2[l - 1] * p2[r - l + 1] % t2 + t2) % t2;
        return h1 * t2 + h2;
    }
    ull rev(ull l, ull r)
    {
        auto r1 = (rv1[l] - rv1[r + 1] * p1[r - l + 1] + t1) % t1;
        auto r2 = (rv2[l] - rv2[r + 1] * p2[r - l + 1] + t2) % t2;
        return r1 * t2 + r2;
    }
    // rev(L,R) = que(L,R) 说明是回文
}