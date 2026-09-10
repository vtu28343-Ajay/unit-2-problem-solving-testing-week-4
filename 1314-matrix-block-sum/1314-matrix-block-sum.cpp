class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        // Build 2D Prefix Sum Array (1-indexed for convenience)
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pref[i + 1][j + 1] = mat[i][j] 
                                  + pref[i][j + 1] 
                                  + pref[i + 1][j] 
                                  - pref[i][j];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));

        // Calculate sum for each block using inclusion-exclusion principle
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int r1 = max(0, i - k);
                int c1 = max(0, j - k);
                int r2 = min(m - 1, i + k);
                int c2 = min(n - 1, j + k);

                // Convert 0-indexed mat coordinates to 1-indexed pref coordinates
                ans[i][j] = pref[r2 + 1][c2 + 1] 
                          - pref[r1][c2 + 1] 
                          - pref[r2 + 1][c1] 
                          + pref[r1][c1];
            }
        }

        return ans;
    }
};