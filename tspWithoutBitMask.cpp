#include<bits/stdc++.h>
using namespace std;



int  dfs(vector<pair<int,int>>adj[],int curr_node,vector<int>visit,int start,int v){

    if(visit.size()==v){
        for(auto x:adj[curr_node]){        // if last node is linked with the staring node (for the sake of cycle)
            if(x.first==start){
               return x.second;
                
            }
        }
        return 1e5;
    }

    
int ans=INT_MAX;
    for(auto x:adj[curr_node]){

        if(find(visit.begin(),visit.end(),x.first)==visit.end()){
            visit.push_back(x.first);
            ans=min(ans,dfs(adj,x.first,visit,start,v)+x.second);
            visit.pop_back();
        }
    }

    return ans;
    

}


int main(){

    int e,v;
    cout<<"Enter the no. of edges and vertex\n";
    cin>>e>>v;

    vector<pair<int,int>>adj[v];

    cout<<"Enter the connected components along with the weights\n";
    for(int i=0;i<e;i++){
        int from,to,wt;
        cin>>from>>to>>wt;                        // graph creation (adjacency list)
        adj[from].push_back({to,wt});
        adj[to].push_back({from,wt});
    }

vector<int>visit;
visit.push_back(0);
    int res=dfs(adj,0,visit,0,v);

    cout<<res;


}