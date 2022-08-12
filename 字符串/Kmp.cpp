#include <bits/stdc++.h>
using namespace std;
/*
    KMP 算法模板
    时间复杂度 ： O(n+m) [其中 n,m 是两字符串的长度]
    说明：
        1. str是长串 substr是短串 即 str.length >= substr.length
            也就是前者主串，后者模式串
        2.实现了“查找第一次匹配的位置” “匹配的次数” “记录所有匹配区间”三个功能
        3.三个功能的实现代码非常相似,第3个功能可以同时实现前2个的功能
        4.下标从0开始
        5.
*/
class Kmp
{
private:
    int f[10000 + 7];
    string str, substr; //记录所有匹配区间 [指在长串中的下标，下标从0开始]
public:
    int times; //记录匹配次数
    struct Interval
    {
        int l, r;
    } q[100000 + 7];
    Kmp()
    {};
    Kmp(string s1, string s2):str(s1),substr(s2)
    {
        pre(substr);
    }
    void pre(string substr) //预处理
    {
        memset(f, 0, sizeof(f)); //根据其前一个字母得到
        for (int i = 1; i < substr.length(); i++)
        {
            int j = f[i];
            while (j && substr[i] != substr[j])
                j = f[j];
            f[i + 1] = (substr[i] == substr[j]) ? j + 1 : 0;
        }
    }
    int FindsFirstPos() //找到第一次匹配的位置 str.length >= substr.length
    {
        pre(substr);
        int j = 0;
        for (int i = 0; i < str.length(); i++)
        {
            while (j && str[i] != substr[j])
                j = f[j];
            if (str[i] == substr[j])
                j++;
            if (j == substr.length())
            {
                return i - substr.length() + 1; //返回小串在大串中第一次出现的位置
            }
        }
        return -1; //不匹配返回-1
    }
    int FindMatchTimes() //返回匹配次数
    {
        pre(substr);
        int j = 0;
        int times = 0;
        for (int i = 0; i < str.length(); ++i)
        {
            while (j && str[i] != substr[j])
                j = f[j];
            if (str[i] == substr[j])
                j++;
            if (j == substr.length())
            {
                times++;
            }
        }
        return times; //不匹配的times将是0
    }

    void FindAllInterval() //找到并记录所有的匹配区间
    {
        int j = 0;
        times = 0;
        int n = str.length();
        for (int i = 0; i < n; ++i)
        {
            while (j && str[i] != substr[j])
                j = f[j];
            if (str[i] == substr[j])
                j++;
            if (j == n)
            {
                times++;
                q[times].l = i - str.length() + 1;
                q[times].r = i;
            }
        }
    }
} kmp;

//示例
int main()
{
    string s1 = "ABBAAAAAA";
    string s2 = "AAAA";
    auto k = Kmp(s1,s2);
    cout << k.FindMatchTimes() << endl;
    k.FindAllInterval();
    for (int i = 0; i < k.times; i++)
    {
        cout << k.q[i].l << " " << k.q[i].r << endl;
    }
}