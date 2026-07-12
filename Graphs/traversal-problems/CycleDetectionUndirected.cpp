#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList = convertToAdjList(V, edges);

        vector<int> visited(V,0);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                visited[i] = 1;
                if(dfs(i,-1,adjList,visited)) return true;
            }
        }
        
        return false;
    }

  private:
    bool dfs(int V,int parent, vector<vector<int>> &adjList, vector<int> &visited){
        
        // for(int node=0; node < adjList.size() ; node++){
        //     if(!visited[node]){
        //         visited[node] = 1;
                
        //         if(dfs(node, V, adjList, visited)) return true;
        //     }
        //     else if(visited[node] && parent != node) return true; 
        // }
        
        // for(adj_matrix[V])
        
        // for(int node : adjList[V]){
        //     if(!visited[node])
        // }
        
        for(int node : adjList[V]){
            if(!visited[node]){
                visited[node] = 1;
                
                if(dfs(node, V, adjList, visited)) return true;
            }
            
            else if(parent != node) return true;
        }
       
        return false;
    }

    vector<vector<int>> convertToAdjList(int V, vector<vector<int>> &edges){
        vector<vector<int>> adj(V);
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // remove this line if directed graph
        }
        return adj;
    }
};

int main(){
    int V;
    
    cout<<"ENTER NO OF VERTICES : "<<endl;

    cin>>V;

    cout<<"ENTER NO OF EDGES : "<<endl;

    int E;

    cin>>E;

    vector<vector<int>> edges;

    cout<<"ENTER EDGES : (u , v) "<<endl;

    for(int i=0; i<E;i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    Solution* sol = new Solution();

    // cout<< sol->findNumberOfComponent(V, edges)<<endl;
    cout<<sol->isCycle(V, edges)<<endl;

    delete sol;
}