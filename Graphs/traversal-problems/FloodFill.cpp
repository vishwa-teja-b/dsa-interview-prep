#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target = image[sr][sc];
        image[sr][sc] = color;
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> visited(m, vector<int>(n,0));

        queue<pair<int,int>> q;

        q.push({sr,sc});


        int d_x[] = {0, 1, 0, -1};
        int d_y[] = {1,0,-1,0};

        while(!q.empty()){
            auto current = q.front(); q.pop();

            int row = current.first;
            int col = current.second;

            for(int i=0;i<4;i++){
                int new_row = row + d_x[i];
                int new_col = col + d_y[i];

                if(new_row >= 0 && new_row < m && new_col >=0 && new_col<n && !visited[new_row][new_col] && image[new_row][new_col] == target){
                    visited[new_row][new_col] = 1;

                    image[new_row][new_col] = color;

                    q.push({new_row,new_col});
                }
            }
        }

        return image;
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

    int sr, sc, color;

    cout<<"ENTER sr, sc, color values : "<<endl;

    cin>>sr>>sc>>color;

    Solution* sol = new Solution();
    // cout<<sol->minTicksToBreach(grid)<<endl;
    delete sol;
}