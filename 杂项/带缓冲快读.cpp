#include <bits/stdc++.h>
using namespace std;

constexpr int MAXB = 1 << 20;
char ibuf[MAXB], *ifr = ibuf, *ied = ibuf;
#define fread() (ied=(ifr=ibuf)+fread(ibuf,1,MAXB,stdin),ifr==ied) // 单次fread不会等待输入
#define ischar(c) (!isspace(c))
inline int gc() { return (ifr==ied && fread()) ? EOF : *(ifr++); } // 读取并弹出字符(类似getchar)
inline int gr() { return (ifr==ied && fread()) ? EOF : *ifr; } // 读取字符
inline int fit() { while(isspace(gr())) ++ifr; return gr(); } // 将空字符丢弃，并返回第一个非空字符或EOF
#undef fread

template<class T> inline T &fin(T &v) {
    int c = v = 0; bool f = fit()=='-'; ifr += f;
    while(isdigit(c=gc())) v = v*10 + (c ^ 48);
    return f ? (v=-v) : v;
}

// 读取非空字符(建议手动gc()，这个只是简写)
template<> inline char &fin(char &v) { return fit(), v = gc(); }

// C++式字符串，如情况允许，建议使用C式字符串
template<> inline string &fin(string &str) {
    str.clear();
    for(char *fp; fit()!=EOF;) {
        for(fp=ifr; fp<ied&&ischar(*fp); ++fp){}
        str.append(ifr, fp - ifr); // O(n)
        if((ifr=fp) != ied) break;
    } return str;
}

// C式字符串
inline char *fin(char *ch) {
    char *cp = ch;
    for(char *fp; fit()!=EOF;) {
        for(fp=ifr; fp<ied&&ischar(*fp); ++fp){}
        const int SZ = fp - ifr;
        memcpy(cp, ifr, SZ*sizeof(char)); cp += SZ;
        if((ifr=fp) != ied) break;
    } return *cp = '\0', ch;
}