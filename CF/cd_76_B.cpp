#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
map <int,int> M;
int a[100010],b[100010],to[100010],t[100010];
int main()
{
    int n,m;
    scanf("%d%d%*d%*d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        M[b[i]]=i;
    }
    memset(t,63,sizeof(t));
    int inf=t[0];
    for (int i=1;i<=n;i++)
    {
        map <int,int>::iterator p=M.lower_bound(a[i]);
        if (p==M.begin())
        {
            to[i]=1;
            t[1]=min(t[1],abs(a[i]-b[1]));
            continue;
        }
        else if (p==M.end())
        {
            to[i]=m;
            t[m]=min(t[m],abs(a[i]-b[m]));
        }
        int pos=p->second,t1=abs(a[i]-b[pos-1]),t2=abs(a[i]-b[pos]),k;
        if (t1!=t2)
            k=t1<t2?pos-1:pos;
        else if (t[pos-1]==inf || t[pos-1]==t1)
            k=pos-1;
        else
            k=pos;
        to[i]=k;
        t[k]=min(t[k],min(t1,t2));
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int x=to[i];
        ans+=t[x]!=abs(a[i]-b[x]);
    }
    printf("%d\n",ans);
    return(0);
}

