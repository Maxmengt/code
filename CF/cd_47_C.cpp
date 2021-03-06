#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector <string> a,ans,now;
char s[1010][1010],buf[100000];
bool calc()
{
    if (a[0].size()+a[2].size()!=a[1].size()+1)
        return(false);
    if (a[3].size()+a[5].size()!=a[4].size()+1)
        return(false);
    if (a[0][0]!=a[3][0] || a[0][a[0].size()-1]!=a[4][0])
        return(false);
    if (a[1][0]!=a[3][a[3].size()-1] || a[1][a[1].size()-1]!=a[5][0])
        return(false);
    if (a[1][a[0].size()-1]!=a[4][a[3].size()-1])
        return(false);
    if (a[2][0]!=a[4][a[4].size()-1] || a[2][a[2].size()-1]!=a[5][a[5].size()-1])
        return(false);
    for (int i=0;i<a[4].size();i++)
        for (int j=0;j<a[1].size();j++)
            s[i][j]='.';
    for (int i=0;i<a[0].size();i++)
        s[0][i]=a[0][i];
    for (int i=0;i<a[1].size();i++)
        s[a[3].size()-1][i]=a[1][i];
    for (int i=0;i<a[2].size();i++)
        s[a[4].size()-1][a[0].size()-1+i]=a[2][i];
    for (int i=0;i<a[3].size();i++)
        s[i][0]=a[3][i];
    for (int i=0;i<a[4].size();i++)
        s[i][a[0].size()-1]=a[4][i];
    for (int i=0;i<a[5].size();i++)
        s[i+a[3].size()-1][a[1].size()-1]=a[5][i];
    now.clear();
    for (int i=0;i<a[4].size();i++)
    {
        string tmp;
        for (int j=0;j<a[1].size();j++)
            tmp+=s[i][j];
        now.push_back(tmp);
    }
    return(true);
}
int main()
{
    for (int i=1;i<=6;i++)
    {
        scanf("%s",buf);
        a.push_back(buf);
    }
    sort(a.begin(),a.end());
    while (1)
    {
        if (calc() && (ans.empty() || now<ans))
            ans=now;
        if (!next_permutation(a.begin(),a.end()))
            break;
    }
    if (ans.empty())
        printf("Impossible\n");
    else
        for (int i=0;i<ans.size();i++)
            printf("%s\n",ans[i].c_str());
    return(0);
}

