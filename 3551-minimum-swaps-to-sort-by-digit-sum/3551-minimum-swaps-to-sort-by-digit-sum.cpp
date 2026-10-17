class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            int sum = 0;

            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            arr[i] = {sum, nums[i]};
        }

        vector<pair<int, int>> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[sorted[i].second] = i;
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || pos[arr[i].second] == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = 1;
                j = pos[arr[j].second];
                cycle++;
            }

            cnt += cycle - 1;
        }

        return cnt;
    }
};