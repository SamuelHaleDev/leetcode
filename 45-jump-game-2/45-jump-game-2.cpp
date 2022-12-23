class Solution {
public:
    int jump(vector<int>& nums) {
        int currEnd = 0, currFarthest = 0, result = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            currFarthest = std::max(currFarthest, i + nums[i]);
            if(i == currEnd) {
                result++;
                currEnd = currFarthest;
            }
        }
        return result;

    }
};