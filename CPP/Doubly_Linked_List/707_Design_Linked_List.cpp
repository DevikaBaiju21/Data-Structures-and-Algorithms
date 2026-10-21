// LeetCode 707: Design Linked List
// Link: https://leetcode.com/problems/design-linked-list/
// Pattern: Doubly linked list with head and tail pointers

class Node{
    public:
        int val;
        Node * next;
        Node * prev;
        Node(int x){
            val = x;
            next = prev = nullptr;
        }
};
class MyLinkedList {
    Node * head;
    Node * tail;
    int size;
public:
    MyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index<0 || index>=size){
            return -1;
        }
        Node * curr = head;
        for(int k =0;k<index;k++){
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node * newHead = new Node(val);
        if (head==nullptr){
            head = tail = newHead;
            size++;
        }else{
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
            size++;
        }
    }
    
    void addAtTail(int val) {
        Node * newTail = new Node(val);
        if (tail==nullptr){
            head = tail = newTail;
            size++;
        }else{
            newTail->prev = tail;
            tail->next = newTail;
            tail = newTail;
            size++;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        Node* newNode = new Node(val);
        Node * target = head;
        for(int i = 0;i<index;i++){
            target = target->next;
        }
        newNode->prev = target->prev;
        newNode->next = target;
        target->prev->next = newNode;
        target->prev = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index<0 || index>=size){
            return;
        }
        Node * target = head;
        for (int i =0;i<index;i++){
            target = target->next;
        }
        if(target->prev == nullptr){
            head = target->next;
        }else{
            target->prev->next =  target->next;
        }
        if(target->next==nullptr){
            tail = target->prev;
        }else{
            target->next->prev = target->prev;
        }
        delete target;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */