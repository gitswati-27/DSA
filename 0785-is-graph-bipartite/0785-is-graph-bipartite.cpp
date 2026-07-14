class Solution {
private:
    bool dfs(const vector<vector<int>>& graph, vector<int>& color,
        int curr, int currColor) {
        for (int neighbor : graph[curr]) {
            if (color[neighbor] == -1) {

                color[neighbor] = 1 - currColor;

                if (!dfs(graph, color, neighbor, 1 - currColor))
                    return false;
            }
            else if (color[neighbor] == currColor) {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {
                color[i] = 0;

                if (!dfs(graph, color, i, 0))
                    return false;
            }
        }

        return true;
    }
};