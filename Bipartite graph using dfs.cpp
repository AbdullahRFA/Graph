#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int vis[1000],col[1000];
bool dfs(int n,int c)
{
    vis[n]=1;
    col[n]=c;
    for(auto x:v[n])
    {
        if(vis[x]==0)
        {
            if(dfs(x,c^1)==false)return false;
        }
        else
        {
            if(col[x]==col[n])return false;
        }
    }return true;
}
int main()
{
    int n;
    cout<<"Enter the number of edge: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bool res= dfs(1,1);
    if(res)cout<<"Bipartite"<<endl;
    else cout<<"Not Bipartite"<<endl;
}
/*
Enter the number of edge:
4
1 2
1 4
2 3
3 4
Bipartite

Enter the number of edge:
3
1 2
2 3
3 1
Not Bipartite

*/
