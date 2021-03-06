#include <cstdio>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;
vector <int> Y;
int N,p[200010],x[200010],y[200010];
set <pair <int,int> > S[200010];
void add(int x,int y,int t)
{
    pair <int,int> tmp(x,y);
    for (int i=t;i<=N;i+=i&-i)
        S[i].insert(tmp);
}
void del(int x,int y,int t)
{
    pair <int,int> tmp(x,y);
    for (int i=t;i<=N;i+=i&-i)
        S[i].erase(tmp);
}
void get(int x,int y,int t)
{
    pair <int,int> tmp(x,y),ans(1<<30,1<<30);
    for (int i=t;i;i-=i&-i)
    {
        set <pair <int,int> >::iterator k=S[i].lower_bound(tmp);
        if (k!=S[i].end() && *k<ans)
            ans=*k;
    }
    if (ans.first==1<<30)
        printf("-1\n");
    else
        printf("%d %d\n",ans.first,ans.second);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        char op[10];
        scanf("%s%d%d",op,&x[i],&y[i]);
        if (op[0]=='a')
            p[i]=0;
        else if (op[0]=='r')
            p[i]=1;
        else
        {
            p[i]=2;
            x[i]++,y[i]++;
        }
        Y.push_back(-y[i]);
    }
    sort(Y.begin(),Y.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    N=Y.size();
    for (int i=1;i<=n;i++)
    {
        int q=lower_bound(Y.begin(),Y.end(),-y[i])-Y.begin()+1;
        if (p[i]==0)
            add(x[i],y[i],q);
        else if (p[i]==1)
            del(x[i],y[i],q);
        else
            get(x[i],y[i],q);
    }
    return(0);
}

