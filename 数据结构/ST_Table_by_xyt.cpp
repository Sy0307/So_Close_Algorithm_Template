#include <bits/stdc++.h>
#define sf(T) sizeof(T)
#define inl inline
#define stc static
#define con const
#define cer constexpr
#define ret return
#define whi(c) while (c)
using namespace std;
using is = int;
using il = long long;
using us = unsigned int;
using ul = unsigned long long;
using fs = float;
using fl = double;
#define ix __int128
using fx = long double;
cer ul ULINF = UINT64_MAX, LINF = 0x3f3f3f3f3f3f3f3f;
cer us USINF = UINT32_MAX, SINF = 0x3f3f3f3f;
con string ANS[2] = {"NO", "YES"}; // 可自定义二元答案

extern con ul MOD;
extern con us MAX;

#define ST_FOR                     \
    for (us i = 1; i <= logl; ++i) \
        for (us j = l; j < r; ++j)

template <us LEN, us LOG_L>
struct STF
{
    us far[LOG_L + 1][LEN] = {0};
    inl con us *operator[](us idx) con { ret far[idx]; }
    inl void build(us l, us r, us logl = LOG_L)
    {
        iota(far[0] + l, far[0] + r, l + 1);
        far[0][r - 1] = r - 1;
        ST_FOR far[i][j] = far[i - 1][far[i - 1][j]];
    }
};

template <us LEN, us LOG_L, class T, class cmp = less<con T &>>
struct ST
{
    con STF<LEN, LOG_L> &far;
    T val[LOG_L][LEN];
    ST(STF<LEN, LOG_L> &_f) : far(_f) {}
    inl T &operator[](us idx) { ret val[0][idx]; }
    inl con T &que(us l, us r)
    {
        us logd = log2(r - l); // TODO: 优化
        con T &lv = val[logd][l], &rv = val[logd][r - (1 << logd)];
        ret cmp()(lv, rv) ? lv : rv;
    }
    inl void build(us l, us r, us logl = LOG_L)
    {
        ST_FOR
        {
            con T &lv = val[i - 1][j], &rv = val[i - 1][far[i - 1][j]];
            val[i][j] = cmp()(lv, rv) ? lv : rv;
        }
    }
};
#undef ST_FOR

cer us MAXB = 1 << 18;
char fbuf[MAXB], *fr = fbuf, *ed = fbuf;
#define fread() (ed = (fr = fbuf - 1) + fread(fbuf, 1, MAXB, stdin), fr == ed)
inl is gc()
{
    ret(fr == ed && fread()) ? EOF : *++fr;
}
// #define gc() getchar() // 如fread不可用可使用原生getchar
template <class T>
inl T &read(T &v)
{
    is c = gc();
    bool f = v = 0;
    whi(!isdigit(c)) f = (c = gc()) == '-';
    for (; isdigit(c); c = gc())
        v = v * 10 + c - '0';
    ret f ? v = -v : v;
}
#undef fread

cer ul MOD = 1e9 + 7;
// cer ul MOD = 998244353;
cer us MAX = 1e5;

us n, m;
STF<MAX, 17> stf;
ST<MAX, 17, us, greater<us>> st(stf);

inl void solve()
{
    for (us l, r; --m;)
    {
        --read(l);
        read(r);
        printf("%u\n", st.que(l, r));
    }
}

inl void pre()
{
    read(n);
    ++read(m);
    for (us i = 0; i < n; ++i)
        read(st[i]);
    stf.build(0, n);
    st.build(0, n);
}

is main()
{
    pre();
    solve();
    ret 0;
}
