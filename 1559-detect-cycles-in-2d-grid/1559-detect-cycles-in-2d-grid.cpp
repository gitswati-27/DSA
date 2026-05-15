class Solution {
public:
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j]) {
                    if(bfs(i, j, grid, vis))
                        return true;
                }
            }
        }

        return false;
    }

    bool bfs(int sr, int sc,
             vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, pair<int,int>>> q;

        q.push({{sr, sc}, {-1, -1}});
        vis[sr][sc] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            int r = node.first.first;
            int c = node.first.second;

            int pr = node.second.first;
            int pc = node.second.second;

            for(int k=0;k<4;k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m &&
                   grid[nr][nc] == grid[r][c]) {

                    if(!vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({{nr,nc}, {r,c}});
                    }
                    else if(!(nr == pr && nc == pc)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};