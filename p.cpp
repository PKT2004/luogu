#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int sb[11][2];
int n;
bool st[11] = false;
int min;
int res = 0;

void dfs(int x,int s_sum,int b_sum)
{
if(x==11)
{
if(res==0) {min = abs(s_sum-b_sum);}
else{ 
res++;
if(min>abs(s_sum-b_sum)) min = abs(s_sum-b_sum);
}
return;
}
 for(int i=0;i<=1;i++)
{
if(!st[x])
{
st[x] = true;
dfs(x+1,s_sum,b_sum);
}
else
{
dfs(x+1,s_sum*sb[x][0],b_sum+sb[x][1]);
}
}
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
cin>>sb[i][0]>>sb[i][1];
dfs(1,1,0);
cout<<min; 
}
