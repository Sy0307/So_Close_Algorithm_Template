#include <bits/stdc++.h>
using namespace std;

// 并查集 按秩合并 复杂度 O(mlog n)
const int Maxn = 100010;
class DSU_BASIC
{
    int fa[Maxn];
    int siz[Maxn];

public:
    DSU_BASIC(int n)
    {
        for (int i = 0; i < n; i++)
            fa[i] = i;
    }
    void init(int n)
    {
        for (int i = 0; i < n; i++)
            fa[i] = i;
    }
    int find(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (siz[x] > siz[y]) //比较大小，更新大的父节点
            swap(x, y);
        fa[x] = y;
    //    val[px] = -val[x] + v + val[y]; 这里是处理带权并查集的情况
        siz[y] += siz[x]; //并查集大小处理
    }
};
