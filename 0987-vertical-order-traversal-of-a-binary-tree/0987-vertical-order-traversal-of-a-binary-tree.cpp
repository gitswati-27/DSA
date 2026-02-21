/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        vector<tuple<int,int,int>> triples;
        while(!q.empty()){
            auto root = q.front();
            q.pop();
            TreeNode* node = root.first;
            int row = root.second.first;
            int col = root.second.second;
            triples.push_back({col,row,node->val});
            if(node->left) q.push({node->left, {row+1, col-1}});
            if(node->right) q.push({node->right, {row+1, col+1}});
        }
        sort(triples.begin(), triples.end());
        int prev = INT_MIN;
        for(auto t : triples)
        {
            int col = get<0>(t);
            int val = get<2>(t);
            if(col != prev)
            {
                ans.push_back({});
                prev = col;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};