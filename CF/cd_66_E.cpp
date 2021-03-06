#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[200010],b[200010],c[200010],f[200010],g[200010];
bool flag[200010];
void calc()
{
    for (int i=n+1;i<=n<<1;i++)
    {
        a[i]=a[i-n];
        b[i]=b[i-n];
        c[i]=c[i-n];
    }
    for (int i=1;i<=n<<1;i++)
    {
        f[i]=f[i-1]+a[i];
        g[i]=g[i-1]+b[i];
    }
    for (int i=1,j=1;i<=n;i++)
    {
        while (j-i+1<n && f[j]-f[i-1]>=g[j]-g[i-1])
            j++;
        if (j-i+1==n)
            flag[c[i]]=true;
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for (int i=1;i<=n;i++)
        c[i]=i;
    calc();
    reverse(a+1,a+n+1);
    reverse(b+1,b+n+1);
    reverse(c+1,c+n+1);
    rotate(a+1,a+n,a+n+1);
    rotate(c+1,c+n,c+n+1);
    calc();
    printf("%d\n",count(flag+1,flag+n+1,true));
    bool first=true;
    for (int i=1;i<=n;i++)
        if (flag[i])
        {
            if (!first)
                printf(" ");
            first=false;
            printf("%d",i);
        }
    printf("\n");
    return(0);
}

