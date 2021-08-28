/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    void normalizer(string &s) {
        int pos = 0;

        for (auto x : s) {
            if (x == ' ') pos++;
            else break;
        }

        s.replace(0, pos, "");
    }

    bool valid(char c) {
        return c == '-' || c == '+' || (c >= '0' && c <= '9') ? true : false;
    }

    bool isNegative(char c) {
        return c == '-' ? true : false;
    }

    void removeSigned(string &s) {
        if (s[0] == '-' || s[0] == '+') s.replace(0, 1, "");
    }

    int convert(string &s) {
        int result = 0;
        bool negative = isNegative(s[0]);
        removeSigned(s);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] < '0' || s[i] > '9') return negative ? -result : result;
            if (result > 214748364) {
                return negative ? INT_MIN : INT_MAX;
            }
            else if (i == 9) {
                if (result == 214748364 && s[i] > '7') return negative ? INT_MIN : INT_MAX;
            }
            result = result * 10 + (s[i] - '0');
        }

        return negative ? -result : result;
    }

    int myAtoi(string s) {
        int result = 0;
        normalizer(s);
        if (!valid(s[0])) return 0;

        return convert(s);
    }
};
// @lc code=end

