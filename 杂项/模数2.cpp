// WARN: 为了防止误用，未实现输入重载，但是可以直接输出
// TIP: 如欲加速，请尽量使用同类型对象作为运算对象(MT += MT)，而不是(MT += T)
// TIP: 另外，对于用不到的成员函数，也可删除以加速
template<class T, class U, const U &M>
struct MT { // T 基础类型，U 乘法上界类型(用于防止乘法溢出), M 全局变量
    T raw;
    inline MT() : raw(0) {} MT(const T _raw) : raw(_raw % M) {}
    inline operator T() const { return raw; } // 自动转换
    inline void add(const MT &r) { raw += r.raw; if(raw >= M) raw -= M; }
    inline void sub(const MT &r) { if(r.raw > raw) raw += M - r.raw; else raw -= r.raw; }
    inline void mul(const MT &r) { raw = (U(raw) * r.raw) % M; }
    inline MT operator-() { MT r; return r.raw = M - raw, r; }
    inline MT &operator=(const MT &r) { return raw = r.raw, *this; }
    inline MT &operator+=(const MT &r) { return add(r), *this; }
    inline MT &operator-=(const MT &r) { return sub(r), *this; }
    inline MT &operator*=(const MT &r) { return mul(r), *this; }
    friend inline MT operator+(MT l, const MT &r) { return l.add(r), l; }
    friend inline MT operator-(MT l, const MT &r) { return l.sub(r), l; }
    friend inline MT operator*(MT l, const MT &r) { return l.mul(r), l; }
};

#include <iostream>
// 使用示例
long long MOD = 114514; // 类型参数必须是全局的
void test() {
    using mt = MT<int, long long, MOD>;
    mt a(1919810);
    // 因为使用了friend，所以双目需要强制转换，但是单目没有使用
    std::cout << a << ' ' << (a *= 10) << ' ' << (a * mt(10)) << '\n';
    // MOD 可随时更改，适用于全局MOD不定的场景
    MOD = 19260817;
    a = mt(1919810);  // 注意更改后原值不会更新
    // 因此建议仅在全部值初始化后更改MOD的情形下使用该类型
    std::cout << a << ' ' << (a *= 10) << ' ' << (a * mt(10)) << '\n';
}
// 实际使用示例:https://www.luogu.com.cn/record/83562355
// 另外此实现并不是最快的(但是相对好用，且代价不是很大),
// 具体见:https://www.luogu.com.cn/record/82776238