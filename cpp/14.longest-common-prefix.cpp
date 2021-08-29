/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < result.size(); j++) {
                // String has EOF symbol at last element
                if (strs[i][j] != result[j]) {
                    result = result.substr(0, j);
                    break;
                }
                if (result.empty()) return result;
            }
        }

        return result;
    }
};
// @lc code=end

