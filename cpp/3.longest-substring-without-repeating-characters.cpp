/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_table;
        vector<int> sums(s.size(), 1);
        int result = s.size() > 1 ? 0 : s.size();

        hash_table[s[0]] = 0;

        for (int i = 1; i < s.size(); i++) {
            auto item = hash_table.find(s[i]);

            if (item == hash_table.end()) {
                sums[i] = sums[i - 1] + 1;
            } else {
                if (sums[i - 1] >= i - item->second) sums[i] = i - item->second;
                else sums[i] = sums[i - 1] + 1;
            }
            hash_table[s[i]] = i;
            result = max(result, sums[i]);
        }

        return result;
    }
};
// @lc code=end

