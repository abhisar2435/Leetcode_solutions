
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dist(2, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // type 0: rotations of original array
        // type 1: rotations of reversed array
        q.push({0, 0});
        dist[0][0] = 0;

        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());

        auto getShift = [&](vector<int>& a) {
            int i = 0;
            while (i < n && a[i] != 0) i++;

            if (i == n) return -1;

            int j = 0;
            while (j < n) {
                if (a[(i + j) % n] != j)
                    return -1;
                j++;
            }

            return i;
        };

        int target0 = getShift(nums);
        int target1 = getShift(rev);

        while (!q.empty()) {
            auto [type, shift] = q.front();
            q.pop();

            if ((type == 0 && shift == target0) ||
                (type == 1 && shift == target1))
                return dist[type][shift];

            // Rotate left by one
            int ns = (shift + 1) % n;

            if (dist[type][ns] == -1) {
                dist[type][ns] = dist[type][shift] + 1;
                q.push({type, ns});
            }

            // Reverse entire array
            int nt = 1 - type;
            ns = (n - shift) % n;

            if (dist[nt][ns] == -1) {
                dist[nt][ns] = dist[type][shift] + 1;
                q.push({nt, ns});
            }
        }

        return -1;
    }
};
