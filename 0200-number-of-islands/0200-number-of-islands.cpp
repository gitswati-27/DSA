class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    cnt++;
                    dfs(i,j,visited,grid);
                }
            }
        }
        return cnt;
    }

    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(row>=m || row<0 || col>=n || col<0 || grid[row][col]=='0' || visited[row][col]) return;

        visited[row][col] = 1;
        dfs(row-1,col,visited,grid);
        dfs(row+1,col,visited,grid);
        dfs(row,col-1,visited,grid);
        dfs(row,col+1,visited,grid);
    }
};