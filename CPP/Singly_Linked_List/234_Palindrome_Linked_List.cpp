// LeetCode 234: Palindrome Linked List
// Link: https://leetcode.com/problems/palindrome-linked-list/
// Pattern: Two Pointers (Fast & Slow) -> Reverse Second Half -> Element-by-Element Comparison
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
    bool isPalindrome(ListNode* head) {

        //Empty Linked list (or) linked list with a single node
        if(head==nullptr || head->next == nullptr){
            return true;
        }

        //finding mid pointer
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reversing 2nd half of the list
        ListNode * mid = slow;
        ListNode * prev = nullptr;
        while(slow!=nullptr){
            ListNode * next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        //Comparing both half
        ListNode * start = head;
        while(prev!=nullptr){
            if (start->val!=prev->val){
                return false;
            }
            prev = prev->next;
            start = start->next;
        }
        return true;
    }
};