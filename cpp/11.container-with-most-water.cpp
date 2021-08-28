/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int height_start, height_end, result = 0;

        while (start < end) {
            height_start = height[start];
            height_end = height[end];

            result = max(result, min(height_start, height_end) * (end - start));

            if (height_start < height_end) {
                start++;
            }
            else {
                end--;
            }
        }

        return result;
    }
};
// @lc code=end

