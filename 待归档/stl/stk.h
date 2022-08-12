#include "../base.h"

// 固定大小的Stack
template<us LEN, class T>
struct Stk {
    us sz = 0; T pool[LEN] = {0};
    inl T &operator[](con us idx) { ret pool[idx]; } // 慎用!!!
    inl con T &top() con { ret pool[sz - 1]; }
    inl void push(T val) { pool[sz++] = val; };
    inl T pop() { ret pool[--sz]; } // 注意，pop有返回值
    inl void init() { sz = 0; }
    // size, empty?还不如直接访问sz，不误改sz就没问题(风险自担)
};