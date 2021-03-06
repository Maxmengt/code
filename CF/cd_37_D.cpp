#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int x[110],y[110],s[110],f[110][1010],c[1010][1010];
int main()
{
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&x[i]);
        s[i]=s[i-1]+x[i];
    }
    int n=s[m];
    for (int i=1;i<=m;i++)
        scanf("%d",&y[i]);
    for (int i=0;i<=n;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    f[0][0]=1;
    for (int i=1;i<=m;i++)
        for (int j=0;j<=s[i-1];j++)
        {
            if (!f[i-1][j])
                continue;
            for (int k=0;k<=min(s[i]-j,y[i]);k++)
                f[i][j+k]=(f[i][j+k]+ll(f[i-1][j])*c[s[i]-j][k])%mod;
        }
    int ans=f[m][n];
    for (int i=1;i<=m;i++)
    {
        ans=ll(ans)*c[n][x[i]]%mod;
        n-=x[i];
    }
    printf("%d\n",ans);
    return(0);
}

