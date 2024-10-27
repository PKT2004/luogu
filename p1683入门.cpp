#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 25;
int n,m,a,b;
char g[N][N]; 
int res = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool st[N][N];
//1.不走重复 2.走 3.上下左右 4.最多 5.越界
void dfs(int x,int y,int sum)
{
    
    for(int i = 0;i < 4;i++)
    {
        int c=x+dx[i];
        int d=y+dy[i];
        if(st[c][d]) continue;
        if(g[c][d]!='.') continue;
        if(c<0||c>=n||d<0||d>=m) continue;
        
        st[c][d] = true;
        res++;
        dfs(c,d,sum+1);
    }
}
int main()
{
    cin>>m>>n;
    for(int i = 0;i < n;i++)
    {
        scanf("%s",g[i]);
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(g[i][j]=='@')
            {
                a=i;
                b=j;
            }
        }
    }
    res++;
    dfs(a,b,1);
    cout<<res;
}
