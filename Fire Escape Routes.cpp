#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
vector<ll>v[100000+5];
ll vis[100005];
ll result=0;
void dfs(ll n)
{
    vis[n]=1;
    result++;
    for(auto x:v[n])
    {
        if(vis[x]==0)dfs(x);
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,e;
        cin>>n>>e;
        for(ll i=1;i<=n;i++)v[i].clear();
        memset(vis,0,sizeof(vis));
        while(e--)
        {
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        ll count=0,sum=1;
        for(ll i=1;i<=n;i++)
        {
            result=0;
            if(vis[i]==0)
            {
                count++;
                dfs(i);
                sum=((sum*result)%1000000007);
            }
        }
        cout<<count<<" "<<sum<<endl;

    }
}
/*

3

4 2
1 2
2 3

5 3
1 2
2 3
1 3

6 3
1 2
3 4
5 6

output
2 3
3 3
3 8
*/
