/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *revert(ListNode *&head, int k, ListNode *&previousResultNode) {
        ListNode *lastNode = head, *tempNode = head;
        for (int i = 0; i < k; i++) {
            if (!tempNode) return nullptr;
            tempNode = tempNode->next;
        }
        ListNode *previousNode = nullptr;

        while(k--) {
            tempNode = head->next;
            head->next = previousNode;
            previousNode = head;
            head = tempNode;
        }
        lastNode->next = head;

        if (previousResultNode) {
            previousResultNode->next = previousNode;
        }
        previousResultNode = lastNode;

        return previousNode;
    } 


    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode *previousResultNode = nullptr;
        ListNode *result = revert(head, k, previousResultNode);

        while(revert(head, k, previousResultNode)) {}
        
        return result;
    }
};
// @lc code=end

