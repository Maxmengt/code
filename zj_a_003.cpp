#include <cstdio>
#include <cstdlib>
int main()
{
   int a,b,c;
   while (scanf("%d%d",&a,&b)!=EOF)
   {
      c=(a*2+b)%3;
      if (c==0)
         printf("��ͨ\n");
      else if (c==1)
         printf("��\n");
      else
         printf("��\n");
   }
   system("pause");
   return(0);
}
