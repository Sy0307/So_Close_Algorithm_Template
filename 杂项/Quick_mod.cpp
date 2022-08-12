inline int inc(int x,int v,int mod)
{x+=v;return x>=mod?x-mod:x;}
// plus and mod

inline int dec(int x,int v,int mod)
{x-=v;return x<0?x+mod:x;}
// minus and mod;
