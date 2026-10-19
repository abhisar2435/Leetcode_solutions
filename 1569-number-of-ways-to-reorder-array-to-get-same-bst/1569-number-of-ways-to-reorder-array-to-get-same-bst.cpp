class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> nCr;

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;
        int root = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long ways = nCr[n - 1][left.size()];

        ways = (ways * solve(left)) % MOD;
        ways = (ways * solve(right)) % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        nCr.assign(n, vector<long long>(n, 0));

        // Pascal's Triangle
        for (int i = 0; i < n; i++) {
            nCr[i][0] = nCr[i][i] = 1;

            for (int j = 1; j < i; j++) {
                nCr[i][j] =
                    (nCr[i - 1][j - 1] +
                     nCr[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};