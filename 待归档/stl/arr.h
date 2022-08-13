#pragma once
#include "../base.h"

template<us LEN, class T>
struct Arr {
    T pool[LEN];
    inl T *operator()() { ret pool; }
    inl T &operator[](con us idx) { ret pool[idx]; }
    inl void init(con T b, us n = LEN) { mem(pool, b, n); }
};