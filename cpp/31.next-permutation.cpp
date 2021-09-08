/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
    public:
        void nextPermutation(vector < int > & nums) {
            for (int i = nums.size() - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    sort(nums.begin() + i + 1, nums.end());
                    swap(nums[i], nums[upper_bound(nums.begin() + i + 1, nums.end(), nums[i]) - nums.begin()]);
                    return;
                }
            }

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            swap(nums[left], nums[right]);
            left++, right--;
        }
        }
};
// @lc code=end