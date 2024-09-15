#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>v[N];
int vis[N],level[N];
void bfs(int node)
{
    queue<int>q;
    q.push(node);
    vis[node]=1;
    level[node]=1;
    cout<<"BFS :- ";
    while(!q.empty())
    {
        int fr=q.front();
        cout<<fr<<" ";
        q.pop();
        for(auto x:v[fr])
        {
            if(!vis[x])
            {
                vis[x]=1;
                level[x]=level[fr]+1;
                q.push(x);
            }
        }
    }
    cout<<endl;
}
int main()
{
    cout<<"Enter the number of edge: ";
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout<<"\nAdjacency List: \n";
    for(int i=1; i<=n; i++)
    {
        cout<<i;
        for(auto x:v[i])cout<<"->"<<x;
        cout<<endl;
    }
    cout<<endl;
    bfs(1);
    cout<<endl;
    cout<<"Distance from source node: \n";
    for(int i=1; i<=n; i++)
    {
        cout<<"\t\t\t"<<i<<"->"<<level[i]<<endl;
    }
}
