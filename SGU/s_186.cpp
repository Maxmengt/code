#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <complex>
#include <iterator>
#include <memory>
#define SQR(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int a[110];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(a+1,a+n+1);
   int t=1,ans=0;
   for (int i=n-1;i;i--)
   {
      if (!a[i])
         break;
      ans++,a[t]--;
      if (!a[t])
         t++;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
