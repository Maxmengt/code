#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    int a[10];
    for (int i=1;i<=4;i++)
        scanf("%d",&a[i]);
    while (1)
    {
        if (a[1]==1 && a[2]==1 && a[3]==1 && a[4]==1)
            break;
        while (1)
        {
            bool flag=false;
            for (int i=1;i<=4;i++)
            {
                int x=i==4?1:i+1;
                if (a[i]%2==0 && a[x]%2==0)
                {
                    a[i]/=2;
                    a[x]/=2;
                    printf("/%d\n",i);
                    flag=true;
                }
            }
            if (!flag)
                break;
        }
        if (a[1]==1 && a[2]==1 && a[3]==1 && a[4]==1)
            break;
        int x=rand()%4+1,y=x==4?1:x+1;
        a[x]++;
        a[y]++;
        printf("+%d\n",x);
    }
    return(0);
}

