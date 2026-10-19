// LeetCode 25: Reverse Nodes in k-Group
// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Pattern: // Pattern: Bounded Lookahead (kicker) -> Isolated Segment Reversal -> Inter-Group Tail Stitching
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head->next == nullptr){
            return head;
        }
        ListNode dummy;
        dummy.next = head;
        ListNode * prevGrpTail = &dummy;
        while(true){
            ListNode * kicker = prevGrpTail;
            for (int i =0;i<k && kicker!=nullptr;i++){
                kicker = kicker->next;
            }
            if (kicker==nullptr){
                break;
            }
            ListNode * grpStart = prevGrpTail->next;
            ListNode * nextGrpHead = kicker->next;

            ListNode * curr = grpStart;
            ListNode * prev = nextGrpHead;
            for (int i = 0; i < k; i++) {
                ListNode * next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            prevGrpTail->next = prev;
            prevGrpTail = grpStart;
        }
        return dummy.next;
    }
};