class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<int> col(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][i] = matrix[j][i];
                col[i] = max(col[i], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[j][i] == -1) {
                    ans[j][i] = col[i];
                }
            }
        }
        return ans;
    }
};