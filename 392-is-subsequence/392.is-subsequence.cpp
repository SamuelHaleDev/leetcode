                                    // Author: Samuel Hale
                                    // Creation Date: 12/3/2022
                                    // Purpose: Algorithm to check if a string
                                    // subset s is in t
// #include <iostream>
// #include <string>

// using namespace std;

/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    //Utility helper to populate ary's sequences and occurrences
    int* populate(int ary[], string x, bool isSeq) {
        for (int i = 0; i < x.size(); i++) {
            if (isSeq) ary[x[i]] = i+1;
            else ary[x[i]]++;
        }
        return ary;
    }            
    bool isSubsequence(string s, string t) {
        int *sSeq = new int[256];
        int *tSeq = new int[256]; // Initializes an Ascii Seqgram *256 valid Ascii Chars*
        int *sHisto = new int[256];
        int *tHisto = new int[256];
        // if (s.size() > t.size()) return false;
        // for (int i = 0; i < t.size(); i++) {    // O(n)
        //         if (i < s.size()) sSeq[s[i]] = i + 1;
        //         tSeq[t[i]] = i + 1;   // Populate the Seqgrams
        // }
        sSeq = populate(sSeq, s, true);
        sHisto = populate(sHisto, s, false);
        tSeq = populate(tSeq, t, true);
        tHisto = populate(tHisto, t, false); // Populate the sequences and occurrences of t and s
        for (int i = 0; i < s.size(); i++) { // O(n)
            if (sSeq[s[i]] > tSeq[s[i]]) return false;
            if (i == s.size()-1) break;  // the ordering of sSeq from its last recorded element to a non recorded element is not relevant so break                                             
            if (sSeq[s[i]] < sSeq[s[i+1]] && tSeq[s[i]] > tSeq[s[i+1]]) return false;
            if (sSeq[s[i]] > sSeq[s[i+1]] && tSeq[s[i]] < tSeq[s[i+1]]) return false;   // of a character in s is <= to that char in t
            if (sHisto[s[i]] != tHisto[s[i]]) return false;
        }
        return true;   // If false not ticked return true
    }
};

// int main() {
//     Solution *Sub = new Solution;
//     (*Sub).isSubsequence("abc", "ahbgdc");
// }
// @lc code=end
