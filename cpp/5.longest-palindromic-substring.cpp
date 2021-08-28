/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool> > checkMap(s.size(), vector<bool> (s.size(), false));
        pair<int, int> coordinateResult = make_pair(0, 0);

        for (int i = 0; i < s.size() - 1; i++) 
            checkMap[i][i] = checkMap[i + 1][i + 1] = checkMap[i][i + 1] = checkMap[i + 1][i] = true;

        for (int i = 2; i <= s.size(); i++) {
            for (int j = 0; j + i <= s.size(); j++) {
                if (s[j] == s[j + i - 1] && checkMap[j + 1][j + i - 2]) {
                    checkMap[j][j + i - 1] = checkMap[j + i - 1][j] = true;
                    coordinateResult = make_pair(j, j + i - 1);
                }
                else {
                    checkMap[j][j + i - 1] = checkMap[j + i - 1][j] = false;
                }
            }
        }

        return s.substr(coordinateResult.first, coordinateResult.second - coordinateResult.first + 1);
    }
};
// @lc code=end

