class Solution {
public:
    int multi(int n){
        int ans=1;
        map<int,int>mp;
        for(int i=2;i<=n;i++){
            int cnt=0;
            while(n%i==0){
                n/=i;cnt++;
            }
            if(cnt>0) mp[i]=cnt;

        }
        for(auto i:mp){
            if(i.second &1) ans*=i.first;
        }
        return ans;
    }
    long long maximumSum(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>>mp;

        for(int i=1;i<=n;i++){
            int temp=multi(i);
            mp[temp].push_back(nums[i-1]);    
        }
        long long ans=0;
        for(auto i:mp){
            long long temp=accumulate(i.second.begin(),i.second.end(),0LL);
            ans=max(ans,temp);
        }
        return ans;
    }
};