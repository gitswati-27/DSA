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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> m;
        m[0] = 1;
        return counter(root, 0, targetSum, m);
    }

    int counter(TreeNode* root, long long currSum, int target, unordered_map<long long, int>& m){
        if(root==nullptr) return 0;
        currSum += root->val;

        int count = m[currSum - target];
        m[currSum]++;

        count += counter(root->left, currSum, target, m);
        count += counter(root->right, currSum, target, m);

        m[currSum]--;

        return count;
    }
};