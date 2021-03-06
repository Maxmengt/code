#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int mod=12345;
typedef long long ll;
typedef int matrix[125][125];
vector <int> b[30];
int N,c[30],p[30];
matrix a,ans;
void to_array(int x)
{
    for (int i=0;i<26;i++)
    {
        p[i]=x%c[i];
        x/=c[i];
    }
}
int to_value()
{
    int ret=0;
    for (int i=25;i>=0;i--)
        ret=ret*c[i]+p[i]%c[i];
    return(ret);
}
void mul(matrix c,matrix a,matrix b)
{
    matrix d={0};
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            for (int k=0;k<N;k++)
                d[i][j]=(d[i][j]+a[i][k]*b[k][j])%mod;
    memcpy(c,d,sizeof(d));
}
void power(ll x)
{
    for (int i=0;i<N;i++)
        ans[i][i]=1;
    for (;x;x>>=1)
    {
        if (x&1)
            mul(ans,ans,a);
        mul(a,a,a);
    }
}
bool check(int x)
{
    to_array(x);
    for (int i=0;i<26;i++)
    {
        if (b[i].empty())
            continue;
        bool flag=false;
        for (int j=0;j<b[i].size();j++)
            if (p[i]%b[i][j]==0)
            {
                flag=true;
                break;
            }
        if (!flag)
            return(false);
    }
    return(true);
}
int main()
{
    ll n;
    int m;
    scanf("%I64d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        char op[10];
        int x;
        scanf("%s%d",op,&x);
        b[op[0]-'A'].push_back(x);
    }
    N=1;
    for (int i=0;i<26;i++)
    {
        c[i]=1;
        for (int j=0;j<b[i].size();j++)
            c[i]*=b[i][j];
        N*=c[i];
    }
    for (int i=0;i<N;i++)
    {
        to_array(i);
        for (int j=0;j<26;j++)
        {
            if (b[j].empty())
                continue;
            p[j]++;
            a[to_value()][i]++;
            p[j]--;
        }
    }
    power(n);
    int sum=0;
    for (int i=0;i<N;i++)
        if (check(i))
            sum=(sum+ans[i][0])%mod;
    printf("%d\n",sum);
    return(0);
}

