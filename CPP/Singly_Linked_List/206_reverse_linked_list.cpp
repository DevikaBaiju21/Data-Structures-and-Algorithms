// LeetCode 206: Reverse Linked List
// Link: https://leetcode.com/problems/reverse-linked-list/
// Pattern: Reversal (iterative, 4-step pointer flip)
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;   
        while (curr != nullptr) {
            ListNode* next = curr->next;    
            curr->next = prev;    
            prev = curr;         
            curr = next;          
        }
        return prev;            
    }
};