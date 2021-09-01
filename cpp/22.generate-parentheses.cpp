/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    void backtracking(vector<string> &result, string &parentheses, int n, int open, int close) {
        if (parentheses.size() == n * 2) {
            result.push_back(parentheses);
            return;
        }

        if (open < n) {
            parentheses.push_back('(');
            backtracking(result, parentheses, n, open + 1, close);
            parentheses.pop_back();
        }
        if (close < open) {
            parentheses.push_back(')');
            backtracking(result, parentheses, n, open, close + 1);
            parentheses.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string parentheses = "";

        backtracking(result, parentheses, n, 0, 0);

        return result;
    }
};
// @lc code=end

