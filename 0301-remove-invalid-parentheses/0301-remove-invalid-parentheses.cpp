class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int i, int leftRemove, int rightRemove,
             int open, string curr) {

        if (i == s.size()) {
            if (leftRemove == 0 &&
                rightRemove == 0 &&
                open == 0) {
                ans.insert(curr);
            }
            return;
        }

        char ch = s[i];

        // Letter
        if (ch != '(' && ch != ')') {
            dfs(s, i + 1, leftRemove, rightRemove,
                open, curr + ch);
            return;
        }

        // Remove current '('
        if (ch == '(' && leftRemove > 0) {
            dfs(s, i + 1,
                leftRemove - 1,
                rightRemove,
                open,
                curr);
        }

        // Remove current ')'
        if (ch == ')' && rightRemove > 0) {
            dfs(s, i + 1,
                leftRemove,
                rightRemove - 1,
                open,
                curr);
        }

        // Keep current '('
        if (ch == '(') {
            dfs(s, i + 1,
                leftRemove,
                rightRemove,
                open + 1,
                curr + '(');
        }

        // Keep current ')'
        else {
            if (open > 0) {
                dfs(s, i + 1,
                    leftRemove,
                    rightRemove,
                    open - 1,
                    curr + ')');
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Calculate minimum removals
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {

                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        dfs(s, 0,
            leftRemove,
            rightRemove,
            0,
            "");

        return vector<string>(ans.begin(), ans.end());
    }
};