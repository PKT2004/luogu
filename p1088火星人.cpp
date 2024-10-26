//全排列dfs算法
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

void dfs(int x)                    //记录第x个位置所填的数字
{
  if(return0) return;              //结束标志
  if(x>n){                         //只要大于10说明就是合理的方案
   res++;
   if(res==m+1)                    //m+1,1代表起始数字
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
      if(!res)                   //将火星人给的数字作为第一个，以此往下遍历，遍历规则是前面数字锁定后，根据大小来排，如1 23，1 32，就是锁了1，然后23，32便是从小到大
      {
        i = mars[x];
      }
      if(!st[i])                //如果被占用，则排除这种情况
      {
      st[i] = true;
      arr[x] = i;
      dfs(x+1);
      st[i] = false;            //还原
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
