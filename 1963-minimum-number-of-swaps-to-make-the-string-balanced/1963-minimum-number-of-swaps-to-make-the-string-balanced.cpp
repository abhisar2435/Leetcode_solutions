class Solution {
public:
    int minSwaps(string s) {
        int bal=0, maxdef=0;
        for(char c:s){
            if(c=='[') bal++;
            else bal--;
            maxdef=max(maxdef,-bal);
        }
        return (maxdef+1)/2;
    }
};