#include <cstdio>
#include <map>
#include <utility>
using namespace std;
typedef long long ll;
const char ans[][10]={"Masha","Missing","Stas"};
ll n;
map <pair <int,int>,int> f;
bool check(int a,int b)
{
    ll t=1;
    for (int i=1;i<=b;i++)
    {
        t*=a;
        if (t>=n)
            return(true);
    }
    return(false);
}
int dp(int a,int b)
{
    pair <int,int> t(a,b);
    if (f.count(t))
        return(f[t]);
    if (check(a,b))
        return(f[t]=0);
    else if (a==1 && check(a+1,b))
        return(f[t]=1);
    else if (b==1 && check(a,b+1))
        return(f[t]=n-a&1?2:0);
    else
        return(f[t]=2-max(dp(a+1,b),dp(a,b+1)));
}
int main()
{
    int a,b;
    scanf("%d%d%I64d",&a,&b,&n);
    printf("%s\n",ans[dp(a,b)]);
    return(0);
}

