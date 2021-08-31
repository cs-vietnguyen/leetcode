/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *nodeOne = head, *nodeTwo = head;
        
        while(nodeOne && n--) {
            nodeOne = nodeOne->next;
        }

        if (!nodeOne) {
            head = nodeTwo->next;
            delete nodeOne;
            return head;
        }

        while(nodeOne && nodeOne->next) {
            nodeOne = nodeOne->next;
            nodeTwo = nodeTwo->next;
        }

        nodeOne = nodeTwo->next;
        nodeTwo->next = nodeTwo->next->next;
        delete nodeOne;

        return head;
    }
};
// @lc code=end

