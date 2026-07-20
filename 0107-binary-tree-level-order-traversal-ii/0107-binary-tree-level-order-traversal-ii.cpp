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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return {};

        vector<vector<int>>ans;
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>level;
            while(n--){
                
                TreeNode* x=q.front();
                q.pop();
                if(x!=nullptr) level.push_back(x->val);
                if(x->left!=nullptr) q.push(x->left);
                if(x->right!=nullptr) q.push(x->right);
            }
            ans.push_back(level);

        }
        vector<vector<int>>res;
        int n=ans.size();
        for(int i=n-1;i>=0;i--){
            res.push_back(ans[i]);
        }

        return res;
    }
};