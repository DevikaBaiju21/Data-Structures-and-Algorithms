// LeetCode 142: Linked List Cycle II
// Link: https://leetcode.com/problems/linked-list-cycle-ii/
// Pattern: Floyd's Tortoise & Hare -> Intersection Point -> Equal Speed Walk to Entrance
// Time: O(n)   Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool hasCycle = false;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!= nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle){
            return nullptr;
        }

        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};