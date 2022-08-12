#pragma once
#include "base.h"

// V3.0
// WARN: 为了防止误用，未实现输入重载，但是可以直接输出
// TIP: 如欲加速，请尽量使用同类型对象作为运算对象(MT += MT)，而不是(MT += T)
// TIP: 另外，对于用不到的成员函数，也可删除以加速
template<class T, class U, con U &M>
struct MT {
    T raw;
    inl MT() : raw(0) {} MT(con T _raw) : raw(_raw % M) {}
    inl operator T() con { ret raw; }
    inl void add(con MT &r) { raw += r.raw; if(raw >= M) raw -= M; }
    inl void sub(con MT &r) { if(r.raw > raw) raw += M - r.raw; else raw -= r.raw; }
    inl void mul(con MT &r) { raw = (U(raw) * r.raw) % M; }
    inl MT operator-() { MT r; ret r.raw = M - raw, r; }
    inl MT &operator=(con MT &r) { ret raw = r.raw, *this; }
    inl MT &operator+=(con MT &r) { ret add(r), *this; }
    inl MT &operator-=(con MT &r) { ret sub(r), *this; }
    inl MT &operator*=(con MT &r) { ret mul(r), *this; }
    friend inl MT operator+(MT l, con MT &r) { ret l.add(r), l; }
    friend inl MT operator-(MT l, con MT &r) { ret l.sub(r), l; }
    friend inl MT operator*(MT l, con MT &r) { ret l.mul(r), l; }
};

template<con ul &M>
using mt = MT<us, ul, M>;
using ms = mt<MOD>;