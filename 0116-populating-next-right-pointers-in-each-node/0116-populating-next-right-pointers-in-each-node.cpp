/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<vector<Node*>> levelOrder(Node* root) {
        if(root==nullptr) return {};

        vector<vector<Node*>>ans;
        queue<Node*>q;

        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<Node*>level;
            while(n--){
                
                Node* x=q.front();
                q.pop();
                if(x!=nullptr) level.push_back(x);
                if(x->left!=nullptr) q.push(x->left);
                if(x->right!=nullptr) q.push(x->right);
            }
            ans.push_back(level);

        }
        return ans;
    }

    Node* connect(Node* root) {
        vector<vector<Node*>> x=levelOrder(root);
        for(int i=0;i<x.size();i++){
            for(int q=0;q<x[i].size()-1;q++){
                x[i][q]->next=x[i][q+1];
            }
        }

        return root;

    }
};