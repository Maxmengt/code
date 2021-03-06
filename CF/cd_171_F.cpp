#include <cstdio>
bool prime(int x)
{
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
            return(false);
    return(true);
}
int reverse(int x)
{
    int ret=0;
    while (x)
    {
        ret=ret*10+x%10;
        x/=10;
    }
    return(ret);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=10;;i++)
    {
        if (prime(i) && prime(reverse(i)) && i!=reverse(i))
            n--;
        if (n==0)
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

