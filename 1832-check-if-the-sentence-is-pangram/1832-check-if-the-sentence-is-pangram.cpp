class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>cnt(26);
        for(char c:sentence){
            cnt[c-'a']++;
        }
        if(count(cnt.begin(),cnt.end(),0)==0)return true;
        else return false;
    }
};