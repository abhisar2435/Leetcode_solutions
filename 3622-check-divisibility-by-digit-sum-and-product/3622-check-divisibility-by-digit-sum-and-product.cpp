class Solution {
public:
    bool checkDivisibility(int n) {
        vector<int>digits;
        int temp=n;
        while(n>0){
            int r= n%10;
            digits.push_back(r);
            n/=10;
        }
        int sum=accumulate(digits.begin(),digits.end(),0);
        int prod=1;
        for(int i=0;i<digits.size();i++){
            prod*=digits[i];
        }
        return (temp % (sum+prod)==0 ?true:false);
    }
}; 