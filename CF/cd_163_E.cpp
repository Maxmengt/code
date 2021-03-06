#include <cstdio>
#include <cstring>
const int maxn=1000010;
int m=1,q[maxn],dan[maxn],suf[maxn],son[maxn][26];
bool f[maxn];
char s[maxn];
int main()
{
    int n,Q;
    scanf("%d%d",&Q,&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        int x=1;
        for (int j=0;s[j];j++)
        {
            int p=s[j]-'a';
            if (!son[x][p])
            {
                son[x][p]=++m;
                x=m;
            }
            else
                x=son[x][p];
        }
        dan[x]=i;
        f[i]=true;
    }
    int l,r;
    q[l=r=1]=1;
    for (int i=0;i<26;i++)
        if (!son[1][i])
            son[1][i]=1;
    suf[1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=0;i<26;i++)
        {
            if (son[x][i]>1)
            {
                int y=son[x][i];
                q[++r]=y;
                if (x==1)
                    suf[y]=1;
                else
                    suf[y]=son[suf[x]][i];
            }
            if (!son[x][i])
                son[x][i]=son[suf[x]][i];
        }
        if (dan[suf[x]] && !dan[x])
            dan[x]=n+1;
    }
    while (Q--)
    {
        scanf("%s",s);
        int len=strlen(s);
        if (s[0]=='?')
        {
            int x=1,ans=0;
            for (int i=1;s[i];i++)
            {
                int p=s[i]-'a';
                x=son[x][p];
                for (int j=x;dan[j];j=suf[j])
                    ans+=f[dan[j]];
            }
            printf("%d\n",ans);
        }
        else
        {
            int p=0;
            for (int i=1;s[i];i++)
                p=p*10+s[i]-'0';
            if (s[0]=='+')
                f[p]=true;
            else
                f[p]=false;
        }
    }
    return(0);
}

