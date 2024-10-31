#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
typedef pair<int,int> PII;
//pair<int,int> 是C++标准库中的一个模板类，用于存储两个元素的配对。在这个例子中，pair的第一个模板参数int表示第一个元素的类型，
//第二个模板参数int表示第二个元素的类型。所以pair<int,int>表示一个包含两个整数的配对。
//PII 是为pair<int,int>定义的新类型别名，这样你就可以使用PII来代替pair<int,int>。
const int N = 1010;
char g[N][N];
int x1,y1,x2,y2;
int dist[N][N];
queue<PII> q;//声明了一个名为q的队列
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n;
int bfs(int x1,int y1)
{
    memset(dist,-1,sizeof dist);
    q.push({x1,y1});
    dist[x1][y1] = 0;
    
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        
        for(int i = 0;i<4;i++)
        {
            int a = t.first + dx[i],b = t.second + dy[i];
            if(a<1||b<1||a>n||b>n) continue ;
            if(g[a][b]!='0') continue ;
            if(dist[a][b]>0) continue ;
            
            q.push({a,b});
            dist[a][b] = dist[t.first][t.second]+1;
        }
    }
    return dist[x2][y2];
}
int main()
{
    cin>>n;
  //使用scanf时有问题
    for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
		cin>>g[i][j];
	    }
	}
    cin>>x1>>y1>>x2>>y2;
    int res = bfs(x1,y1);
    cout<<res;
}
