#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <iostream>
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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=(1<<30)-1;
const double eps=1e-7;
const double pi=acos(-1.0);
int main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while (t--)
   {
      int n,sum=0,p=0;
      bool flag=false;
      cin>>n;
      for (int i=1;i<=n;i++)
      {
         int x;
         cin>>x;
         sum+=x;
         p^=x;
         if (x>1)
            flag=true;
      }
      if (!flag)
         cout<<(sum&1?2:1)<<endl;
      else
         cout<<(p?1:2)<<endl;
   }
   system("pause");
   return(0);
}
