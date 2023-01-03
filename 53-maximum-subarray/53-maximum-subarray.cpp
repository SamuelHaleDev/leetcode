class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize our variables using the first element.
        int currentSubarray = nums[0];
        int maxSubarray = nums[0];
        
        // Start with the 2nd element since we already used the first one.
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            // If current_subarray is negative, throw it away. Otherwise, keep adding to it.
            currentSubarray = max(num, currentSubarray + num);  // This currentSubArray = max(num, currentSubarray+num) will filter out negative current sums
            maxSubarray = max(maxSubarray, currentSubarray);    // This will figure the max out between the current max and the current subarray sum
        }
        
        return maxSubarray;
    

    }
};