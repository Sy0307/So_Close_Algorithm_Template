#include<bits/stdc++.h>
using namespace std;

template <typename T>
T qpow(T a, ll n)
{
    T ans = 1; // 赋值为乘法单位元，可能要根据构造函数修改
    while (n)
    {
        if (n & 1)
            ans = ans * a; // 这里就最好别用自乘了，不然重载完*还要重载*=，有点麻烦。
        n >>= 1;
        a = a * a;
    }
    return ans;
}