class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        if(n==1) return strs[0];
        int i=0,j=0;
        while(i<strs[0].size() && j<strs[1].size()){
            if(strs[0][i]==strs[1][j]){
                ans+=strs[0][i];
                i++;j++;
            }
            else break;

        }
        if(ans.empty()) return "";
        if(n==2) return ans;
        for(int p=2;p<n;p++){
            int q=0;
            while(q<ans.size() && q<strs[p].size()){
                if(ans[q]!=strs[p][q]) break;

                q++;
            }
            ans.resize(q);
            if(ans.empty()) return "";
        }
        return ans;

    }
};