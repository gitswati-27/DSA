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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        //vector<vector<int>> ans;
        if(root==nullptr) return -1;
        q.push(root);
        int lastsum;
        while(!q.empty()){
            int size = q.size();
           // vector<int> level;
            int sum = 0; 
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                //level.push_back(node->val);
                sum += node->val;
            }
            lastsum = sum;
            //ans.push_back(level);
        }
        // int sum = 0;
        // for(int n : ans.back()) sum += n;
        return lastsum;
    }
};