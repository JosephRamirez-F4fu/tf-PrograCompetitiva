#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Solution {
    map<char, vector<char>> keys;
public:
    Solution() {
        keys = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
    }
    void combine(vector<string>& combinations, string& digits, int k, string prefix) {
        if (k < digits.length()) {
            if ('2' <= digits[k] && digits[k] <= '9')
                for (size_t i = 0; i < keys[digits[k]].size(); i++)
                    combine(combinations, digits, k + 1, prefix + keys[digits[k]].at(i));
        }
        else {
            combinations.push_back(prefix);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (0 < digits.length() && digits.length() <= 4) {
            combine(combinations, digits, 0, "");
        }
        return combinations;
    }
};
