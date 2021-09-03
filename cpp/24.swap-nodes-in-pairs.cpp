/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapNodes(ListNode* &head) {
        ListNode *tempNode = head->next->next, *result = head->next;
        head->next->next = head;
        head->next = tempNode;

        return result;
    }


    ListNode* swapPairs(ListNode* head) {
        int count = 0;
        ListNode *previousNode, *result = head;

        while (head) {
            if (head->next) {
                ListNode *tempNode = swapNodes(head);
                if (!count) result = tempNode, previousNode = tempNode->next;
                else {
                    previousNode->next = tempNode;
                    previousNode = tempNode->next;
                }
                head = tempNode->next->next;
            }
            else head = head->next;
            count++;
        }

        return result;
    }
};
// @lc code=end

