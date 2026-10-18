#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int x){
            data = x;
            next = nullptr;
        }
};

class LinkedList{
    Node* head = nullptr;
    int size = 0;
    
    public:
        void display() const;
        void insertFront(int x);
        void insertEnd(int x);
        bool insertAt(int x,int i);
        void deleteHead();
        void deleteTail();
        bool deleteAt(int i);
        int search(int x) const;
        int len() const;
        void reverseLL();
        int findMid() const;
        bool detectCycle() const;
        ~LinkedList();
        LinkedList(const LinkedList&) = delete;
        LinkedList& operator=(const LinkedList&) = delete;
};

//display linked list
void LinkedList::display() const{
    if (head==nullptr) {
        cout<<"head -> NULL"; 
        return;
    }
    Node * curr = head;
    cout<<"head -> ";
    while(curr!=nullptr){
        cout<<curr->data<<" -> ";
        curr = curr->next;
    }
    cout<<"NULL";
}

//insert at head 
void LinkedList::insertFront(int x){
    Node *  NewNode = new Node(x);
    Node * prevHead = head;
    head = NewNode;
    NewNode->next = prevHead;
    size++;
}

//Insert at tail
void LinkedList::insertEnd(int x){
    Node * NewNode = new Node(x);
    if(head == nullptr){
        head = NewNode;
        size++;
        return;
    }
    Node * curr = head;
    while(curr->next!=nullptr){
        curr = curr->next;
    }
    curr->next = NewNode;
    size++;
}

//destructor
LinkedList::~LinkedList(){
    Node * succ = head;
    Node * curr = head;
    while(succ!=nullptr){
        succ = curr->next;
        delete curr;
        curr = succ;
    }
    size = 0;
}

// insert value x at position i (0 <= i <= size)
// returns true if inserted, false if the index is invalid
bool LinkedList::insertAt(int x, int i){
    if(i < 0 || i > size){
        return false;
    }
    if(i == 0){
        insertFront(x);     
        return true;
    }
    if(i == size){
        insertEnd(x);       
        return true;
    }

    Node* curr = head;
    for(int k = 0; k < i - 1; k++){
        curr = curr->next;  
    }
    Node* newNode = new Node(x);
    newNode->next = curr->next;  
    curr->next = newNode;        
    size++;
    return true;
}

void LinkedList::deleteHead(){
    if(head==nullptr){
        return;
    }
    Node * next = head->next;
    delete head;
    head = next;
    size--;
}

void LinkedList::deleteTail(){
    if(head==nullptr){
        return;
    }
    if(head->next == nullptr){   
        deleteHead();           
        return;
    }
    Node * curr = head;
    while(curr->next->next!=nullptr){
        curr = curr->next;
    }
    delete curr->next;
    curr->next=nullptr;
    size--;
}

bool LinkedList::deleteAt(int i) {
    if(i<0 || i>=size){
        return false;
    }
    if(i==0){
        deleteHead();
        return true;
    }
    Node* prev = head;
    for(int k = 0; k < i - 1; k++){
        prev = prev->next;      
    }
    Node* target = prev->next;  
    prev->next = target->next;  
    delete target;              
    size--;
    return true;
}

int LinkedList:: search(int x) const{
    Node * curr = head;
    int i = 0;
    while(curr!=nullptr){
        if(curr->data==x){
            return i;
        }
        i++;
        curr = curr->next;
    }
    return -1;
}

int LinkedList::len() const{
    return size;
}

void LinkedList::reverseLL(){
    Node * curr = head;
    Node * prev = nullptr;
    while(curr!=nullptr){
        Node * next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int LinkedList::findMid() const{
    if(head==nullptr){
        return -1;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;       
        fast = fast->next->next; 
    }
    return slow->data;
}


bool LinkedList::detectCycle() const{
    if(head==nullptr){
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;       
        fast = fast->next->next; 
        if(slow == fast){
            return true;
        }
    }
   return false; 
}

int main(){
    LinkedList l;

    // inserts
    l.insertEnd(2);
    l.insertEnd(3);
    l.insertFront(1);
    l.insertAt(9, 1);
    l.display();
    cout << "  len=" << l.len() << endl;

    // deletes
    l.deleteAt(1);
    l.deleteHead();
    l.deleteTail();
    l.display();
    cout << "  len=" << l.len() << endl;

    // search, middle, cycle
    l.insertEnd(5);
    l.insertEnd(7);
    l.display();
    cout << "  len=" << l.len() << endl;
    cout << l.search(5) << " " << l.search(99) << " " << l.findMid() << " " << l.detectCycle() << endl;

    // reverse
    l.reverseLL();
    l.display();
    cout << "  len=" << l.len() << endl;

    // empty list: nothing should crash
    LinkedList e;
    e.reverseLL();
    e.deleteHead();
    e.deleteTail();
    e.deleteAt(0);
    cout << e.findMid() << endl;
}
