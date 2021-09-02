/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode *one, ListNode *two) {
        if (!one) return two;
        if (!two) return one;
        if (one->val < two ->val) {
            one->next = merge(one->next, two);
            return one;
        }
        else {
            two->next = merge(one, two->next);
            return two;
        }
    }

    ListNode* handler(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        int mid = left - (left - right) / 2;
        return merge(handler(lists, left, mid), handler(lists, mid + 1, right));
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return nullptr;
        else if (lists.size() == 1) return lists[0];

        return handler(lists, 0, lists.size() - 1);
    }
};
// @lc code=end

