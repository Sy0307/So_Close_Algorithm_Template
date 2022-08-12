#include "../base.h"
#include "../fun.h"

template<us LEN, class T>
struct Arr {
    T pool[LEN];
    inl T &operator[](con us idx) { ret pool[idx]; }
    inl void mem(con T b, us n = LEN) { mem(pool, b, n); }
};