#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100]; // Adjacency list representation of the graph
int start_time[100], finish_time[100];
int timer = 1;

void dfs(int node) {
    start_time[node] = timer++;

    for (int neighbor : adj[node]) {
        if (start_time[neighbor] == -1) {
            dfs(neighbor);
        }
    }

    finish_time[node] = timer++;
}

int main() {
    int n, e;
    cin >> n >> e; // Number of nodes and edges

    // Clearing data structures
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        start_time[i] = -1;
        finish_time[i] = -1;
    }

    // Input edges
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        //adj[y].push_back(x); // Assuming undirected graph
    }

    // Perform DFS on each unvisited node
    for (int i = 0; i <=n; i++) {
        if (start_time[i] == -1) {
            dfs(i);
        }
    }

    // Output start and finish times
    cout << "Node\tStart Time\tFinish Time" << endl;
    for (int i = 0; i <= n; i++) {
        cout << i << "\t" << start_time[i] << "\t\t" << finish_time[i] << endl;
    }

    return 0;
}

/*
8 10
0 1
1 2
2 3
3 0
2 4
4 5
5 6
6 4
7 6
7 8

*/
