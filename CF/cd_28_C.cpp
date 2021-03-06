#include <cstdio>
#include <cmath>
const double eps=1e-8;
double c[60][60],f[60][60][60];
int a[60];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for (int i=0;i<=n;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    f[0][0][0]=1;
    for (int i=0;i<=n;i++)
        for (int j=0;j<m;j++)
            for (int k=0;k<=50;k++)
            {
                if (f[i][j][k]<eps)
                    continue;
                for (int l=0;l<=n-i;l++)
                {
                    int x=l/a[j+1]+(l%a[j+1]!=0);
                    if (k>x)
                        x=k;
                    f[i+l][j+1][x]+=f[i][j][k]*c[i+l][i];
                }
            }
    double ans=0,sum=0;
    for (int i=0;i<=50;i++)
    {
        ans+=f[n][m][i]*i;
        sum+=f[n][m][i];
    }
    printf("%.10f\n",ans/sum);
    return(0);
}

