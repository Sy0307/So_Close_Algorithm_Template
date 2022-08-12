typedef struct node 
{
    int rank;
    int spc;
    int now;

    node(int a,int b,int c)
    {
        rank = a;
        spc = b;
        now =  c;
    }
    bool operator<(const node& a) const{
        return a.now<now;
    }
}s[100010];