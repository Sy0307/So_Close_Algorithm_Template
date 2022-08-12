#include "base.h"

// 取消注释可开启缓冲(针对大文件)
#define gc() getchar()
// cer us MAXB = 1 << 20;
// char fbuf[MAXB], *fr = fbuf, *ed = fbuf;
// #define fread() (ed=(fr=fbuf-1)+fread(fbuf,1,MAXB,stdin),fr==ed)
// inl is gc() { ret(fr == ed && fread()) ? EOF : *++fr; }
// #undef fread
template<class T>
inl T &fin(T &v) {
    is c = gc(); bool f = v = 0;
    whi(!isdigit(c)) f = (c = gc()) == '-';
    for(; isdigit(c); c = gc()) v = v * 10 + c - '0';
    ret f ? v = -v : v;
}