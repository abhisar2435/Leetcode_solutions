class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        long long total=0;
        for(int i:nums) total+=i;
        long long target =total-x;
        if(target <0) return -1;
        if (target==0) return n;
        int l=0;
        long long sum=0,maxlen=-1;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>target && l<=r){
                sum-=nums[l];
                l++;
            }
            if(sum==target){
                maxlen=max(maxlen,(long long)r-l+1);
            }  
        } 
        if(maxlen==-1) return -1;
        return n-maxlen;


    }
};