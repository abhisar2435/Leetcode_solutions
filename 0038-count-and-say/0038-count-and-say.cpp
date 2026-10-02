class Solution {
public:
    string rle(string x){
        int n=x.size();
        int cnt=1;
        char temp=x[0];
        string ans="";
        if(n==1){
            ans+=to_string(cnt);
            ans+=temp;
            return ans;
        }
        for(int i=1;i<n;i++){
            if(x[i]==temp) cnt++;
            else {
                ans+=to_string(cnt);
                ans+=temp;
                temp=x[i];
                cnt=1;
            }
        }
        ans+=to_string(cnt);
        ans+=temp;
        
        return ans;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        else return rle(countAndSay(n-1));
    }
};