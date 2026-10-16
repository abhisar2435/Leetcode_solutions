class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    // Apply an increment d to every value in [l, r].
    void apply(int node, int l, int r, long long d) {
        long long len = r - l + 1;
        long long oldSum = tree[node].sum;

        tree[node].sq = (
            tree[node].sq
            + 2LL * d % MOD * oldSum
            + d * d % MOD * len
        ) % MOD;

        tree[node].sum = (
            oldSum + d * len
        ) % MOD;

        tree[node].lazy = (tree[node].lazy + d) % MOD;
    }

    // Push a pending increment to the children.
    void push(int node, int l, int r) {
        long long d = tree[node].lazy;

        if (d == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;

        apply(node * 2, l, mid, d);
        apply(node * 2 + 1, mid + 1, r, d);

        tree[node].lazy = 0;
    }

    // Increment every value in [ql, qr] by exactly 1.
    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum = (
            tree[node * 2].sum +
            tree[node * 2 + 1].sum
        ) % MOD;

        tree[node].sq = (
            tree[node * 2].sq +
            tree[node * 2 + 1].sq
        ) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        unordered_map<int, int> last;
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int p = -1;

            if (last.count(nums[r]))
                p = last[nums[r]];

            update(1, 0, n - 1, p + 1, r);

            ans = (ans + tree[1].sq) % MOD;

            last[nums[r]] = r;
        }

        return ans;
    }
};