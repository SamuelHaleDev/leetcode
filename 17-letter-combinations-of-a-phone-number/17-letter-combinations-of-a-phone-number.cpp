class Solution {
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // Handles empty digits
		vector<string> result;
        result.push_back("");
        
        for(auto digit: digits) {   // iterates through digits with auto meaning it can be any data type
            vector<string> tmp; 
            for(auto candidate: pad[digit - '0']) { // 
                for(auto s: result) {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};