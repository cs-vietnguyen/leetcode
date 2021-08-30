/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> hash_table = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtracking(
        vector<string> &result,
        string digits,
        string letter, 
        int size, 
        int postion
    ) {
        if (!size) return;
        
        if (postion == size) {
            result.push_back(letter);
            return;
        }
        string pattern = this->hash_table[digits[postion] - '2'];

        for (int i = 0; i < pattern.size(); i++) {
            backtracking(result, digits, letter + pattern[i], size, postion + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;

        backtracking(result, digits, "", digits.size(), 0);

        return result;
    }
};
// @lc code=end

