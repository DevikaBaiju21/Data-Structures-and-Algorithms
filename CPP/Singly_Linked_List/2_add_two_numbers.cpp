// LeetCode 2: Add two numbers
// Link: https://leetcode.com/problems/add-two-numbers/
// Pattern: Dummy Head -> Pointer Co-Traversal + Carry Management
// Time: O(n)   Space: O(max(m,n))

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); 
        ListNode* l3 = dummyHead;             
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry != 0){
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10; 
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return dummyHead->next;
    }
};