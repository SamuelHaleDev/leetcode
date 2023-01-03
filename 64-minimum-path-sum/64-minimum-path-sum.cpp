class Solution {
    public: 
    
    int minPathSum(vector<vector<int>> grid) {
        for (int i = grid.size() - 1; i >= 0; i--) {    // Outer loop for the row elements
            for (int j = grid[0].size() - 1; j >= 0; j--) { // Inner loop for the column elements
                if(i == grid.size() - 1 && j != grid[0].size() - 1) // Checking for when j is out of starting point
                    grid[i][j] = grid[i][j] +  grid[i][j + 1];  // If so it initializes current element to be its value + previous value
                else if(j == grid[0].size() - 1 && i != grid.size() - 1)    // Checking for when i is out of starting point
                    grid[i][j] = grid[i][j] + grid[i + 1][j];   // If so it initializes current element to be its value + previous value
                else if(j != grid[0].size() - 1 && i != grid.size() - 1)    // Checking for when i and j have shifted from starting point
                    grid[i][j] = grid[i][j] + min(grid[i + 1][j],grid[i][j + 1]);   // If so it initializes current element to the current value + the minimum between the downward or the rightward element essentially checking what the minimum way is. 
            }
        }
        return grid[0][0];  // After algorithm completes the 0, 0 starting point will be initialized to the minimum sum path.
    }
};