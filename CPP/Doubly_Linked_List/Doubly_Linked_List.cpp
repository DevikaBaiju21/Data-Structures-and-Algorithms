#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * prev;
        Node * next;
        Node(int x){
            data = x;
            prev = next = nullptr;
        }
};

class DLL{
    Node * head;
    Node * tail;
    int size;
    public:
        DLL();
        void insertAtFront(int x);
        void insertAtEnd(int x);
        bool insertAtPosition(int x,int i);
        void deleteAtHead();
        void deleteAtTail();
        bool deleteAtPosition(int i);
        Node * search(int x) const;
        void displayForward() const;
        void displayBackward() const;
        int len() const;
        void reverseLL();
        Node * findMid() const;
        ~DLL();
        DLL(const DLL&) = delete;
        DLL& operator=(const DLL&) = delete;
};

//Constructor
DLL::DLL(){
    head =tail= nullptr;
    size = 0;
}

//Insert at head
void DLL::insertAtFront(int x){
    Node * newHead = new Node(x);
    if (head==nullptr){
        head = newHead;
        tail = newHead;
        size++;
        return;
    }
    Node * oldHead = head;
    newHead->next = oldHead;
    oldHead->prev = newHead;
    head = newHead;
    size++;
}

//Insert at tail
void DLL::insertAtEnd(int x){
    Node * newNode = new Node(x);
    if(head==nullptr){
        head = newNode;
        tail = newNode;
        size++;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    size++;
}

//Insert a node with data x at position i
bool DLL::insertAtPosition(int x,int i){
    if(i<0 || i>size){
        return false;
    }
    if(i==0){
        insertAtFront(x);
        return true;
    }
    if(i==size){
        insertAtEnd(x);
        return true;
    }
    Node * newNode = new Node(x);
    Node * prev = head;
    for (int k =0;k<(i-1);k++){
        prev = prev->next;
    }
    Node * next = prev->next;
    prev->next = newNode;
    newNode->prev = prev;
    newNode->next = next;
    next->prev = newNode;
    size++;
    return true;
}

//delete at head
void DLL::deleteAtHead(){
    if(head==nullptr){
        return;
    }
    Node * oldHead = head;
    Node * newHead = head->next;
    head = newHead;
    if (newHead==nullptr){
        tail = nullptr;
    }else{
        newHead->prev = nullptr;
    }
    delete oldHead;
    size--;
}

//delete at tail
void DLL::deleteAtTail(){
    if(tail==nullptr){
        return;
    }
    Node * newTail = tail->prev;
    if(newTail == nullptr){
        head=nullptr;
    }else{
        newTail->next = nullptr;
    }
    delete tail;
    tail = newTail;
    size--;
}

//Delete at position i
bool DLL::deleteAtPosition(int i){
    if(i<0 || i>=size){
        return false;
    }
    if(i==0){
        deleteAtHead();
        return true;
    }
    if(i==size-1){
        deleteAtTail();
        return true;
    }
    Node * target = head;
    for (int k = 0;k<i;k++){
        target = target->next;
    }
    target->next->prev = target->prev;
    target->prev->next = target->next;
    delete target;
    size--;
    return true;
}

//Search for node with value x
Node * DLL::search(int x) const{
    Node * curr = head;
    for (int i = 0;i<size;i++){
        if (curr->data == x){
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

//Display Forward
void DLL::displayForward() const{
    Node * curr = head;
    for (int i = 0; i<size;i++){
        cout<<curr->data<<" -> ";
        curr = curr->next;
    }
    cout<<"NULL\n";
}

//Display Backward
void DLL::displayBackward() const{
    Node * curr = tail;
    for (int i = 0; i<size;i++){
        cout<<curr->data<<" -> ";
        curr = curr->prev;
    }
    cout<<"NULL\n";
}

//Length of doubly linked list
int DLL::len() const{
    return size;
}

//Reverse the given doubly linked list
void DLL::reverseLL(){
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;  
        curr->next = curr->prev;  
        curr->prev = next;
        curr = next;               
    }
    Node* temp = head;            
    head = tail;
    tail = temp;
}

//Middle Node
Node * DLL::findMid() const{
    if(head==nullptr){
        return head;
    }
    Node * start = head;
    Node * end = tail;
    while(start!=end && start->next!=end){
        start = start->next;
        end = end->prev;
    }
    return start;
}

//Destructor
DLL::~DLL(){
    Node * curr = head;
    while (curr!=nullptr){
        Node * next = curr->next;
        delete curr;
        curr = next;
    }
    size=0;
}

int main(){
    DLL d;

    d.insertAtEnd(2);
    d.insertAtEnd(3);
    d.insertAtFront(1);
    d.insertAtPosition(9, 1);
    d.displayForward();
    d.displayBackward();
    cout << "len=" << d.len() << endl;

    d.deleteAtPosition(1);
    d.deleteAtHead();
    d.deleteAtTail();
    d.displayForward();
    d.displayBackward();
    cout << "len=" << d.len() << endl;

    d.insertAtEnd(5);
    d.insertAtEnd(7);
    d.displayForward();
    d.displayBackward();
    cout << "len=" << d.len() << endl;
    cout << d.search(5)->data << " " << (d.search(99) == nullptr) << " " << d.findMid()->data << endl;
    d.reverseLL();
    d.displayForward();
    d.displayBackward();
    cout << "len=" << d.len() << endl;

    DLL e;
    e.reverseLL();
    e.deleteAtHead();
    e.deleteAtTail();
    e.deleteAtPosition(0);
    cout << (e.findMid() == nullptr) << endl;
}