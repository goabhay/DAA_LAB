#include<bits/stdc++.h>
using namespace std;

int tsp(vector<pair<int,int>> adj[], int v, int start, int city, int mask,vector<vector<int>>&memo) {
    if (mask == (1 << v) - 1) {        //  1<<v means 2^v-1   
        for (auto x : adj[city]) {
            if (x.first == start) {
                return x.second;
            }
        }
        return 1e5;
    }

    if(memo[city][mask]!=-1) return memo[city][mask];      // if already visited then no need to process again

    int ans = 1e5;

    for (auto x : adj[city]) {
        if ((mask & (1 << x.first)) == 0) {                    
            int new_mask = mask | (1 << x.first);           // checking the bit correspoding to the city no. (x.first)
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
    for (int i = 0; i < e; i++) {        // length of this code can be reduced by implementing it via adj matirx
        int from, to, wt;
        cin >> from >> to >> wt;
        adj[from].push_back({to, wt});
        adj[to].push_back({from, wt});
    }

vector<vector<int>>memo(v,vector<int>(1<<v,-1));
    int start = 0;     // if want to change the strting position then (let say 'x') then set start=x , city=x
    int city = 0;               
    int mask = 1 << city;  // by this step we are shifting 1 by city no. of places and rest of the position 
                                            // will get fill with 0 auotmatically.

    int res = tsp(adj, v, start, city, mask,memo);
    cout << res;

    return 0;
}

