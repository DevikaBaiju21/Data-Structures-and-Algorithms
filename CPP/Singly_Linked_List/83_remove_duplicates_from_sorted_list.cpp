// LeetCode 83: Remove Duplicates from Sorted List
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Pattern: Single pointer, bypass duplicate neighbors (no dummy needed)
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * curr = head;
        while(curr!=nullptr && curr->next != nullptr){
            if (curr->val==curr->next->val){
                ListNode * next = curr->next->next;
                delete curr->next;
                curr->next = next;
                continue;
            }
            curr = curr->next;
        }
        return head;
    }
};