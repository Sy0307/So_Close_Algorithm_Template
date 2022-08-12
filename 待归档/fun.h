#include "base.h"

template<class T>
inl void mem(T *arr, us b, us n) { memset(arr, b, n * sf(T)); }

template<class T>
inl void mxt(T &l, con T &r) { l = max(l, r); }
template<class T>
inl void mnt(T &l, con T &r) { l = min(l, r); }