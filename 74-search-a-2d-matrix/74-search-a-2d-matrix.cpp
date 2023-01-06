class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int colSize = matrix[0].size(), rowSize = matrix.size(), hi = (colSize*rowSize) - 1, lo = 0, i = 0, j = 0;
        while (hi >= lo) {
            int mid = (lo+hi)/2;
            i = 0;
            j = mid;
            // Convert this to a row and column index
            while (j >= colSize) {
                j -= colSize;   // Keep taking away colSize until you find the correct column index
                i++;    // Everytime you can take away colSize from it indicates entering a new row
            }

            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};