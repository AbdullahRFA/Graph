#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int inf=1e9+10;

vector<pair<int,int>>v[N];
vector<int>lev(N,inf);
int n,m;

int bfs()
{
    deque<int>q;
    q.push_back(1);
    lev[1]=0;
    while(!q.empty())
    {
        int fr=q.front();
        q.pop_front();
        for(auto &x:v[fr] )
        {
            int x_v=x.first;
            int wt=x.second;
            if(lev[fr]+wt<lev[x_v])
            {
                lev[x_v]=lev[fr]+wt;
                if(wt==1)
                {
                    q.push_back(x_v);
                }
                else
                {
                    q.push_front(x_v);
                }
            }
        }
    }
    return lev[n]==inf ? -1:lev[n];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)continue;
        v[x].push_back({y,0});
        v[y].push_back({x,1});
    }
   cout<< bfs()<<endl;
}
