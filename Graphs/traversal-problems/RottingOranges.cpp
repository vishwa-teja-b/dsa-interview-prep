#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         // T R B L
        vector<int> dx = {0 , +1, 0, -1};
        vector<int> dy = {+1, 0, -1, 0};

        int m = grid.size(); int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2) {
                    if(!visited[i][j]){
                        visited[i][j] = 1;
                        q.push({{i,j},0});
                    }
                }
            }
        }

        int min_time = 0;

        while(!q.empty()){
            auto curr = q.front(); q.pop();

            int row = curr.first.first;
            int col = curr.first.second;

            int time = curr.second;
            min_time = max(min_time, time);

            for(int i=0;i<4;i++){
                int nr = row + dx[i];
                int nc = col + dy[i];

                if(nr >= 0 && nr <m && nc>=0 && nc<n && !visited[nr][nc] && grid[nr][nc] == 1){
                    visited[nr][nc] = 1;
                    q.push({{nr,nc},time+1});
                }
            }
        }

        return min_time;
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
    cout<<sol->orangesRotting(grid)<<endl;
    delete sol;
}