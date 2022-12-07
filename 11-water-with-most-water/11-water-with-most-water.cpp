class Solution {
public:
    int maxArea(vector<int>& height) { // comments based on first input: [1,8,6,2,5,4,8,3,7]
        int first = 0;
        int last = height.size() - 1;
        int maxArea = 0;
        if (height.size() <= 1) return 0;
        while (first < last) {
            maxArea = max(maxArea, min(height[first], height[last])*(last-first)); // update the current area
            if(height[first] > height[last]) last--;
            else first++;
        }
        return maxArea;
        return 0;
    }
};

/*############################## Step by step #################################*/
/*

height              |   maxArea   |   last    |   first   |    height.size()     
[1,8,6,2,5,4,8,3,7]        0            8           0                9
=>                         8            8           1               =>
=>                        49            7           1               =>
=>                        49            6           1               =>
=>                        49            6           2               =>
=>                        49            6           3               =>
=>                        49            6           4               =>
=>                        49            6           5               =>
=>                        49            6           6               =>

first > last == false so while loop terminates
49 is returned

*/