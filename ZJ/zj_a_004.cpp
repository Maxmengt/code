#include <cstdio>
#include <cstdlib>
int main()
{
   int x;
   while (scanf("%d",&x)!=EOF)
      if (x%4==0 && x%100!=0 || x%400==0)
         printf("�c��\n");
      else
         printf("ƽ��\n");
   system("pause");
   return(0);
}
