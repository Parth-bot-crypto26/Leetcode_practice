#include <iostream>
#include <numeric>

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 60; ++k) {
            long long x = num1 - k * num2;
            if (x < 0) {
                return -1;
            }
            if (x >= k) {
                int set_bits = 0;
                long long temp = x;
                while (temp > 0) {
                    set_bits += (temp & 1);
                    temp >>= 1;
                }
                
                if (set_bits <= k) {
                    return k;
                }
            }
        }
        return -1;
    }
};