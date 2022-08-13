// TIP: 以下实现比大多数裸实现常数要小
#pragma once
#include "../base.h"

#define ST_FOR               \
    for(us i = 1; i <= logl; ++i) \
        for(us j = l; j < r; ++j) 

template<us LEN, us LOG_L>
struct STF {
    us far[LOG_L + 1][LEN] = {0};
    inl con us *operator[](us idx) con { ret far[idx]; }
    inl void build(us l, us r, us logl = LOG_L) {
        iota(far[0] + l, far[0] + r, l + 1);
        far[0][r - 1] = r - 1;
        ST_FOR far[i][j] = far[i - 1][far[i - 1][j]];
    }
};

template<us LEN, us LOG_L, class T, class cmp = less<con T &>>
struct ST {
    con STF<LEN, LOG_L> &far;
    T val[LOG_L][LEN];
    ST(STF<LEN, LOG_L> &_f) : far(_f) {}
    inl T *operator()() { ret val[0]; } // 供scanf使用
    inl T &operator[](us idx) { ret val[0][idx]; } // 供cin,fin使用
    inl con T &que(us l, us r) {
        us logd = log2(r - l); // TODO: 优化
        // us logd = log(r - l) / log(2); // 备用(老版本不支持log2)
        con T &lv = val[logd][l], &rv = val[logd][r - (1 << logd)];
        ret cmp()(lv, rv) ? lv : rv;
    }
    inl void build(us l, us r, us logl = LOG_L) { ST_FOR {
        con T &lv = val[i - 1][j], &rv = val[i - 1][far[i - 1][j]];
        val[i][j] = cmp()(lv, rv) ? lv : rv;
    }}
};
#undef ST_FOR

/*
使用示例：
STF<MAX, LOG2_MAX> stf;
ST<MAX, LOG2_MAX, us> st_min(stf);
ST<MAX, LOG2_MAX, us, greater<us>> st_max(stf);
*/