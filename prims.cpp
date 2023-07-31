#include<bits/stdc++.h>
using namespace std;

void prims(vector<vector<int>>adj[],int start,int v){

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    pq.push({0,-1,start});   // wt,from,to  (since start node won't have any prev node so -1)


vector<pair<int,int>>edges;

    vector<int>visit(v,0);  // unvisited

    while(!pq.empty()){

        auto p=pq.top();   // p is a vector now
        pq.pop();
        int wt=p[0];
        int from=p[1];
        int to=p[2];

        if(visit[to]==1) continue;

        visit[to]=1;
        edges.push_back({from,to});

        for(auto x:adj[to]){     // x is a  vector now
            if(visit[x[0]]==0){
                pq.push({x[1],to,x[0]});
            }
        }

    }


    // printing the edges of MST

    for(auto x:edges){
        if(x.first==-1) continue;
        cout<<x.first<<"-"<<x.second<<endl;
    }
}



int main(){

   
   cout<<"Enter no. of vertex and edges\n";
        int vertex,edges;
        cin>>vertex>>edges;

        vector<vector<int>>adj[vertex+1];

        int i=0;
cout<<"Enter connected component of graph\n";

        for(int i=0;i<edges;i++){
            int from,to,weight;

            cin>>from>>to>>weight;
            vector<int>t1,t2;
            t1.push_back(to);
            t1.push_back(weight);

            adj[from].push_back(t1);

        }

       cout<<" Edges to be considered in minimum spanning tree are\n";
       
         prims(adj,0,vertex);  // let say we are starting with vertex 0
return 0;
}
