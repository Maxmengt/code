#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair <int,int> > ans;
int f[60],d[60];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        f[i]=i;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        d[x]++,d[y]++;
        f[find(x)]=find(y);
    }
    bool flag=true;
    int sum=0,tot=0;
    for (int i=1;i<=n;i++)
    {
        if (d[i]!=2 && d[i]!=1 && d[i]!=0)
        {
            flag=false;
            break;
        }
        sum+=find(i)==i;
        tot+=2-d[i];
    }
    if (sum!=1 && tot/2!=sum)
        flag=false;
    if (!flag)
        printf("NO\n");
    else if (n==1 && m==0)
        printf("YES\n1\n1 1\n");
    else
    {
        for (int i=1;i<=n;i++)
            for (int T=1;T<=2;T++)
                for (int j=i+1;j<=n;j++)
                    if (d[i]<2 && d[j]<2 && find(i)!=find(j))
                    {
                        ans.push_back(make_pair(i,j));
                        d[i]++,d[j]++;
                        f[find(i)]=find(j);
                        break;
                    }
        for (int i=1;i<=n;i++)
            if (d[i]==1)
                for (int j=i+1;j<=n;j++)
                    if (d[j]==1)
                    {
                        ans.push_back(make_pair(i,j));
                        goto out;
                    }
out:
        sort(ans.begin(),ans.end());
        printf("YES\n%d\n",ans.size());
        for (int i=0;i<ans.size();i++)
            printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return(0);
}

