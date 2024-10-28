#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 15;

int n,k;
char g[N][N];
bool st[N];                 //标记某一列是否可以放棋子
int res=0;

void dfs(int x,int cnt)
{
    if(cnt==k)             //这个要放在x>=n前，临界条件下cnt==k+1时是卡在x==n的  
    {
        res++;
        return;            //注意return
    }
    if(x>=n) return ;
    
  for(int i=0;i<n;i++)
  {
      if(!st[i]&&g[x][i]=='#')
      {
          st[i]=true;
          dfs(x+1,cnt+1);
          st[i]=false;
      }
  }
  dfs(x+1,cnt);                //第一行不放棋子的情况
}

int main()
{
    while(cin>>n>>k,n>0&&k>0)  //c++特殊用法，做笔记;输入多组数据的循环
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
