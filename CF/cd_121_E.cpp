#include <cstdio>
int n,a[100010],c[100010];
bool f[100010],g[100010];
bool lucky(int x)
{
    while (x)
    {
        if (x%10!=4 && x%10!=7)
            return(false);
        x/=10;
    }
    return(true);
}
void add(int x,int y)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]+=y;
}
int find(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret+=c[i];
    return(ret);
}
int main()
{
    for (int i=1;i<=10000;i++)
        g[i]=lucky(i);
    int m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        f[i]=g[a[i]];
        if (f[i])
            add(i,1);
    }
    while (m--)
    {
        char op[10];
        scanf("%s",&op);
        if (op[0]=='a')
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            for (int j=x;j<=y;j++)
            {
                a[j]+=z;
                if (f[j])
                {
                    add(j,-1);
                    f[j]=false;
                }
                if (g[a[j]])
                {
                    add(j,1);
                    f[j]=true;
                }
            }
        }
        else
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",find(y)-find(x-1));
        }
    }
    return(0);
}

