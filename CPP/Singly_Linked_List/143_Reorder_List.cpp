// LeetCode 143: Reorder List
// Link: https://leetcode.com/problems/reorder-list/
// Pattern: Find Midpoint (Slow/Fast) -> Split & Reverse Second Half -> In-Place Zipper Merge
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
    void reorderList(ListNode* head) {
        if (head->next==nullptr){
            return;
        }

        //Find middle 
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        //Disconnecting the first and second half of the linked list
        //Reversing the second half of the linked list
        ListNode * curr = slow->next;
        slow->next = nullptr;
        ListNode * prev = nullptr;
        while(curr!=nullptr){
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //Linking the first and second halves alternatively
        ListNode * first = head;
        ListNode * second = prev; //prev will be the head of the second half
        while(second!=nullptr){
            ListNode * tmp1 = first->next;
            ListNode * tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};