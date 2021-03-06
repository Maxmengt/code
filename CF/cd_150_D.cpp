#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[160];
int a[160],ans[160],f[160][160][160];
int dp(int l,int r,int len)
{
    if (f[l][r][len]!=-1)
        return(f[l][r][len]);
    int &ret=f[l][r][len];
    if (l>r)
        ret=len==0?0:-1<<30;
    else
    {
        if (s[l]==s[r])
            ret=max(ret,max(dp(l+1,r-1,len+1),dp(l+1,r-1,0)+a[2*len+1+(l<r)]));
        for (int i=l;i<r;i++)
            ret=max(ret,max(dp(l,i,len)+dp(i+1,r,0),dp(l,i,0)+dp(i+1,r,len)));
    }
    if (ret<0)
        ret=-1<<30;
    return(ret);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==-1)
            a[i]=-1<<30;
    }
    scanf("%s",s+1);
    memset(f,-1,sizeof(f));
    for (int i=1;i<=n;i++)
    {
        ans[i]=ans[i-1];
        for (int j=1;j<=i;j++)
            ans[i]=max(ans[i],ans[j-1]+dp(j,i,0));
    }
    printf("%d\n",ans[n]);
    return(0);
}

