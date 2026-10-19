// LeetCode 92: Reverse Linked List II
// Link: https://leetcode.com/problems/reverse-linked-list-ii/
// Pattern: Anchor Boundaries via Dummy Node -> Advance to Segment Window -> Three-Pointer Sublist Reversal -> Stitch Sublist Back to Main Chain
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy;
        dummy.next = head;
        int i = 1;
        ListNode * curr = head;
        ListNode * next = curr->next;
        ListNode * prev = &dummy;
        while(i<left){
            prev = curr;
            curr = curr->next;
            i++;
        }
        ListNode * appendF = prev;
        ListNode* appendL = curr;
        curr = curr->next;
        prev = prev->next;
        i++;
        while (i<=right && curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        appendF->next = prev;
        appendL->next = curr;
        return dummy.next;
    }
};