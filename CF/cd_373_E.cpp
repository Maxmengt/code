#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f[2][150010];
int q[150010];
int main()
{
    int n,m,D;
    scanf("%d%d%d",&n,&m,&D);
    int u=0,v=1,prev=1;
    for (int i=1;i<=m;i++)
    {
        int a,b,T;
        scanf("%d%d%d",&a,&b,&T);
        int l=1,r=0,t=1;
        ll limit=ll(D)*(T-prev);
        for (int j=1;j<=n;j++)
        {
            while (l<=r && j-q[l]>limit)
                l++;
            while (t<=n && t-j<=limit)
            {
                while (l<=r && f[u][t]>=f[u][q[r]])
                    r--;
                q[++r]=t++;
            }
            f[v][j]=f[u][q[l]]+b-abs(a-j);
        }
        swap(u,v);
        prev=T;
    }
    printf("%I64d\n",*max_element(f[u]+1,f[u]+n+1));
    return(0);
}

