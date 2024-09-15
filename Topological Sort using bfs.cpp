#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000],res;
int mp[10000];
void bfs(int n)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==0)q.push(i);
    }
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        res.push_back(cur);
        for(auto child:v[cur])
        {
            mp[child]--;
            if(mp[child]==0)q.push(child);
        }
    }
    cout<<"Topological Sort : ";
    for(auto x:res)cout<<x<<" ";
    cout<<endl;
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
        mp[y]++;
    }
    bfs(n);
}
/*

5 4

1 2
2 3
1 3
1 5
Topological Sort : 1 4 2 5 3
*/
/*
///If topological sort Exits or not

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v[n+1],mp(n+5,0),res;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        mp[y]++;
    }
    //sort()
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=1; i<=n; i++)
    {
        if(mp[i]==0)q.push(i);
    }
    while(!q.empty())
    {
        int cur=q.top();
        q.pop();
        res.push_back(cur);
        for(auto x:v[cur])
        {
            mp[x]--;
            if(mp[x]==0)q.push(x);
        }
    }
    if(res.size()==n)
    {
        //cout<<"YES"<<endl;
    for(int i=0; i<n; i++)
        cout<<res[i]<<" ";
    cout<<endl;
    }
    else cout<<"Sandro fails."<<endl;
}


*/
