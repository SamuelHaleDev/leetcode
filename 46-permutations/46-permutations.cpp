#include <iostream>
#include <vector>

using namespace std;

//Purpose: Recursively calculate all permutations given a vector of integers
void permuteRecursive(vector<int>& num, int l, vector<vector<int>>& result) {
    if (l >= num.size()) {
        result.push_back(num);
        return;
    }
    for (int i = l; i < num.size(); i++) {
        swap(num[l], num[i]); // swap
        permuteRecursive(num, l + 1, result); // increment begin to fix the left index in the next recursive call
        swap(num[l], num[i]); // backtracks through recursive calls and switches the first and last & first and second of the rest of the results after the first i to ensure correct results
    }
}

//Purpose: To calculate all permutations given a vector of integers
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permuteRecursive(nums, 0, result);
    return result;
}

//Drives: the permutation function
int main() {
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> permutations;
    permutations = permute(nums);
    for (int i = 0; i < permutations.size(); i++) {
        cout << endl;
        for (int j = 0; j < permutations[i].size(); j++) {
            cout << permutations[i][j] << ", ";
        }
    }
    return 0;
}