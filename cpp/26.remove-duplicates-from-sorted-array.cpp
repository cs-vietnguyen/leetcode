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
        for (auto x : nums) setNums.insert(x);
        copy(setNums.begin(), setNums.end(), nums.begin());

        return setNums.size();
    }
};
// @lc code=end

