// LeetCode 19: Remove Nth Node From End of List
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Pattern: Two pointers with a gap + dummy node
// Time: O(n)   Space: O(1)

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
        ListNode dummy;
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode * fast = head;
        for (int i = 0;i<n;i++){
            fast = fast->next;
        }
        while(fast!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode * next = slow->next->next;
        delete slow->next;
        slow->next = next;
        return dummy.next;
    }
};