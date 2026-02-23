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
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==nullptr) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        int finmin = INT_MAX;
        for(int i=0;i<ans.size()-1;i++){
            int diff = ans[i+1] - ans[i];
            finmin = min(finmin, diff);
        }
        return finmin;
    }
};