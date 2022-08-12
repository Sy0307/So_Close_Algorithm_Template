#include<bits/stdc++.h>

#define ll long long

using namespace std;

inline ll ksc(ll x, ll y, ll mod)
{
    return ( x * y - (ll) ( (long double) x / mod*y )*mod + mod ) % mod;     
}