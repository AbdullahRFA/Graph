#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int vis[10000],sub_tree_size[10000];
int dfs(int n)
{
    vis[n]=1;
    int cnt=1;
    for(auto x:v[n])
    {
        if(vis[x]==0)
        {
            cnt+=dfs(x);
        }
    }
    sub_tree_size[n]=cnt;
    return cnt;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=1; i<=e; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for(int i=1; i<=n; i++)
    {
        cout<<"Subtree Size of "<<i<<" is "<<sub_tree_size[i]<<endl;
    }
}
/*
7 6
1 2
2 4
2 5
3 6
3 7
1 3
Subtree Size of 1 is 7
Subtree Size of 2 is 3
Subtree Size of 3 is 3
Subtree Size of 4 is 1
Subtree Size of 5 is 1
Subtree Size of 6 is 1
Subtree Size of 7 is 1
*/
