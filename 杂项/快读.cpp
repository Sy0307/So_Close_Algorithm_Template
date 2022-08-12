int read(){                        //读入优化，可以照着这个模板来写，这个还算写的比较好看。 
    int re=0;
    char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9'){ 
        re=re*10+ch-'0'; 
        ch=getchar();
    }
    return re;
}