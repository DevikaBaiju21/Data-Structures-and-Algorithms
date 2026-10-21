// LeetCode 1670: Design Front Middle Back Queue
// Link: https://leetcode.com/problems/design-front-middle-back-queue/
// Pattern: Doubly Linked List with Linear Middle Traversal
// Time Complexity: 
//   - pushFront, pushBack, popFront, popBack: O(1)
//   - pushMiddle, popMiddle: O(n) due to center traversal loops
// Space Complexity: O(n) total node allocations

class Node{
    public:
        int data;
        Node * next, *prev;
        Node(int x){
            data = x;
            next = prev = nullptr;
        }
};

class FrontMiddleBackQueue {
    Node * head,* tail;
    int size;
public:
    FrontMiddleBackQueue() {
        head = tail = nullptr;
        size = 0;
    }
    
    void pushFront(int val) {
        Node* newHead = new Node(val);
        if (head==nullptr){
            head=tail=newHead;           
        }else{
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
        }
        size++;
    }
    
    void pushMiddle(int val) {
        Node * newNode = new Node(val);
        int idx = size/2;
        if(idx==0){
            pushFront(val);
            return;
        }   
        Node * target = head;
        for (int i = 0; i<idx;i++){
            target = target->next;
        }
        Node * before = target->prev;     
        newNode->next = target;
        newNode->prev = before;
        before->next = newNode;
        target->prev = newNode;
        size++;
    }
    
    void pushBack(int val) {
        Node * newTail = new Node(val);
        if(tail==nullptr){
            tail = head = newTail;
        }else{
            tail->next = newTail;
            newTail ->prev = tail;
            tail = newTail;
        }
        size++;
    }
    
    int popFront() {
        if (head==nullptr){
            return -1;    
        }
        Node * oldHead = head;
        int data = oldHead->data; 
        head = head->next;
        if (head==nullptr){
            tail = nullptr;               
        }else{
            head->prev = nullptr;          
        }
        delete oldHead;
        size--;
        return data; 
    }
    
    int popMiddle() {
        if(head==nullptr){
            return -1;
        }   
        int idx = (size-1)/2;
        if(idx==0){
            return popFront();
        }  
        Node * target = head;
        for (int i = 0; i<idx;i++){
            target = target->next;
        }
        int data = target->data;
        Node * prevT = target->prev;
        Node * nextT = target->next;
        prevT->next = nextT;
        nextT->prev = prevT;
        delete target;
        size--;
        return data;
   }
    
    int popBack() {
        if (tail==nullptr){
            return -1;         
        }
        Node * oldTail = tail;
        int data = oldTail->data; 
        tail = tail->prev;
        if (tail==nullptr){
            head = nullptr;               
        }else{
            tail->next = nullptr;         
        }
        delete oldTail;
        size--;
        return data;   
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */