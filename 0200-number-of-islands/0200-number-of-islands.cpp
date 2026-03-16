class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols,0));
        int cnt=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return cnt;
    }

    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow<rows && ncol >= 0 && ncol<cols && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }

            }
        }
    }
};