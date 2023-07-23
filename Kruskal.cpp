#include<bits/stdc++.h>
using namespace std;


class disjoint{
    vector<int>rank;
    vector<int>parent;
    public:
    disjoint(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);//works for both 0 and 1 based indexing 
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int find(int n){
        if(n==parent[n])return n;
       
         return parent[n]=find(parent[n]);
        
    }
    
    void unionbyrank(int a,int b){//it is a void functions
        int u=find(a);
        int v=find(b);
        if(u==v)return;//creating a cycle
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[v]>rank[u]){
            parent[u]=v;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
   
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    void spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int u=i;
                int v=it[0];
                int wt=it[1];
                
                edges.push_back({wt,{u,v}});
            }
        }
        
        vector<pair<int,int>>ans;

        sort(edges.begin(),edges.end());
        disjoint ds(V);
        int w=0;
        for(auto i:edges){
            int u=i.second.first;
            int v=i.second.second;
            int wt=i.first;
            if(ds.find(u)!=ds.find(v)){
                ds.unionbyrank(u,v);
                ans.push_back({u,v});
            }
        }
        
        for(auto x:ans){
            cout<<x.first<<"-"<<x.second<<endl;
        } 
        
    }
};

int main(){

   
   cout<<"Enter no. of vertex and edges\n";
        int vertex,edges;
        cin>>vertex>>edges;

        vector<vector<int>>adj[vertex+1];

        int i=0;
cout<<"Enter component of graph\n";

        while(i++ < edges){
            int from,to,weight;

            cin>>from>>to>>weight;
            vector<int>t1,t2;
            t1.push_back(to);
            t1.push_back(weight);

            adj[from].push_back(t1);

        }

       cout<<" Edges to be considered in minimum spanning tree are\n";
        Solution obj;
         obj.spanningTree(vertex,adj);
return 0;

}