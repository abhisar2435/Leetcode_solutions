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
set<string> seen;

string serialize(TreeNode* root){
    if(root == nullptr) return "#";
    return to_string(root->val) + "," +
           serialize(root->left) + "," +
           serialize(root->right);
}
    TreeNode* insert(TreeNode*root, int val){
        if(root==nullptr) return new TreeNode(val);
        if(val< root->val){
            root->left=insert(root->left,val);
        }
        else {
            root ->right =insert(root->right,val);
        }
        return root;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};

        vector<int>ans;
        vector<TreeNode*> res;

        for(int i=1;i<=n;i++) ans.push_back(i);
        do{
            TreeNode* x = new TreeNode(ans[0]);
            for(int i=1;i<n;i++) insert(x, ans[i]);
            
            string key = serialize(x);

            if(!seen.count(key)){
                seen.insert(key);
                res.push_back(x);
            }
        
        } while( next_permutation(ans.begin(),ans.end()));
        return res;
    }
};