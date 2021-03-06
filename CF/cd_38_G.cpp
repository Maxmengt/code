#include <cstdio>
#include <algorithm>
using namespace std;
const int m=320;
struct data
{
    int n,x,a[2*m+10];
    data *next;
};
data *head;
int get(int value,int limit)
{
    int ret=0;
    data *k;
    for (k=head;k!=NULL;k=k->next)
    {
        if (k->x>value)
            break;
        ret+=k->n;
    }
    if (k!=NULL)
        for (int i=1;i<=k->n;i++)
        {
            if (k->a[i]>value)
                break;
            ret++;
        }
    return(min(ret,limit)+1);
}
void split(data *k)
{
    data *t=new(data);
    t->x=k->x=0;
    for (int i=1;i<=m;i++)
    {
        t->a[i]=k->a[i+m];
        t->x=max(t->x,t->a[i]);
        k->x=max(k->x,k->a[i]);
    }
    k->n=t->n=m;
    t->next=k->next;
    k->next=t;
}
void insert(int value,int pos)
{
    if (head==NULL)
    {
        head=new(data);
        head->n=1;
        head->x=head->a[1]=value;
        head->next=NULL;
        return;
    }
    data *k;
    for (k=head;k!=NULL;k=k->next)
    {
        if (pos<=k->n+1)
            break;
        pos-=k->n;
    }
    for (int i=k->n;i>=pos;i--)
        k->a[i+1]=k->a[i];
    k->a[pos]=value;
    k->x=max(k->x,value);
    k->n++;
    if (k->n==2*m)
        split(k);
}
int ans[100010],p[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p[x]=i;
        int pos=get(x,y);
        insert(x,pos);
    }
    int t=0;
    for (data *k=head;k!=NULL;k=k->next)
        for (int i=1;i<=k->n;i++)
            ans[++t]=k->a[i];
    reverse(ans+1,ans+n+1);
    for (int i=1;i<=n;i++)
        printf("%d%c",p[ans[i]],i==n?'\n':' ');
    return(0);
}

