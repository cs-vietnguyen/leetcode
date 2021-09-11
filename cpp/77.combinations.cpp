/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    void backtracking(vector<vector<int> > &result, vector<int> tempResult, int n, int k, int pos) {
        if (tempResult.size() == k) {
            result.push_back(tempResult);
            return;
        }

        for (int i = pos; i <= n; i++) {
            tempResult.push_back(i);
            backtracking(result, tempResult, n, k, i + 1);
            tempResult.pop_back();
        }
    }


    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> tempResult;
        backtracking(result, tempResult, n, k, 1);

        return result;
    }
};
// @lc code=end

