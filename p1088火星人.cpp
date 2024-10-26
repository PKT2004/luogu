#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 10010;
int n,m;
int res=0;
int arr[N];
bool st[N];
int mars[N];
bool return0 = false;

void dfs(int x)
{
  if(return0) return;
  if(x>n){
   res++;
   if(res==m+1)
   {
     return0 = true;
    for(int i=1;i<=n;i++)
      {
        printf("%d ",arr[i]); 
      }
   }
   return;
  }
  for(int i=1;i<=n;i++)
    {
      if(!res)
      {
        i = mars[x];
      }
      if(!st[i])
      {
      st[i] = true;
      arr[x] = i;
      dfs(x+1);
      st[i] = false;
      }
    }
}
int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    {
      cin>>mars[i];
    }
  dfs(1);
  return 0;
}
