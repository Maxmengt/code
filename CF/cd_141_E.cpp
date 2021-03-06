#include <cstdio>
int f[1010],e[100010][3];
bool vis[100010];
void init(int n)
{
    for (int i=1;i<=n;i++)
        f[i]=i;
}
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
bool work(int n,int m)
{
    if (n%2==0)
        return(false);
    init(n);
    for (int i=1;i<=m;i++)
        if (e[i][2]==1)
            f[find(e[i][0])]=find(e[i][1]);
    int ans=0;
    for (int i=1;i<=m;i++)
        if (e[i][2]==0 && ans<n/2 && find(e[i][0])!=find(e[i][1]))
        {
            ans++;
            vis[i]=true;
            f[find(e[i][0])]=find(e[i][1]);
        }
    init(n);
    for (int i=1;i<=m;i++)
        if (vis[i])
            f[find(e[i][0])]=find(e[i][1]);
    for (int i=1;i<=m;i++)
        if (e[i][2]==0 && ans<n/2 && find(e[i][0])!=find(e[i][1]))
        {
            ans++;
            vis[i]=true;
            f[find(e[i][0])]=find(e[i][1]);
        }
    if (ans!=n/2)
        return(false);
    for (int i=1;i<=m;i++)
        if (e[i][2]==1 && ans<n-1 && find(e[i][0])!=find(e[i][1]))
        {
            ans++;
            vis[i]=true;
            f[find(e[i][0])]=find(e[i][1]);
        }
    return(ans==n-1);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        char ch;
        scanf("%d%d %c",&x,&y,&ch);
        e[i][0]=x,e[i][1]=y,e[i][2]=ch=='S';
    }
    if (!work(n,m))
        printf("-1\n");
    else
    {
        bool first=true;
        printf("%d\n",n-1);
        for (int i=1;i<=m;i++)
            if (vis[i])
            {
                if (!first)
                    printf(" ");
                first=false;
                printf("%d",i);
            }
        printf("\n");
    }
    return(0);
}

