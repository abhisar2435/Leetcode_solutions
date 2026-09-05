class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        vector<int>suffmin(n),prefmax(n);
        suffmin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffmin[i]= min(suffmin[i+1],nums[i]);
        }
        prefmax[0]=nums[0];
        for(int i=1;i<n;i++){
            prefmax[i]=max(prefmax[i-1],nums[i]);
        }

        for(int i=0;i<n;i++){
            if(prefmax[i]-suffmin[i]<=k) {ans=i; break;}
        }

        return ans;
    }
};