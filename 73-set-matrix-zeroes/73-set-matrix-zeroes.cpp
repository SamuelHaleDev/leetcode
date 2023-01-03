class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<tuple<int, int>> stack;
        // Iterate over matrix
        // Push i, jth ints to a stack where element = 0
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    stack.push_back(make_tuple(i, j));  // Gets position of our zeroes stored
                }
            }
        }
        // Pop each i, jth int from stack 
        for (tuple<int, int> x: stack) {
            int posI = get<0>(x);
            int posJ = get<1>(x);
            for (int j = posJ; j < matrix[0].size(); j++) { // Gets right values
                matrix[posI][j] = 0;
            }
            for (int j = posJ; j >= 0; j--) {    // Gets left values
                matrix[posI][j] = 0;
            }
            for (int i = posI; i < matrix.size(); i++) {    // Gets up values
                matrix[i][posJ] = 0;
            }
            for (int i = posI; i >= 0; i--) {    // Gets down values
                matrix[i][posJ] = 0;
            }
        }
        // Starting from there loop right until you hit size
        // loop left until you hit 0
        // loop up until you hit 0
        // loop down until you hit 0
    }
};