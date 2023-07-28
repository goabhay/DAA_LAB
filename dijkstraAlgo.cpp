#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>>adj[],int v,int start){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,start});
    vector<int>path(v,1e5);
    path[start]=0;

    while(!pq.empty()){

        auto p=pq.top();
        pq.pop();

        int node=p.second;
        int dis=p.first;

        for(auto x:adj[node]){

            if(dis+x[1]<path[x[0]]){
                path[x[0]]=dis+x[1];
                pq.push({path[x[0]],x[0]});
            }
        }
    }


    cout<<"Shortest path :\n";
for(int i=0;i<v;i++){
    cout<<start<<"-"<<i<<"-"<<path[i]<<endl;
}

}

int main(){

int e,v;
cout<<"Enter the no. of edges and vertex\n";
cin>>e>>v;
    vector<vector<int>>adj[v];

cout<<"Enter the connected component of graph\n";
    for(int i=0;i<e;i++){
        int from,to,wt;
        cin>>from>>to>>wt;
        adj[from].push_back({to,wt});
    }

    dijkstra(adj,v,0);
    
}