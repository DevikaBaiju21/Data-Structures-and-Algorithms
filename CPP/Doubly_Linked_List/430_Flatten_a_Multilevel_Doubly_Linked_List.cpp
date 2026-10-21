// LeetCode 430: Flatten a Multilevel Doubly Linked List
// Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Pattern: Splice each child list into the main chain; the walking pointer handles deeper levels
// Time: O(n)   Space: O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node * curr = head;
        while(curr!=nullptr){
            if(curr->child!=nullptr){
                Node * next = curr->next;
                Node * child = curr->child;
                Node * tail = child;
                while(tail->next!=nullptr){
                    tail = tail->next;
                }
                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
                tail->next = next;
                if(next!=nullptr){
                    next->prev = tail;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};