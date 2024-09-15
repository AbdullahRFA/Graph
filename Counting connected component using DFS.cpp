#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int vis[10000];
int DFS(int node)
{
    vis[node]=1;
    for(auto x:v[node])
    {
        if(vis[x]!=1)DFS(x);
    }

}
int main()
{
    int n,e;
    cout<<"Enter node and edge: ";
    cin>>n>>e;
    while(e--)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int count=0;
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            count++;
        DFS(i);
        }
    }
    cout<<"Number of Connected Components are : "<<count<<endl;
}
/*
Enter node and edge:
 10 7
1 2
1 3
3 4
3 5
6 7
8 9
8 10
Number of Connected Components are : 3

*/
