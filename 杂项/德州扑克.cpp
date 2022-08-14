#include<bits/stdc++.h>
using namespace std;

/*
使用方法 
将花色+点数压成一个string 最后把五张牌压成一个vector<string>
使用Poker::test()函数,返回一个pair,直接判断两个pair的大小即可
原作者：知乎 严格鸽
*/


namespace Poker {
    #define mst(a) memset(a,0,sizeof(a))
    int chint[128];
    bool cmp1(string &a, string &b) {
        return chint[a[0]] < chint[b[0]];
    }
    bool samehua(vector<string>&str) {
        bool flag = 1;
        for (int i = 1; i < str.size(); i++) {
            if (str[i][1] != str[0][1])return 0;
        }
        return 1;
    }

    int _hash(vector<int>&v) {
        int hs = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            hs = 20 * hs + v[i];
        }
        return hs;
    }


    bool flush(vector<string>&str) {
        vector<int>v;
        for (string &s : str) {
            v.push_back(chint[s[0]]);
        }
        if (v[0] == 2 && v[1] == 3 && v[2] == 4 && v[3] == 5 && v[4] == 14)return 1;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] != v[i - 1] + 1)return 0;
        }
        return 1;
    }


    vector<int>v;

    int cot[40];
    int cnt[40];

    bool four() {
        if (cnt[4])return 1;
        else return 0;
    }
    bool house() {
        return cnt[3] && cnt[2];
    }
    bool three() {
        return cnt[3];
    }
    pair<int, int> test(vector<string>str) {
        for (int i = 2; i <= 9; i++) {
            chint['0' + i] = i;
        }
        chint['T'] = 10;
        chint['J'] = 11;
        chint['Q'] = 12;
        chint['K'] = 13;
        chint['A'] = 14;
        sort(str.begin(), str.end(), cmp1);
        v.clear();
        mst(cot);
        mst(cnt);
        for (string &s : str) {
            v.push_back(chint[s[0]]);
        }

        if (samehua(str)) {
            if (str[0][0] == 'T' && str[1][0] == 'J' &&str[2][0] == 'Q' && str[3][0] == 'K' && str[4][0] == 'A') {
                return { 10,0 };
            }
            if (flush(str)) {
                if (v[0] == 2 && v[1] == 3 && v[2] == 4 && v[3] == 5 && v[4] == 14)return { 9,0 };
                else {
                    return { 9,_hash(v) };
                }
            }
        }

        for (int x : v)cot[x]++;
        for (int i = 0; i < 18; i++)cnt[cot[i]]++;

        if (four()) {
            int x = 0;
            for (int i = 0; i < 18; i++) {
                if (cot[i] == 1) {
                    x = i;
                    break;
                }
            }
            vector<int>vv;
            vv.push_back(x);
            for (int i = 0; i < v.size(); i++)if (v[i] != x)vv.push_back(v[i]);
            return { 8,_hash(vv) };
        }

        if (house()) {
            int x = 0;
            for (int i = 0; i < 18; i++) {
                if (cot[i] == 2) {
                    x = i;
                    break;
                }
            }
            vector<int>vv;
            vv.push_back(x);
            vv.push_back(x);

            for (int i = 0; i < v.size(); i++)if (v[i] != x)vv.push_back(v[i]);
            return { 7,_hash(vv) };
        }

        if (samehua(str)) {
            return { 6,_hash(v) };
        }

        if (flush(str)) {
            if (v[0] == 2 && v[1] == 3 && v[2] == 4 && v[3] == 5 && v[4] == 14)return { 5,0 };
            else {
                return { 5,_hash(v) };
            }
        }


        if (three()) {
            int x = 0;
            for (int i = 0; i < 18; i++) {
                if (cot[i] == 3) {
                    x = i;
                    break;
                }
            }
            vector<int>vv;

            for (int i = 0; i < v.size(); i++)if (v[i] != x)vv.push_back(v[i]);
            vv.push_back(x);
            vv.push_back(x);
            vv.push_back(x);
            return { 4,_hash(vv) };
        }

        if (cnt[2] == 2) {
            int x = 0;
            for (int i = 0; i < 18; i++) {
                if (cot[i] == 1) {
                    x = i;
                    break;
                }
            }
            vector<int>vv;
            vv.push_back(x);
            for (int i = 0; i < v.size(); i++)if (v[i] != x)vv.push_back(v[i]);
            return { 3,_hash(vv) };
        }

        if (cnt[2]) {
            int x = 0;
            for (int i = 0; i < 18; i++) {
                if (cot[i] == 2) {
                    x = i;
                    break;
                }
            }
            vector<int>vv;
            for (int i = 0; i < v.size(); i++)if (v[i] != x)vv.push_back(v[i]);
            vv.push_back(x);
            vv.push_back(x);
            return { 2,_hash(vv) };
        }
        return { 1,_hash(v) };
    }
}