/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for (int i = 0; i < len / 2; i++) {
            for (int j = i; j < len - i - 1; j++) {
                swap(matrix[i][j], matrix[j][len - i - 1]);
                swap(matrix[i][j], matrix[len - i - 1][len - j - 1]);
                swap(matrix[i][j], matrix[len - j - 1][i]);
            }
        }
    }
};
// @lc code=end

