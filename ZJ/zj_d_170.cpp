#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int x1,x2,x3,y1,y2,y3;
      scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
      if ((x2-x1)*(y3-y1)==(x3-x1)*(y2-y1) && (x3-x2)*(x3-x1)<=0 && (y3-y2)*(y3-y1)<=0)
         printf("ԓ���Ė|��!������׌������\n");
      else
         printf("���H����!ĸ�H����!�ҿ쵽�ˣ�\n");
   }
   system("pause");
   return(0);
}
