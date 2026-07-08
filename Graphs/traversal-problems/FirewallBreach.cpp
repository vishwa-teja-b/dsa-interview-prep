#include <bits/stdc++.h>

using namespace std;

/***
 * Problem Statement

You are given a grid grid of size n x m. Each cell has one of three states:


0 — Dead slot: no server is racked here (empty, inert — never gets infected, never spreads infection).
1 — Secure node: a healthy, uninfected server.
2 — Compromised node: an already-infected server, actively spreading the breach.


Every tick (unit of time), every compromised node infects all secure nodes among its 8 neighbors (horizontal, vertical, and both diagonals) — all infections happen simultaneously across the whole grid before the next tick begins.

Return the minimum number of ticks required until no secure node (1) remains in the grid.

If there exists at least one secure node that can never be reached by the breach (no matter how many ticks pass), return -1.
 */
class Solution{
  public:
    int minTicksToBreach(vector<vector<int>>& grid){

        int m = grid.size(); int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n,0));

        queue<pair<pair<int,int>,int>> q;

        int secure_nodes = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    if(!visited[i][j]){
                        visited[i][j] = 1;

                        q.push({{i,j},0});
                    }
                }

                else if(grid[i][j] == 1){
                    secure_nodes++;
                }
            }
        }


        int d_row[] = {0,1,1,1,0,-1,-1,-1};
        int d_col[] = {1,1,0,-1,-1,-1,0,1};

        int min_time = 0;

        while(!q.empty()){
            auto current = q.front(); q.pop();

            int row = current.first.first;
            int col = current.first.second;

            int time = current.second;

            min_time = max(min_time, time);

            for(int i=0;i<8;i++){
                int nr = row + d_row[i];
                int nc = col + d_col[i];

                if(nr >= 0 && nr<m && nc >=0 && nc < n && !visited[nr][nc] && grid[nr][nc] == 1){
                    visited[nr][nc] = 1;
                    secure_nodes--;
                    q.push({{nr,nc},time+1});
                }
            }
        }

        return secure_nodes == 0? min_time : -1;
    }
};

int main(){
    cout<<"ENTER m and n"<<endl;

    int m, n;
    cin>>m>>n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout<<"Fill the grid : "<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    Solution* sol = new Solution();
    cout<<sol->minTicksToBreach(grid)<<endl;
    delete sol;
}