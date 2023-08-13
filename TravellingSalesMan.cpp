#include<bits/stdc++.h>
using namespace std;

int tsp(vector<pair<int,int>> adj[], int v, int start, int city, int mask,vector<vector<int>>&memo) {
    if (mask == (1 << v) - 1) {
        for (auto x : adj[city]) {
            if (x.first == start) {
                return x.second;
            }
        }
        return 1e5;
    }

    if(memo[city][mask]!=-1) return memo[city][mask];

    int ans = 1e5;

    for (auto x : adj[city]) {
        if ((mask & (1 << x.first)) == 0) {
            int new_mask = mask | (1 << x.first);
            ans = min(ans, tsp(adj, v, start, x.first, new_mask,memo) + x.second);
        }
    }

    memo[city][mask]=ans;
    return ans;
}

int main() {
    int e, v;
    cout << "Enter the number of edges and vertices: ";
    cin >> e >> v;

    vector<pair<int,int>> adj[v];

    cout << "Enter the connected components along with the weights:\n";
    for (int i = 0; i < e; i++) {
        int from, to, wt;
        cin >> from >> to >> wt;
        adj[from].push_back({to, wt});
        adj[to].push_back({from, wt});
    }

vector<vector<int>>memo(v,vector<int>(1<<v-1,-1));
    int start = 1;
    int city = 1;
    int mask = 1 << city;

    int res = tsp(adj, v, start, city, mask,memo);
    cout << res;

    return 0;
}

