#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> calculateLPS(string pattern) {
        int patternLength = pattern.length();
        vector<int> lps(patternLength, 0);

        int len = 0;
        int i = 1;
        while (i < patternLength) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        int haystackLength = haystack.length();
        int needleLength = needle.length();

        if (needleLength == 0) {
            return 0;
        }

        vector<int> lps = calculateLPS(needle);

        int i = 0;  // Index for haystack
        int j = 0;  // Index for needle

        while (i < haystackLength) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == needleLength) {
                    return i - j;
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
};

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";
    int result = Solution().strStr(haystack, needle);
    cout << "Input: haystack = \"" << haystack << "\", needle = \"" << needle << "\"" << endl;
    cout << "Output: " << result << endl;

    haystack = "leetcode";
    needle = "leeto";
    result = Solution().strStr(haystack, needle);
    cout << "Input: haystack = \"" << haystack << "\", needle = \"" << needle << "\"" << endl;
    cout << "Output: " << result << endl;

    return 0;
}

