/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            hash_table[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            auto item = hash_table.find(target - nums[i]);

            if (item != hash_table.end() && item->second != i) {
                result.push_back(i);
                result.push_back(item->second);
                
                return result;
            }
        }

        return nums;
    }
};
// @lc code=end

