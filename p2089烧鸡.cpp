#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=20;

int n=0;
int arr[N];
int res=0;
int mem[35095][N]={0};

void dfs(int x,int sum) //dfs:使用for往下遍历，遵循从小到大的原则，设置的参数一般代表位置
{
if(sum>n) return; //剪枝,遍历的时候会遍历到不符合的情况，然后进行剪枝
if(x==11)         
{
if(sum==n)        //将sum!=n情况区分      
{
for(int i=1;i<=10;i++)
{
mem[res][i]=arr[i];    
}
res++;
}
return;
}
for(int i=1;i<=3;i++)
{
arr[x]=i;
dfs(x+1,sum+i);
}
}

int main()
{
cin>>n;
dfs(1,0);
cout<<res<<endl;
for(int i=0;i<res;i++)
{
for(int j=1;j<=10;j++)
{
printf("%d ",mem[i][j]);
}
printf("\n");
}
return 0;
}
