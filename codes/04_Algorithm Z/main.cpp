#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s == "")
            return s;
        int len = s.length();
        string r = s;
        reverse(r.begin(), r.end());
        int z[2 * len + 5];
        memset(z, 0, sizeof z);
        string x = s + "$" + r;
        int L, R;
        int xsize = 2 * len + 1;
        L = R = 0;
        for (int i = 0; i < xsize; i++) {
            if (i > R) {
                L = R = i;
                while (R < xsize && x[R] == x[R - L])
                    R++;
                z[i] = R - L;
                R--;
            } else {
                int k = i - L;
                if (z[k] < R - i + 1)
                    z[i] = z[k];
                else {
                    L = i;
                    while (R < xsize && x[R] == x[R - L])
                        R++;
                    z[i] = R - L;
                    R--;
                }
            }
            if (i > len && i + z[i] == xsize) // found answer
                return x.substr(len + 1, i - len - 1) + s;
        }
        return "";
    }
};

int main() {
    Solution solution;

    string s = "aacecaaa";
    string result = solution.shortestPalindrome(s);
    cout << "Input: " << s << endl;
    cout << "Output: " << result << endl;

    s = "abcd";
    result = solution.shortestPalindrome(s);
    cout << "Input: " << s << endl;
    cout << "Output: " << result << endl;

    return 0;
}
