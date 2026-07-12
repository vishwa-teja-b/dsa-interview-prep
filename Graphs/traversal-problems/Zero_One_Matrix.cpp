#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(m, vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(mat[i][j] == 0) {
                visited[i][j]=1;
                q.push({{i,j},0});}  
            }
        }

        
        vector<vector<int>> dist(m, vector<int>(n,0));

        int d_row[] = {0,1,0,-1};
        int d_col[] = {1,0,-1,0};

        while(!q.empty()){
            auto current = q.front(); q.pop();

            int row = current.first.first;
            int col = current.first.second;
            int steps = current.second;

            dist[row][col] = steps;

            for(int i=0;i<4;i++){
                int nr = row+d_row[i];
                int nc=  col+d_col[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc] == 0 && mat[nr][nc] == 1){
                    visited[nr][nc] = 1;

                    q.push({{nr,nc},steps+1});
                }
            }
        }

        return dist;
    }
};

int main(){
    int m, n;

    cout<<"ENTER M AND N : "<<endl;

    cin>>m>>n;

    vector<vector<int>> mat(m, vector<int>(n,0));

    cout<<"FILL THE GRID : "<<endl;

    for(int row=0;row<m;row++){
        for(int col=0;col<n;col++){
            cin>>mat[row][col];
        }
    }
}