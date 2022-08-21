#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
//header

/*使用方法
queue(l,r,k) 可以查询区间[l,r]中与k互质的数的个数。

*/



namespace qjhz
{
    typedef long long LL;
    int T, N, num;
    LL A, B;
    int a[100];
    void prime(int n)
    {
        num = 0;
        for (int i = 2; i * i <= n; i++)
        {
            if ((n % i) == 0)
            {
                num++;
                a[num] = i;
                while ((n % i) == 0)
                {
                    n /= i;
                }
            }
        }
        if (n > 1)
        {
            num++;
            a[num] = n;
        }
        return;
    }
    LL solve(LL r, int n)
    {
        prime(n);
        LL res = 0;
        for (int i = 1; i < (1 << num); i++)
        {
            int kk = 0;
            LL div = 1;
            for (int j = 1; j <= num; j++)
            {
                if (i & (1 << (j - 1)))
                {
                    kk++;
                    div *= a[j];
                }
            }
            if (kk % 2)
                res += r / div;
            else
                res -= r / div;
        }
        return r - res;
    }

    LL que(LL L, LL R, LL k)
    {
        return solve(R, k) - solve(L - 1, k);
    }
}
