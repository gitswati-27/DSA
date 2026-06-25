class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==m-1 || j==n-1 || i==0 || j==0)&& grid[i][j]==1 && vis[i][j]==-1){
                    bfs(grid, vis, i, j);
                }
                if(grid[i][j]==0) vis[i][j]=0;
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==-1) cnt++;
            }
        }

        return cnt;
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col){
        int rows = grid.size();
        int cols = grid[0].size();

        vis[row][col] = 0;

        queue<pair<int,int>> q;

        q.push({row, col});
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]==1 && vis[nr][nc]==-1){
                    vis[nr][nc] = 0;
                    q.push({nr,nc});
                }
            }
        }
    }
};