// WARN: 以下实现常数较大，比大多数实现慢，开启O2则与裸实现相差不大
#pragma once
#include "../base.h"

// 可维护[0, LEN)范围，所有[l, r)均左闭右开
// 调用节点成员使用->访问，例：seg->add(l, r, 1);
// 嫌麻烦可以直接裸用下面的Node
template<us LEN, class Node>
struct SegTree {
    Node pool[(LEN << 1) - 1], *iter = pool;
    inl Node *operator->() { ret iter; }
    inl void init(us l, us r) { iter = pool; build(l, r); }
private:
    void build(us l, us r) {  // 经测试，无返回值建树会快一点
        Node *ln, *rn;
        if(l + 1 != r) {
            con us md = (l + r) >> 1;
            build(l, md); ln = iter++;
            build(md, r); rn = iter++;
        } else ln = rn = NULL;
        iter->lb = l; iter->rb = r;
        iter->val = iter->ad = 0; iter->mu = 1;
        iter->ln = ln; iter->rn = rn;
    }
};

// BasicNode，仅支持加乘和查询区间和。(减法可复用，除法可复制增加)
// 依据使用场景，可删除部分内容以加速(类成员越少越快)，洛谷O2快50ms...
// TIP: 如想区间修改为同一个值，可以mul(,,0)，add(,,up)
template<class T>
struct BNode {
    us lb, rb;
    T val, mu, ad;
    BNode *ln, *rn;
    inl void push() {
        if(mu ^ 1) { ln->mt(mu); rn->mt(mu); mu = 1; }
        if(ad) { ln->at(ad); rn->at(ad); ad = 0; }
    }
    T que(us l, us r) {
        if(l == lb && rb == r) ret val;
        else {
            con us md = ln->rb; push(); T res = 0;
            if(l < md) res += ln->que(l, min(md, r));
            if(r > md) res += rn->que(max(l, md), r);
            ret res;
        }
    }

    // 加法
    inl void at(T up) { ad += up; val += up * T(rb - lb); }
    void add(us l, us r, T up) {
        if(l == lb && rb == r) at(up);
        else {
            con us md = ln->rb; push();
            if(l < md) ln->add(l, min(md, r), up);
            if(r > md) rn->add(max(l, md), r, up);
            val = ln->val + rn->val;
        }
    }
    // 乘法，请注意：删除乘法后push第一行也要更改
    inl void mt(T up) { mu *= up; ad *= up; val *= up; }
    void mul(us l, us r, T up) {
        if(l == lb && rb == r) mt(up);
        else {
            con us md = ln->rb; push();
            if(l < md) ln->mul(l, min(md, r), up);
            if(r > md) rn->mul(max(l, md), r, up);
            val = ln->val + rn->val;
        }
    }
};

template<class T, class cmp = less<T>>
struct MNode {
    us lb, rb;
    T val, mu, ad;
    MNode *ln, *rn;
    inl void push() {
        if(mu ^ 1) { ln->mt(mu); rn->mt(mu); mu = 1; }
        if(ad) { ln->at(ad); rn->at(ad); ad = 0; }
    }
    T que(us l, us r) {
        if(l == lb && rb == r) ret val;
        else {
            con us md = ln->rb; push();
            con bool lhs = l < md, rhs = r > md;
            if(lhs ^ rhs)
                ret lhs ? ln->que(l, min(md, r))
                        : rn->que(max(l, md), r);
            con T lv = ln->que(l, min(md, r));
            con T rv = rn->que(max(l, md), r);
            ret cmp()(lv, rv) ? lv : rv;
        }
    }

    // 加法
    inl void at(T up) { ad += up; val += up * T(rb - lb); }
    void add(us l, us r, T up) {
        if(l == lb && rb == r) at(up);
        else {
            con us md = ln->rb; push();
            if(l < md) ln->add(l, min(md, r), up);
            if(r > md) rn->add(max(l, md), r, up);
            val = cmp()(ln->val, rn->val) ? ln->val : rn->val;
        }
    }
    // 乘法，请注意：删除乘法后push第一行也要更改
    inl void mt(T up) { mu *= up; ad *= up; val *= up; }
    void mul(us l, us r, T up) {
        if(l == lb && rb == r) mt(up);
        else {
            con us md = ln->rb; push();
            if(l < md) ln->mul(l, min(md, r), up);
            if(r > md) rn->mul(max(l, md), r, up);
            val = cmp()(ln->val, rn->val) ? ln->val : rn->val;
        }
    }
};