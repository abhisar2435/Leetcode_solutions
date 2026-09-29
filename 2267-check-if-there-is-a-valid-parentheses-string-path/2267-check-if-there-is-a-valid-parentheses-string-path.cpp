class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool dfs(vector<vector<char>>& grid, int i, int j, int bal) {

        // Outside grid
        if (i >= m || j >= n)
            return false;

        // Process current cell
        if (grid[i][j] == '(')
            bal++;
        else
            bal--;

        // Too many closing brackets
        if (bal < 0)
            return false;

        // Not enough cells left to close all '('
        int remaining = (m - 1 - i) + (n - 1 - j);

        if (bal > remaining)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1)
            return bal == 0;

        // Already solved
        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        // Try down
        bool down = dfs(grid, i + 1, j, bal);

        // Try right
        bool right = dfs(grid, i, j + 1, bal);

        // Store result
        return dp[i][j][bal] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // Valid parentheses string must start with '('
        if (grid[0][0] != '(')
            return false;

        int maxbal = m + n;

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(maxbal + 1, -1)
            )
        );

        return dfs(grid, 0, 0, 0);
    }
};