class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(curr == destination) return true;
            for(int neigh: adj[curr]){
                if(!visited[neigh]){
                     visited[neigh] = true;
                     q.push(neigh);
                }
            }
        }
        return false;
    }
};