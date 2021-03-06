#include <cstdio>
typedef long long ll;
ll u,v,mod;
ll get(ll delta,ll first,ll begin,ll end,ll l,ll r)
{
    if (begin==l && end==r)
    {
        ll last=first+(r-l)*delta;
        if (first>v || last<u)
            return(0);
        if (first<u)
            first+=(u-first)/delta*delta;
        if (first<u)
            first+=delta;
        if (last>v)
            last-=(last-v)/delta*delta;
        if (last>v)
            last-=delta;
        if (first>last)
            return(0);
        ll cnt=((last-first)/delta+1)%mod,sum=(first+last)%mod;
        return(cnt*sum%mod);
    }
    ll mid=begin+end>>1;
    if (r<=mid)
        return(get(delta<<1,first,begin,mid,l,r));
    else if (l>mid)
        return(get(delta<<1,first+delta,mid+1,end,l,r));
    else
        return((get(delta<<1,first,begin,mid,l,mid)+get(delta<<1,first+delta,mid+1,end,mid+1,r))%mod);
}
int main()
{
    ll n;
    int m;
    scanf("%I64d%d%I64d",&n,&m,&mod);
    mod<<=1;
    while (m--)
    {
        ll l,r;
        scanf("%I64d%I64d%I64d%I64d",&l,&r,&u,&v);
        printf("%I64d\n",get(1,1,1,n,l,r)/2);
    }
    return(0);
}

