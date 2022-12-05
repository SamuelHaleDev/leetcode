                                    //Author: Samuel Hale
                                    //Creation Date: 12/3/2022
/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int *sHisto = new int[256];
        int *tHisto = new int[256]; // Initializes an Ascii histogram *256 valid Ascii Chars*

        for (int i = 0; i < s.size(); i++) {
            if (sHisto[s[i]] != tHisto[t[i]]) return false; // goes to corresponding Ascii index and compares
            else {
                sHisto[s[i]] = i + 1;
                tHisto[t[i]] = i + 1;   // If the character has not occurred before *the else condition*
                                        // Note the occurrence of it with the index + 1
            }
        }
        return true;    // If program makes it through for loop return true since the false condition
                        // never gets set
    }
};
// @lc code=end
