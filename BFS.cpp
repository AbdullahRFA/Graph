#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int vis[10000],dis[10000];
void bfs(int node)
{
    queue<int>q;
    q.push(node);
    vis[node]=1;
    dis[node]=0;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto child:v[cur])
        {
            if(vis[child]==0)
            {
                vis[child]=1;
                dis[child]=dis[cur]+1;
                q.push(child);
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);
    cout<<"Root 1: \n";
    for(int i=1;i<=n;i++)
    {
        cout<<"Distance  from root to "<<i<<" is "<<dis[i]<<endl;
    }
}
/*
6 5
1 4
2 4
3 4
4 5
5 6
Root 1:
Distance  from root to 1 is 0
Distance  from root to 2 is 2
Distance  from root to 3 is 2
Distance  from root to 4 is 1
Distance  from root to 5 is 2
Distance  from root to 6 is 3
*/
