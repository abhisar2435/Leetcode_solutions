class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);

        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        sort(diff.begin(), diff.end());

        long long total = 0;
        long long ans = 0;

        for(long long x : diff) {
            total += x;
            ans += x * x;
        }

        if(k >= total)
            return 0;

        for(int i = n - 1; i > 0 && k > 0; i--) {

            long long old = diff[i];
            long long newLevel = diff[i - 1];

            long long cnt = n - i;
            long long gap = old - newLevel;

            long long need = gap * cnt;

            if(k >= need) {

                // Lower all cnt elements from old to newLevel
                ans -= cnt * (old * old - newLevel * newLevel);

                k -= need;
            }
            else {

                // Lower all cnt elements equally by q
                long long q = k / cnt;
                long long r = k % cnt;

                long long level = old - q;

                ans -= cnt * (old * old - level * level);

                // r elements get one additional reduction
                ans -= r * (level * level - (level - 1) * (level - 1));

                k = 0;
            }
        }

        // All remaining elements are now at the same level
        if(k > 0) {

            long long level = diff[0];

            long long q = k / n;
            long long r = k % n;

            long long newLevel = level - q;

            ans -= n * (level * level - newLevel * newLevel);

            // r elements decrease one more time
            ans -= r * (newLevel * newLevel
                        - (newLevel - 1) * (newLevel - 1));
        }

        return ans;
    }
};