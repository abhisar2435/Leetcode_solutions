class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=haystack.size(), n=needle.size();
        if(n>h) return -1;
        for(int i=0;i<=h-n;i++){
            int j=0;
            while(j<n && haystack[i+j] ==needle[j]){j++;}
            if(j==n) return i;
        }
        return -1;
    }
};