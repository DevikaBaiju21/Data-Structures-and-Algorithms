// LeetCode 203: Remove Linked List Elements
// Link: https://leetcode.com/problems/remove-linked-list-elements/
// Pattern: Dummy node + prev/curr (head may be removed)
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy;
        dummy.next = head;
        ListNode * curr = head;
        ListNode * prev = &dummy;
        while(curr!=nullptr){
            ListNode * next = curr->next;
            if(curr->val == val){
                prev->next = next;
                delete curr;
                curr = next;
                
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};