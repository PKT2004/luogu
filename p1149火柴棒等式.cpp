//思路：位选数字和数字选位。位选数字复杂低
//条件：1.A+B=C;  2.A,B,C火柴数之和要为n-4（减去2个符号的火柴）
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 10010;
int sum = 0;
int num[N]={6,2,5,5,4,5,6,3,7,6};
int n;
int arr[4];
int res = 0;
void dfs(int x,int sum)
{
  if(sum > n-4) return ;
  if(x==4){
  if((arr[1]+arr[2]==arr[3])&&sum==n-4)
  {
    res++;
  }
    return ;
    }
  for(int i=0;i<=1000;i++)
    {
    arr[x]=i;
    dfs(x+1,sum+num[i]);  
    }
}
int main()
{

  cin>>n;
  for(int i = 10;i<=1000;i++)
    {
      num[i] = num[i/10] + num[i%10];
    }
  dfs(1,sum);
  printf("%d",res);
  return 0;
}
