#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
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
    for(int i=1; i<=n; i++)
    {
        if(in[i]==0)
            dfs(i);
    }
    cout<<"\nNode\tInTime and OutTime: \n";
    for(int i=1; i<=n; i++)
    {
        cout<<i<<"\t   "<<in[i]<<"\t      "<<out[i]<<endl;
    }
}
/*
7 6
1 2
1 3
2 4
2 5
3 6
3 7
Node    InTime and OutTime:
1                   1          14
2                    2          7
3                    8          13
4                    3          4
5                    5          6
6                     9          10
7                     11         12


*/
