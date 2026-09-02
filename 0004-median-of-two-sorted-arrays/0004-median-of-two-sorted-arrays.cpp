class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<int>temp;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]< nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            }
            else {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1) {
            temp.push_back(nums1[i]);
            i++;
        }
        while(j<n2){
            temp.push_back(nums2[j]);
            j++;
        }

        int x=n1+n2;
        if((x) & 1) return (double)temp[(x)/2];
        else {
            return (double) ((temp[x/2 -1] + temp[(x)/2 ])/2.0);
        }

    }
};