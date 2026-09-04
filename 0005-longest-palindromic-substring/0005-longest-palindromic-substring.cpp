class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        if(n<=1) return s;
        for(int i=0;i<n;i++){
            string temp="";
            int x=i,y=i;
            while(x>=0 && y<n && s[x]==s[y]){
                x--;y++;
            }
            temp=s.substr(x+1, y-x-1);
            if(temp.size()>ans.size()) ans=temp;
            x=i,y=i+1;
            while(x>=0 && y<n && s[x]==s[y]){
                x--;y++;
            }
            temp=s.substr(x+1, y-x-1);
            if(temp.size()>ans.size()) ans=temp;
        }
        return ans;
    }
};