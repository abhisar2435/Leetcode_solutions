class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mine=INT_MAX,mino=INT_MAX;
        for(int x:nums1){
            if(x&1) mino=min(mino,x);
            else mine=min(mine, x);
        }
        if(mino ==INT_MAX) return true;
        if( mine==INT_MAX) return true;

        return mine >mino;
    }
};