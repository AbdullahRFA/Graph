#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int vis[10000];
bool dfs(int n)
{
    vis[n]=1;
    for(auto x:v[n])
    {
        if(vis[x]==0)
        {
            if(dfs(x)==true)return true;
        }
        else
        {
            if(vis[x]==1)return true;
        }
    }
    vis[n]=2;
    return false;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    bool res=dfs(1);
    if(res)cout<<"Cycle found"<<endl;
    else cout<<"Cycle not found"<<endl;
}
/*
4
1 2
1 3
2 4
3 4
Cycle not found

4
1 2
2 3
3 4
4 1
Cycle found
*/
