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
    void recursive_pre(vector<int>& ans, TreeNode* root){
        if(root==nullptr) return;
        ans.push_back(root->val);
        recursive_pre(ans,root->left);
        recursive_pre(ans,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        recursive_pre(ans, root);
        return ans;
    }
};