#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000],ans;
int vis[10000],in[10000],out[10000];
int t=1;
void dfs(int n)
{
    cout<<n<<" -> ";
    vis[n]=1;
    in[n]=t++;
    for(int x:v[n])
    {
        if(vis[x]==0)dfs(x);
    }
    out[n]=t++;
    ans.push_back(n);
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        //v[y].push_back(x);
    }
    cout<<"DFS :- ";
    for(int i=0; i<=n; i++)
    {
        if(in[i]==0)
            dfs(i);
    }
    cout<<"\nNode\tInTime and OutTime: \n";
    for(int i=0; i<=n; i++)
    {
        cout<<i<<"\t   "<<in[i]<<"\t      "<<out[i]<<endl;
    }
    cout<<"Topological Sort : ";
    reverse(ans.begin(),ans.end());
    for(auto x: ans)cout<<x<<" ";
    cout<<endl;
}
/*
6 6
6 3
6 1
4 1
4 2
3 4
4 2
DFS :- 1 -> 2 -> 3 -> 4 -> 5 -> 6 ->
Node    InTime and OutTime:
1          1          2
2          3          4
3          5          8
4          6          7
5          9          10
6          11         12
Topological Sort : 6 5 3 4 2 1
*/

