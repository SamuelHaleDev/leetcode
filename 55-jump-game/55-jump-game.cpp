class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;    // Last position in the vector
        for (int i = nums.size() - 1; i >= 0; i--) {  // Start iterating from last element and go leftward
            if (i + nums[i] >= n) n = i;    
        }
        return n == 0;
    }
};