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
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      bitset <32> a(n);
      int k=0;
      for (int i=31;i>=0;i--)
         if (a[i])
         {
            k=i;
            break;
         }
      for (int i=k;i>=0;i--)
         cout<<a[i];
      printf("\n");
   }
   system("pause");
   return(0);
}
