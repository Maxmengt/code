#include <cstdio>
#include <vector>
using namespace std;
vector <int> b,c;
int a[100010];
bool vis[100010],ok[100010];
int dfs(int x)
{
    if (vis[x])
        return(x);
    vis[x]=true;
    return(dfs(a[x]));
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        ok[a[i]]=true;
    }
    for (int i=1;i<=n;i++)
        if (!ok[i])
        {
            b.push_back(i);
            c.push_back(dfs(i));
        }
    for (int i=1;i<=n;i++)
        if (!vis[i])
        {
            b.push_back(i);
            c.push_back(i);
            dfs(i);
        }
    int ans=b.size();
    if (ans==1 && b[0]==c[0])
        ans=0;
    printf("%d\n",ans);
    for (int i=0;i<ans;i++)
        printf("%d %d\n",c[i],b[(i+1)%ans]);
    return(0);
}

