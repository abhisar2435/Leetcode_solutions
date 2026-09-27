class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int>st;
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int j=st.top();
                st.pop();
                reverse(s.begin()+j+1,s.begin()+i);

            }
        }
        for(char c:s){
            if (c!='(' && c!=')') {
                ans+=c;
            }
        }
        return ans;


    }
};