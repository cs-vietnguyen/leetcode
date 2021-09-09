/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if (st.empty()) st.push(i);
                else {
                    result = max(result, i - st.top());
                }
            }
        }

        return result;
    }
};
// @lc code=end

