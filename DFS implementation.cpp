#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int vis[100000];
void DFS(int node)
{
    vis[node]=1;
    cout<<node<<"->";
    for(auto x:v[node])
    {
        if(vis[x]!=1)
        {
            DFS(x);
        }
    }
}
int main()
{
    int n,edge;
    cout<<"Enter the number of edge: ";
    cin>>edge;
    while(edge--)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
       // v[y].push_back(x);
    }
    cout<<"Enter the starting node: ";
    cin>>n;
    DFS(n);
}
/*
Enter the number of edge:
 5
1 2
2 3
2 4
4 5
4 6

Enter the starting node:
1
DFS is: 1->2->3->4->5->6->
*/
