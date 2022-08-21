#include <bits/stdc++.h>
using namespace std;
class PAM
{
    static const int maxn = 3e5 + 5;

public:
    int las, tot;
    struct node
    {
        int ch[26], len, sum, fa;
    } t[maxn];
    PAM() { las = 0, tot = 1, t[0].fa = 1, t[1].len = -1; }
    void Insert(char *s, int pos)
    {
        auto jump = [&](int u, int pos) -> int
        {
            while (s[pos] ^ s[pos - t[u].len - 1])
                u = t[u].fa;
            return u;
        };
        int p = las, c = s[pos] - 'a';
        p = jump(p, pos);
        if (!t[p].ch[c])
        {
            int u = ++tot;
            t[u].len = t[p].len + 2;
            t[u].fa = t[jump(t[p].fa, pos)].ch[c];
            t[u].sum = t[t[u].fa].sum + 1;
            t[p].ch[c] = u;
        }
        las = t[p].ch[c];
    }
};