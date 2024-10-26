#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int a,b,n;
int lad[205];
int min=1e9;

void dfs(int x,int sum)
{
 if(sum>res) return ;
 if(x<=0) return ; 
 if(x==b)
 {
   else res=sum;
 }
 dfs(x+lad[x],sum+1);
 dfs(x-lad[x],sum+1); 
}
int main()
{
  cin>>n>>a>>b;
  for(int i=1;i<n;i++)
    {
      cin>>lad[i];
    }
  dfs(1,sum);
}
