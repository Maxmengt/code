#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f[110][110];
int a[110],b[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    memset(f,63,sizeof(f));
    for (int i=n;i;i--)
    {
        f[i][i]=0;
        for (int j=i+1;j<=n;j++)
            for (int k=i;k<j;k++)
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+a[i]*b[k]*a[k+1]*b[j]);
    }
    printf("%lld\n",f[1][n]);
    return(0);
}

