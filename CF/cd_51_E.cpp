#include <cstdio>
typedef long long ll;
ll a[5][710][710];
int d[710];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        d[x]++,d[y]++;
        a[1][x][y]=a[1][y][x]=1;
    }
    for (int p=2;p<=3;p++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    a[p][i][j]+=a[p-1][i][k]*a[1][k][j];
    ll ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            ans+=a[2][i][j]*a[3][i][j];
    ans/=10;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=j+1;k<=n;k++)
                if (a[1][i][j] && a[1][i][k] && a[1][j][k])
                    ans-=d[i]+d[j]+d[k]-3;
    printf("%I64d\n",ans);
    return(0);
}

