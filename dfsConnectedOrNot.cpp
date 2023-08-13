#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],vector<int>&visit,int start){

    stack<int>st;
    st.push(start);
    visit[start]=1;

    while(!st.empty()){

        auto p=st.top();
        st.pop();
        cout<<p<<" ";

        for(auto x:adj[p]){
            if(visit[x]==0){
                visit[x]=1;
                st.push(x);
            }
        }
    }
}


int main(){

    int e,v;
    cout<<"Enter the no. of edges and vertex\n";
    cin>>e>>v;

    vector<int>adj[v];

    cout<<"Enter the connected components along with the weights\n";
    for(int i=0;i<e;i++){
        int from,to;
        cin>>from>>to;                        // graph creation (adjacency list)
        adj[from].push_back(to);
        adj[to].push_back(from);
        
    }
int start=0;
int cnt=0;
vector<int>visit(v,0);
for(int i=0;i<v;i++){

    if(visit[i]==0){
        cnt++;
        dfs(adj,visit,i);
    }
}

if(cnt>1) cout<<endl<<"Graph is not connected "<<endl;
else cout<<"Graph is connected";

return 0;

}