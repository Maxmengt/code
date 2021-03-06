#include <cstdio>
int n,a[30],b[30],c[30],d[30];
bool dfs(int dep,int limit)
{
    if (a[dep]==n)
    {
        printf("%d\n",dep-1);
        for (int i=1;i<dep;i++)
        {
            printf("lea e%cx, [",'a'+i);
            if (c[i]!=0)
            {
                printf("e%cx + ",'a'+b[i]-1);
                if (d[i]==0)
                    printf("e%cx",'a'+c[i]-1);
                else
                    printf("%d*e%cx",1<<d[i],'a'+c[i]-1);
            }
            else
                printf("%d*e%cx",1<<d[i],'a'+b[i]-1);
            printf("]\n");
        }
        return(true);
    }
    if (dep>limit)
        return(false);
    for (int i=1;i<=dep;i++)
    {
        for (int j=1;j<4;j++)
        {
            a[dep+1]=a[i]<<j;
            b[dep]=i;
            c[dep]=0;
            d[dep]=j;
            if (dfs(dep+1,limit))
                return(true);
        }
        for (int j=1;j<=dep;j++)
            for (int k=0;k<4;k++)
            {
                a[dep+1]=a[i]+(a[j]<<k);
                b[dep]=i;
                c[dep]=j;
                d[dep]=k;
                if (dfs(dep+1,limit))
                    return(true);
            }
    }
    return(false);
}
int main()
{
    scanf("%d",&n);
    a[1]=1;
    for (int i=0;i<=26;i++)
        if (dfs(1,i))
            break;
    return(0);
}

