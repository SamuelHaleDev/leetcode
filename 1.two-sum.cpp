/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> targetIndices(2);
        int search = 0;
        int num1;
        int num2;
        vector<int> usnums = nums;
        sort(nums.begin(), nums.end()); // O(nlogn)
        int maximum = nums.size()-1;
        int minimum = 0;
        int mean;
        for (int i = 0; i < nums.size(); i++) { // O(n)
            num1 = nums[i];
            search = target - nums[i]; // find the number that when added with nums[i] gives you target
            while(maximum>minimum) {    // binary search O(logn)
                mean = (maximum+minimum)/2;
                if(nums[mean] == search) {
                    num2 = nums[mean];
                    break;
                }
                else if(nums[mean] > search) maximum=(mean-1);
                else minimum=(mean+1);
            }
            if(nums[mean] == search) break;
        }
        for(int i=0; i < usnums.size(); i++) {
            if (usnums[i] == num1) targetIndices[0] = i;
            else if (usnums[i] == num2) targetIndices[1] = i;
        }
        return targetIndices;
    }
};

// @lc code=end

