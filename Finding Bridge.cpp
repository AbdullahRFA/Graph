#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int vis[10000],in[10000],low[10000];
int timer;
void dfs(int n,int par)
{
    vis[n]=timer;
    low[n]=timer;
   timer++;
   for(auto x:v[n])
   {
       if(x==par)continue;
       if (vis[x]==1)
       {
           low[n]=min(low[n],low[x]);
       }
       else
       {
           dfs(x,n);
           if(low[n]<low[x])
           {
               cout<<"\nBridge Found between  "<<n<<"   "<<x<<endl;
           }
           low[n]=min(low[n],low[x]);
       }
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
    dfs(1,-1);
}
/*
jekono duiti noder moddhe theke eadge delete korar fole connected component er poriman briddhi pai taile
oi dui noder majhe bridge biddaman

intput:
4 4
output:
1 2
2 3
2 4
3 4

Bridge Found between  1   2

*/
