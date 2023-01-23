#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> decipher;
        int i = 97; // start at ascii value for a
        string result;

        // lowercase ascii values are 97 -  122
        // Create a map where the keys are the characters from key 
        // Values are the english alphabet

        for (char x: key) { // Initalize map for deciphering
            // Sense for duplicate characters
            // Where no duplicate exists insert into map
            if (x != ' ' && decipher.find(x) == decipher.end()) {   // This means that the current character is not present in map
                decipher[x] = char(i);
                i++;
            }
        }

        for (char x: message) {
            if (x != ' ') {
                result.push_back(decipher[x]);
            } else result.push_back(' ');
        }

        return result;
    }
};

int main() {
    Solution x;
    string answer = x.decodeMessage("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv");
    cout << answer;
    return 0;
}