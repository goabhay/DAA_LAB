#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&adj,int start){

queue<int>q;
int v=adj.size();
vector<int>visit(v,0);
q.push(0);
visit[0]=1;

while(!q.empty()){

    int p=q.front();
    cout<<p<<" ";
    q.pop();

    for(int i=0;i<v;i++){
        if(visit[i]==0 && adj[p][i]==1){
            q.push(i);
            visit[i]=1;
        }
    }
}

}


void dfs(vector<vector<int>>&adj,int start,vector<int>&visit){    // dfs using recursion

cout<<start<<" ";

visit[start]=1;

for(int i=0;i<adj.size();i++){
    if(visit[i]==0 && adj[start][i]==1){
        dfs(adj,i,visit);
    }
}

}

int main(){

    int e,v;

    cout<<"Enter the no. of edeges and vertex\n";
    cin>>e>>v;

    vector<vector<int>>adj(v,vector<int>(v,0));
    cout<<"Enter the nodes which are connected\n";

    for(int i=0;i<e;i++){     // creating adjacency matrix
        int a,b;
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }

    vector<int>visit(e,0);  // 0->unvisited, 1->visited

    cout<<"DFS:-";
    dfs(adj,0,visit);
    cout<<endl;
    cout<<"BFS:-";
    bfs(adj,0);


}