/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divideNeg(int dividend, int divisor) {
        if (dividend > divisor) return 0;

        int cnt = 1, d = divisor;
        while (dividend - d <= d) {
            d += d;
            cnt += cnt;
        }
        return cnt + divideNeg(dividend - d, divisor);
    }

    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        if (dividend > 0 && divisor > 0) return divideNeg(-dividend, -divisor);
        if (dividend > 0) return -divideNeg(-dividend, divisor);
        if (divisor > 0) return -divideNeg(dividend, -divisor);
        return divideNeg(dividend, divisor);
    }
};
// @lc code=end

