/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int result = 0, count = 0;

        while(x) {
            if (count == 9 && (result > 214748364 || result < -214748364 || x % 10 < -8 || x % 10 > 7)) return 0;

            result = (result * 10) + (x % 10);
            x /= 10;
            count++;
        }

        return result;
    }
};
// @lc code=end

