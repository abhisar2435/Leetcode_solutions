class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack<int>st;
        int cnt=0,i=0,c=0;
        while(i<n && s[i] !='('){i++;cnt++;}
        for(int j=i;j<n;j++){
            if(s[j]=='(') c++;
            else{
                if(c>0) c--;
                else cnt++;
            }
        }
        cnt+=c;
        return cnt;
    }
};