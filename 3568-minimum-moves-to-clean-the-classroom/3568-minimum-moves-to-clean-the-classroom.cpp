class Solution {
public:
    int minMoves(vector<string>& a, int energy) {
        int n = a.size(), m = a[0].size(), id = 0, res = 0;
        
        vector<vector<int>> h(n, vector<int>(m, -1));
        bool vis[21][21][51][1 << 10] = {};

        queue<tuple<int, int, int, int>> q;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(a[i][j] == 'S') {
                    q.push({i, j, energy, 0});
                    vis[i][j][energy][0] = 1;
                }

                if(a[i][j] == 'L')
                    h[i][j] = id++;
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [i, j, e, msk] = q.front();
                q.pop();

                if(msk == (1 << id) - 1)
                    return res;

                if(e == 0 && a[i][j] != 'R')
                    continue;

                if(a[i][j] == 'R')
                    e = energy;

                for(int d = 0; d < 4; ++d) {
                    int ni = i + dx[d], nj = j + dy[d];

                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] != 'X') {
                        int ne = e - 1;
                        
                        if(ne < 0)
                            continue;

                        int nmsk = msk;

                        if(a[ni][nj] == 'L')
                            nmsk |= (1 << h[ni][nj]);

                        if(a[ni][nj] == 'R')
                            ne = energy;

                        if(!vis[ni][nj][ne][nmsk]) {
                            vis[ni][nj][ne][nmsk] = 1;
                            q.push({ni, nj, ne, nmsk});
                        }
                    }
                }
            }

            ++res;
        }

        return -1;
    }
};