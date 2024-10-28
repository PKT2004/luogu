#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 15;

int n,k;
char g[N][N];
bool st[N];
int res=0;

void dfs(int x,int cnt)
{
    if(x>=n) return ;
    if(cnt==k) 
    {
        res++;
    }
    
  for(int i=0;i<n;i++)
  {
      if(!st[i]&&g[x][i]=='#')
      {
          st[i]=true;
          dfs(x+1,cnt+1);
          st[i]=false;
      }
  }
  dfs(x+1,cnt);
}

int main()
{
    while(cin>>n>>k,n>0&&k>0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",g[i]);
        }
        res=0;
        dfs(0,1);
        cout<<res;
    }
  return 0;
}
