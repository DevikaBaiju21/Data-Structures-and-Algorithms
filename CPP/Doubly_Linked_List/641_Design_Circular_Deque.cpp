// LeetCode 641: Design Circular Deque
// Link: https://leetcode.com/problems/design-circular-deque/
// Pattern: Doubly linked list with head, tail and a capacity counter
// Time: O(1) per operation   Space: O(k)

class Node{
    public:
    int data;
    Node * next, *prev;
    Node(int x){
        data = x;
        next = prev = nullptr;
    }
};
class MyCircularDeque {
    Node * head,* tail;
    int size,capacity;
public:
    MyCircularDeque(int k) {
        head = tail = nullptr;
        size = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        Node * newHead = new Node(value);
        if(head==nullptr){
            head = tail = newHead;
        }else{
            head->prev = newHead;
            newHead->next = head;
            head = newHead;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        Node * newTail = new Node(value);
        if(tail==nullptr){
            head = tail = newTail;
        }else{
            tail->next = newTail;
            newTail->prev = tail;
            tail = newTail;
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        Node * oldHead = head;
        head = head->next;
        if(head==nullptr){
            head = tail = nullptr;
        }else{
            head->prev =nullptr;
        }
        delete oldHead;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        Node * oldTail = tail;
        tail = tail->prev;
        if(tail==nullptr){
            head=tail=nullptr;
        }else{
            tail->next = nullptr;
        }
        delete oldTail;
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return head->data;
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return tail->data;
    }
    
    bool isEmpty() {
        return size==0?true:false;
    }
    
    bool isFull() {
        return size==capacity?true:false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */