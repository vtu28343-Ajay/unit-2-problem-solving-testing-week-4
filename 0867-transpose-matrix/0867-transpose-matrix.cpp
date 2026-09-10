#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Create result matrix with swapped dimensions (n rows, m columns)
        std::vector<std::vector<int>> result(n, std::vector<int>(m));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                result[c][r] = matrix[r][c];
            }
        }
        
        return result;
    }
};