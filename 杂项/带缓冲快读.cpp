#include <cctype>
#include <cstdio>
// 取消注释可开启缓冲(针对大文件)
#define gc() getchar()
// const int MAXB = 1 << 20;
// char fbuf[MAXB], *fr = fbuf, *ed = fbuf;
// #define fread() (ed=(fr=fbuf-1)+fread(fbuf,1,MAXB,stdin),fr==ed)
// inline int gc() { return (fr == ed && fread()) ? EOF : *++fr; }
// #undef fread
template<class T>
inline T &fin(T &v) {
    int c = gc(); bool f = v = 0;
    while(!isdigit(c)) f = (c = gc()) == '-';
    for(; isdigit(c); c = gc()) v = v * 10 + c - '0';
    return f ? v = -v : v;
}