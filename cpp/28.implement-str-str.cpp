/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    void preprocessing(vector<int> &prefix, string &needle) {
        int range = prefix.size(), headCursor = 0, index = 1;

        while(index < range) {
            if (needle[headCursor] == needle[index]) {
                prefix[index++] = ++headCursor;
            } 
            else {
                if (headCursor) {
                    headCursor = prefix[headCursor - 1];
                } 
                else {
                    prefix[index++] = headCursor;
                }
            }
        }
    }

    int kmp(vector<int> &prefix, string &haystack, string &needle) {
        int range = haystack.size(), headCursor = 0, index = 0, needleLimit = needle.size() - 1;

        while(index < range) {
            if (haystack[index] == needle[headCursor]) {
                if (headCursor == needleLimit) return index - needleLimit;
                index++, headCursor++;
            } 
            else {
                if (headCursor) {
                    headCursor = prefix[headCursor - 1];
                } 
                else {
                    index++;
                }
            }
        }

        return -1;
    }

    int strStr(string haystack, string needle) {
        if (!needle.size()) return 0;
        if (!haystack.size()) return -1;

        vector<int> prefix(needle.size());
        preprocessing(prefix, needle);

        return kmp(prefix, haystack, needle);
    }
};
// @lc code=end

