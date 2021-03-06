#include <cstdio>
#include <vector>
#include <map>
using namespace std;
map <int,vector <int> > M;
int n,a[100010],ans[100010];
int find(int p)
{
    int x=a[p];
    for (int i=0;i<M[x].size();i++)
    {
        int y=M[x][i],t=y;
        if (y<=p)
            continue;
        bool flag=true;
        for (int j=p;j<y;j++,t++)
            if (t>n || a[j]!=a[t])
            {
                flag=false;
                break;
            }
        if (flag)
            return(y);
    }
    return(0);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        M[a[i]].push_back(i);
    }
    int m=0;
    for (int i=1;i<=n;i++)
    {
        int len=find(i);
        if (len==0)
            ans[++m]=a[i];
        else
        {
            i=len-1;
            m=0;
        }
    }
    printf("%d\n",m);
    for (int i=1;i<=m;i++)
        printf("%d%c",ans[i],i==m?'\n':' ');
    return(0);
}

