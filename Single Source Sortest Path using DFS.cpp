#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int vis[10000],dis[10000];
void DFS(int node,int d)
{
    vis[node]=1;
    dis[node]=d;
    for(auto x:v[node])
    {
        if(vis[x]==0)DFS(x,d+1);
    }
}
int main()
{
    int n,e;
    cout<<"Enter the number of node and edges: ";
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int x;
    cout<<"Enter source node: ";
    cin>>x;
    DFS(x,0);
    cout<<"Sortest Distance from Sorce node "<<x<<" to others node :\n";
    for(int i=1;i<=n;i++)
    {
        cout<<"\t\t\t\t"<<x<<"->"<<i<<" = "<<dis[i]<<endl;
    }
}
/*
Enter the number of node and edges:
7 6
1 2
2 4
2 5
1 3
3 6
3 7
Enter source node: 3
Sortest Distance from Sorce node 3 to others node :
                                3->1 = 1
                                3->2 = 2
                                3->3 = 0
                                3->4 = 3
                                3->5 = 3
                                3->6 = 1
                                3->7 = 1

*/
