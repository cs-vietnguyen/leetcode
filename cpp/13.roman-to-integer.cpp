/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
    map<char, int> mapper = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
public:
    int romanToInt(string s) {
        int result = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i != s.size() - 1 && this->mapper[s[i]] < this->mapper[s[i + 1]]) {
                result += this->mapper[s[i + 1]] - this->mapper[s[i]];
                i++;
            }
            else {
                result += this->mapper[s[i]];    
            }
        }

        return result;
    }
};
// @lc code=end

