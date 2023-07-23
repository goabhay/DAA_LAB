#include<bits/stdc++.h>
using namespace std;

class DisjointSet{

    vector<int>parent;
    vector<int>rank;
    vector<int>size;

    public:

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);

        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findPar(int node){

        if(node==parent[node]) return node;

        return parent[node]=findPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        
        if(ulp_u==ulp_v) return;
        
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        
        else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }
        
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }


    void unionBySize(int u,int v){

        int ulp_u=findPar(u);
        int ulp_v=findPar(v);  

        if(ulp_v==ulp_u) return ;

        if(size[ulp_v]>size[ulp_u]){
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
        else{
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }

    }
  
    
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        
        vector<pair<int,pair<int,int>>>edges;
        
        
        
        for(int i=0;i<v;i++){
            for(auto x:adj[i]){
                
                int from=i;
                int to=x[0];
                int wt=x[1];
                
                edges.push_back({wt,{from,to}});
            }
        }
        
        sort(edges.begin(),edges.end());
        DisjointSet d(v);
        int sum=0;
        
        // for(int i=0;i<v;i++){                    can't use this because we are entering  the edges not the vertex.
            
        //     int wt=edges[i].first;
        //     int from=edges[i].second.first;
        //     int to=edges[i].second.second;
            
        //     if(d.findPar(from)!=d.findPar(to)){
        //         sum+=wt;
        //         d.unionByRank(from,to);
        //     }
            
        // }
        
        
        for(auto x:edges){
            
            int wt=x.first;
            int from=x.second.first;
            int to=x.second.second;
            
            if(d.findPar(from)!=d.findPar(to)){
                sum+=wt;
                d.unionBySize(from,to);
            }
        }
        return sum;
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

       
        Solution obj;
        int ans = obj.spanningTree(vertex,adj);

        cout<<" Cost of min. spanning tree "<<ans;

    

}