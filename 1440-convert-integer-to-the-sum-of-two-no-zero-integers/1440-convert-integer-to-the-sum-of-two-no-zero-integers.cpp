#include <vector>
#include <string>

class Solution {
public:
    bool hasZero(int num) {
        string s = to_string(num);
        for (char c : s) {
            if (c == '0') {
                return true;
            }
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            if (!hasZero(a) && !hasZero(b)) {
                return {a, b};
            }
        }
        return {}; 
    }
};