#include<iostream>
#include<algorithm>
#include<cstring>

const int N=25;
using namespace std;
int n;
string word[N];//1wei or 2wei
int g[N][N];
int use[N];
int res=0;
void dfs(string dragon,int x)
{
    res=max(res,(int)dragon.size());
    use[x]++;
    for(int i=0;i<n;i++)
    {
        if(use[i]<2&&g[x][i])
        {
            dfs(dragon+word[i].substr(g[x][i]),i);
        }
    }
    use[x]--;
}
int main()
{
    char start;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>word[i];
    }
    cin>>start;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            string a=word[i],b=word[j];
            for(int k=1;k<min(a.size(),b.size());k++)
            {
                if(a.substr(a.size()-k,k)==b.substr(0,k))
                {g[i][j]=k;break;}
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(word[i][0]==start)
        dfs(word[i],i);
    }
    cout<<res;
}
