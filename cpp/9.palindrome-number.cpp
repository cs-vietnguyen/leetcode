/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int result = 0, temp = x;
        
        while(temp) {
            if (result > INT_MAX / 10) return false;
            result = result * 10 + temp % 10;
            temp /= 10;
        }


        return result == x ? true : false;
    }
};
// @lc code=end

