// LeetCode 24: Swap Nodes in Pairs
// Link: https://leetcode.com/problems/swap-nodes-in-pairs/
// Pattern: // Pattern: Track Previous Pair's Tail -> Isolate 2-Node Window -> In-place Pointer Swapping & Re-stitching
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
    ListNode* swapPairs(ListNode* head) {
        // Base case: if the list has 0 or 1 node, no swapping needed
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* curr = head;
        ListNode* h1 = head->next; 
        ListNode* prevTail = nullptr; 

        while (curr != nullptr && curr->next != nullptr) {
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;        
            second->next = curr;
            curr->next = nextPair;
            if (prevTail != nullptr) {
                prevTail->next = second;
            }
            prevTail = curr;
            curr = nextPair;  
        }

        return h1;
    }
};
