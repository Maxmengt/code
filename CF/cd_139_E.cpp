#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector <pair <int,int> > a,s;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        int x,y,l,r;
        scanf("%d%d%d%d",&x,&y,&l,&r);
        l=100-l,r=100-r;
        s.push_back(make_pair(x-y,l));
        s.push_back(make_pair(x,-l+1));
        s.push_back(make_pair(x+1,r));
        s.push_back(make_pair(x+y+1,-r+1));
    }
    sort(s.begin(),s.end());
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a.push_back(make_pair(x,y));
    }
    sort(a.begin(),a.end());
    double ans=0,p=0;
    vector <pair <int,int> >::iterator k=s.begin();
    int cnt=0;
    for (int i=0;i<m;i++)
    {
        while (k!=s.end() && k->first<=a[i].first)
        {
            if (k->second==0)
                cnt++;
            else if (k->second==1)
                cnt--;
            else if (k->second>0)
                p+=log(k->second/100.0);
            else
                p-=log(-(k->second-1)/100.0);
            k++;
        }
        if (cnt==0)
            ans+=exp(p)*a[i].second;
    }
    printf("%.10f\n",ans);
    return(0);
}

