/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = INT_MAX, count = 0;
        vector<int> tempArray;

        if (!nums.size()) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (count < 3) {
                tempArray.push_back(nums[i]);
            }
            if (nums[i] == nums[i + 1]) {
                count++;
            }
            else {
                count = 0;
            }
        }

        if (count < 3) tempArray.push_back(nums[nums.size() - 1]);
        int diff = INT_MAX;

        for (int i = 0; i < tempArray.size(); i++) {
            for (int j = tempArray.size() - 1; j > i; j--) {
                if (j - i == 1) break;
                int sum = tempArray[i] + tempArray[j];
                auto postion_low = lower_bound(tempArray.begin() + i + 1, tempArray.begin() + j - 1, target - sum) - tempArray.begin();
                auto postion_up = upper_bound(tempArray.begin() + i + 1, tempArray.begin() + j - 1, target - sum) - tempArray.begin();

                if (postion_low == postion_up && postion_low > i + 1) {
                    postion_low--;
                }

                int sum_low = sum + tempArray[postion_low];
                int sum_up = sum + tempArray[postion_up];
                int sum_result;

                if (abs(sum_low - target) < abs(sum_up - target)) {
                    sum_result = sum_low;
                }
                else {
                    sum_result = sum_up;
                }

                if (abs(sum_result - target) < diff) {
                    diff = abs(sum_result - target);
                    result = sum_result;
                }
            }
        }
        return result;
    }
};
// @lc code=end

