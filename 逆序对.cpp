#include<bits/stdc++.h>
using namespace std;
long long ans=  0;
int a[500100],c[500100];

void merge(int l,int r)
{
    if(l==r) return;
    int mid = (l+r)>>1;
    merge(l,mid);merge(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] =a[j++];
            ans+=mid-i+1;
        }
    }
    while(i<=mid)
    {
        c[k++] = a[i++];
    }
    while(j<=r)
    {
        c[k++] = a[j++];
    }
    for(int i=l;i<=r;i++)
        a[i] = c[i];
}
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    merge(1,n);
    cout<<ans<<endl;
    return 0;

}