#include <vector>
#include <algorithm>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        
        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        
        // Fill remaining array positions with zeros
        for (int i = lastNonZeroFoundAt; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};