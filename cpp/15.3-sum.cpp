/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        set<pair<int, int> > checkMap;
        int count = 0;
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

        for (int i = 0; i < tempArray.size(); i++) {
            unordered_map<int, int> hash_table;

            for (int j = i + 1; j < tempArray.size(); j++) {
                int sum = tempArray[i] + tempArray[j];
                auto check = hash_table.find(-sum);
                auto check1 = checkMap.find(make_pair(tempArray[i], tempArray[j]));

                if (check != hash_table.end() && check1 == checkMap.end()) {
                    int k = check->second;
                    vector<int> tempResult = {tempArray[i], tempArray[k], tempArray[j]};

                    if (checkMap.insert(make_pair(tempResult[0], tempResult[1])).second) {
                        result.push_back(tempResult);
                    }
                }
                
                if (hash_table.find(tempArray[j]) == hash_table.end()) hash_table[tempArray[j]] = j;
            }
        }
        return result;
    }
};
// @lc code=end
