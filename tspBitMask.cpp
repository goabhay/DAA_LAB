#include<bits/stdc++.h>
using namespace std;



int  dfs(vector<pair<int,int>>adj[],int curr_node,int mask,int start,int v){

    if(mask==(1<<v)-1){                    // if 2^v-1==mask means all nodes are visited
        for(auto x:adj[curr_node]){        // if last node is linked with the staring node (for the sake of cycle)
            if(x.first==start){
               return x.second;
                
            }
        }
        return 1e5;
    }

    
int ans=INT_MAX;
    for(auto x:adj[curr_node]){

        if((mask&(1<<x.first))==0){           
          int new_mask=mask|(1<<x.first);
            ans=min(ans,dfs(adj,x.first,new_mask,start,v)+x.second);
          
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
int mask=1;   // node 0 is visited     eg.-> if 0th node is the starting node and in-total we have 4 cities then 
int curr_pos =0;       
int start=curr_pos;                            // mask will be like 0001  i.e mask=1  , (i.e mask<<0)
                                        // if 2nd city is startind node then mask=1 , mask<<1  it will given 0010
int res=dfs(adj,curr_pos,mask,start,v);

    cout<<res;


}