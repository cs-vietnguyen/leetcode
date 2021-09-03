/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> setNums;
        vector<int> result(nums.size());
        int iter = 0;

        for (auto x : nums) setNums.insert(x);

        for (auto x : setNums) nums[iter++] = x;

        return setNums.size();
    }
};
// @lc code=end

