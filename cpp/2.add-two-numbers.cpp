/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode;
        ListNode* handle_node = result;
        int temp, temp2, exc = 0;
        
        while(1) {
            temp = temp2 = 0;

            if (l1) {
                handle_node->val += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                handle_node->val += l2->val;
                l2 = l2->next;
            }

            handle_node->val += exc;
            exc = handle_node->val / 10;
            handle_node->val %= 10;

            if (!l1 && !l2) {
                if (exc) {
                    handle_node->next = new ListNode;
                    handle_node->next->val = exc;
                }
                return result;
            }

            handle_node->next = new ListNode;
            handle_node = handle_node->next;

        }

        return result;
    }
};
// @lc code=end

