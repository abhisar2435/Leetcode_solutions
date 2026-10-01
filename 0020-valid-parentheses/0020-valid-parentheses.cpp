class Solution {
public:
    bool isValid(string s) {
        vector<char>st;
        for(char ch: s){
            if(ch=='(' || ch=='[' || ch=='{') st.push_back(ch);
            else {
                if(st.empty()) return false;
            
            if((ch==')' && st.back()!='(')  || (ch==']' && st.back()!='[')  || (ch=='}' &&st.back()!='{' ))return false;
            st.pop_back();
            }
            
        }
        return st.empty();
    }
}; 