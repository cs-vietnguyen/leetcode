/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (int i = 0; i < s.size(); i++) {
            switch (s[i])
            {
                case '(':
                    stack.push(s[i]);
                    break;
                case '[':
                    stack.push(s[i]);
                    break;
                case '{':
                    stack.push(s[i]);
                    break;
                case ')':
                    if (stack.empty() || stack.top() != '(') return false;
                    stack.pop();
                    break;
                case ']':
                    if (stack.empty() || stack.top() != '[') return false;
                    stack.pop();
                    break;
                case '}':
                    if (stack.empty() || stack.top() != '{') return false;
                    stack.pop();
                    break;
                
                default:
                    break;
            }
        }

        return stack.empty();
    }
};
// @lc code=end

