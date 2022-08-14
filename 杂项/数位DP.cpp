//Tips 支持到2^1e9 如需要更大范围修改f数组即可
// 运算出 1-n范围内，互不相同的数的个数
//example 135 - 110
//        20 - 19
// 调用方法，digitDP(int x)

#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define forall(i, a) for(auto &i : a)

class Solution {
public:
    int f[10][2][2][1025];
    vector<int> a;
    int dp(int pos,bool full,bool flag,int mask)
    {
        if(pos<0) return flag;
        if(f[pos][full][flag][mask]>=0)
            return f[pos][full][flag][mask];
        int &ret = f[pos][full][flag][mask];
        ret = 0;
        for(int i = 0;i<=9;i++)
        {
            if(full) {if(a[pos]<i) break;}
            int nextfull = full&&(a[pos]==i);
            int nextflag,nextmask;
            if(flag ||i>0)
            {
                if(mask>>i & 1>0)
                {
                    continue;
                }
                nextflag = 1;
                nextmask = mask|(1<<i);
            }
            else
            {
                nextflag = nextmask = 0;
            }
            ret+=dp(pos-1,nextfull,nextflag,nextmask);
        }
        return ret;
    }
    int digitDP(int n) {
        memset(f,-1,sizeof(f));
        int x = n;
        for(int i=0;i<=9;x/=10,i++)
        {
            a.push_back(x%10);
        }
        return dp(9,1,0,0);
    }
};