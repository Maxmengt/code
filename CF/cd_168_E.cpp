#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
bool win(ll a,ll b)
{
    if (a<b)
        swap(a,b);
    if (!b)
        return(false);
    if (!win(b,a%b))
        return(true);
    ll p=a/b;
    return(p%(b+1)%2==0);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll a,b;
        scanf("%I64d%I64d",&a,&b);
        printf("%s\n",win(a,b)?"First":"Second");
    }
    return(0);
}

