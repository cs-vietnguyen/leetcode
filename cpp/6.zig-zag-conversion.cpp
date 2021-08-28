/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string result;

        if (numRows == 1) return s;

        for (int i = 0; i < numRows; i++) {
            if (!i || i == numRows - 1) {
                for (int j = i; j < s.size(); j += numRows * 2 - 2) {
                    result.push_back(s[j]);
                }
            }
            else {
                int j = i;
                bool neg = true;
                while(1) {
                    if (j >= s.size()) break;
                    
                    result.push_back(s[j]);
                    if (neg) {
                        j += (numRows - i - 1) * 2;
                        neg = false;
                    }
                    else {
                        j += i * 2;
                        neg = true;
                    }
                    
                }
            }
        }

        return result;
    }
};
// @lc code=end

