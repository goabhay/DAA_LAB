#include<bits/stdc++.h>
using namespace std;

void primsAlgo(vector<vector<int>>adj[],int start,int v){

int sum=0;
priority_queue<pair<int,pair<int,int>>>pq;
pq.push({0,{start,-1}});

vector<int>visit(v,0);
int wt=0;

while(!pq.empty()){

    auto p=pq.top();
    int wt=p.first;
    int node=p.second.first;
    if(visit[node]==1) continue;
    visit[node]=1;
    sum+=wt;

    for(auto x:adj[node]){
        if(visit[x[0]]==0){
            pq.push({x[1],{node,x[0]}});
        }
    }
}

cout<<sum<<" ";

}


int main(){

int e,v;
cout<<"Enter edges and vertex\n";
cin>>e>>v;

    vector<vector<int>>adj[v];

    cout<<"Enter the connected components of graph\n";
    for(int i=0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }
primsAlgo(adj,0,v);
    
}