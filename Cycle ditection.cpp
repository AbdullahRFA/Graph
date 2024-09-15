#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int vis[10000];
bool dfs(int n,int par)
{
    vis[n]=1;
    for(auto x:v[n])
    {
        if(vis[x]==0)
        {
            if(dfs(x,n)==true)return true;
        }
        else
        {
            if(x!=par)return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bool res=dfs(1,-1);
    if(res)cout<<"Cycle found "<<endl;
    else cout<<"Cycle not found "<<endl;
}
/*
    4
1 2
2 3
2 4
4 5
Cycle not found

5
1 2
2 3
2 4
3 4
4 5
Cycle found


*/
