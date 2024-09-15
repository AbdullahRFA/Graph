#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int vis[10000],dis[10000];
int mx=-1;
int nod;
void dfs(int n,int d)
{
    vis[n]=1;
    dis[n]=d;
    if(dis[n]>mx)
    {
        mx=dis[n];
        nod=n;
    }
    for(auto x: v[n])
    {
        if(vis[x]==0)dfs(x,dis[n]+1);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    cout<<"Distance from source 1 to "<<nod<<" -> "<<mx<<endl;;
   // cout<<mx<<"  "<<nod<<endl;
    mx=-1;
     cout<<"Diameter of thr graph is from node "<<nod<<" to ";
    for(int i=1;i<=n;i++)vis[i]=0;
    dfs(nod,0);
    cout<<nod<<" is "<<mx<<endl;

}
/*
9 8
1 2
2 4
2 5
4 8
1 3
3 6
3 7
7 9
Distance from source 1 to 8 -> 3
Diameter of thr graph is from node 8 to 9 is 6
*/
