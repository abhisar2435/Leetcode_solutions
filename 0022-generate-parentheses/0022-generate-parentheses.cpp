class Solution {
public:
    void dfs(vector<string >&ans,string curr, int open ,int close,int n){
        if (open==n && close==n){
            ans.push_back(curr);
            return ;
        }
        if(open<n){
            dfs(ans, curr+"(",open+1, close, n);
        }
        if(close< open){
            dfs(ans, curr+")", open, close+1, n);
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr="";
        int open =0,close=0;
        dfs(ans, curr,open ,close,n);

        return ans;

    }
};