#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ara[n][n];
    vector<int>v[n+3],v1[n+3];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
           cin>>ara[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(ara[i][j]==1)
            {
                v1[i].push_back(j);
                //v1[j].push_back(i);
            }
        }
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i;
        for(auto x:v1[i])cout<<"->"<<x;
        cout<<endl;
    }
}

/*
5
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0

1->2->5
2->1->3->4->5
3->2->4
4->2->3->5
5->1->2->4

*/
