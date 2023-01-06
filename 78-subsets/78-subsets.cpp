
class Solution {
private:
    void solve(vector<vector<int>>&ans,int i,vector<int>&v,vector<int>&nums){
        if(i>=nums.size()){ // Checking if current position is out of range
            ans.push_back(v);   // If it is push back current permutation
            return; // and return
        }
        
        v.push_back(nums[i]);   // Push back current value
        solve(ans,i+1,v,nums);  // Increment iterator and call function
        v.pop_back();   // pop the back of the vector
        solve(ans,i+1,v,nums);  // increment iterator again and recursively call 
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans; // 2D result vector
        vector<int>v;   // Temp vector
        solve(ans,0,v,nums);    // Calling recursive function
        return ans;
    }
};