#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=20;

int n=0;
int arr[N];
int res=0;
int mem[35095][N]={0};

void dfs(int x,int sum)
{
if(sum>n) return; //剪枝
if(x==11)         //将sum!=n情况区分
{
if(sum==n)
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
