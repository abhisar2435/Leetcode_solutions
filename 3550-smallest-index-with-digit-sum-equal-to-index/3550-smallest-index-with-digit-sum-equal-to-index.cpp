class Solution {
public:
    int sumindex(int x){
        if(x<10 ) return x;
        int ans=0;
        while(x>0){
            ans+=(x%10);
            x/=10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sumindex(nums[i]) ==i) return i;
        }
        return -1;
    }
};