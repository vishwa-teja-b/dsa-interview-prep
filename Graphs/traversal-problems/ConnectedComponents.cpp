#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> convertToAdjMatrixRepresentation(vector<vector<int>> &edges, int V){
    vector<vector<int>> adjMatrix(V, vector<int>(V,0));

    for(int i=0;i<edges.size();i++){
        adjMatrix[edges[i][0]][edges[i][1]] = 1;
        adjMatrix[edges[i][1]][edges[i][0]] = 1; 
    }

    return adjMatrix;
}

class Solution {
  public:
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adjMatrix = convertToAdjMatrixRepresentation(edges,V);

        vector<int> visited(V,0);

        int count = 0;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                visited[i] = 1;

                dfs(i,adjMatrix, visited);
                count++;
            }
        }

        return count;
    }

    void dfs(int vertex, vector<vector<int>> &adjMatrix, vector<int> &visited){

        int V = adjMatrix.size();

        for(int i=0;i<V;i++){
           if(!visited[i] && adjMatrix[vertex][i] == 1){
            visited[i] = 1;
            dfs(i, adjMatrix, visited);
           }
        }
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

    cout<< sol->findNumberOfComponent(V, edges)<<endl;
    delete sol;
}