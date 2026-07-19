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
    bool solve(TreeNode* root, long long low,long long high){
        if(root== nullptr) return true;
        if(root->val <=low || root->val >=high) return false;
        return (solve (root->left, low, root->val) && solve(root->right, root->val, high));


    }
    bool isValidBST(TreeNode* root) {
        long long low=LLONG_MIN,high=LLONG_MAX;

        return solve(root,low,high);
    }
};
