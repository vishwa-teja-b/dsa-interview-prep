#include <bits/stdc++.h>

using namespace std;

/**
 * There are n cities. Some of them are connected, while some are not.
 * If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
    
 A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
 */

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();

        vector<bool> visited(n);

        for(int vertex=0;vertex<n;vertex++){
            if(!visited[vertex]){
                visited[vertex] = true;

                dfs(vertex, isConnected, visited);
                count++;
            }
        }

        return count;
    }

    void dfs(int vertex, vector<vector<int>> & adjMatrix, vector<bool> &visited){

        int n = adjMatrix.size();

        for(int i=0;i<n;i++){
            if(!visited[i] && i!=vertex && adjMatrix[vertex][i] == 1){
                visited[i] = true;

                dfs(i,adjMatrix,visited);
            }
        }
    }
};

int main(){
    int n;
    cout<<"ENTER NUMBER OF NODES : "<<endl;
    cin>>n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout<<"FILL ADJACENCY MATRIX : "<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    Solution* sol = new Solution();

    int res = sol->findCircleNum(graph);

    cout<<res<<endl;
}