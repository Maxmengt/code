#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[100];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(a+1,a+n+1);
   for (int i=1;i<=n;i++)
      printf("%d\n",a[i]);
   system("pause");
   return(0);
}
