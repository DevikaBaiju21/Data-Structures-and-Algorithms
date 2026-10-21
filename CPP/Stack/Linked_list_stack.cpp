//Linked-list stack
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

class Stack{
    Node * top;
    int size;
    public:
    Stack();
    bool push(int x);
    bool pop();
    int peek() const;
    bool isEmpty() const;
    int len() const;
    void display() const;
    ~Stack();
};

//Constructor
Stack::Stack(){
    top = nullptr;
    size = 0;
}

//Insert a new node with value x at the head.
bool Stack::push(int x){
    Node * newNode = new Node(x);
    newNode->next = top;
    top = newNode;
    size++;
    return true;
}

//Delete the node at head.
bool Stack::pop(){
    if(isEmpty())return false;
    Node * oldHead = top;
    top = top->next;
    delete oldHead;
    size--;
    return true;
}

//Return the data present at head.
int Stack::peek() const{
    return top->data;
}

//Returns whether the stack is empty or not.
bool Stack::isEmpty() const{
    return (size==0)?true:false;
}

//Returns the size of the stack.
int Stack::len() const{
    return size;
}

void Stack::display() const{
    cout<<"------STACK-------\n";
    Node * curr = top;
    while(curr!=nullptr){
        cout<<curr->data<<"\n";
        curr = curr->next;
    }
}

Stack::~Stack(){
    Node * curr = top;
    while(curr!=nullptr){
        Node * next = curr->next;
        delete curr;
        curr = next;
    }
}
int main() {
    Stack s;

    // 1. Test isEmpty() and size() on empty stack
    cout << "Is empty? " << (s.isEmpty() ? "Yes" : "No") << "\n";
    cout << "Initial Size: " << s.len() << "\n\n";

    // 2. Test push()
    cout << "Pushing elements: 10, 20, 30\n";
    s.push(10);
    s.push(20);
    s.push(30);

    // 3. Test display() and size() after pushes
    s.display();
    cout << "Current Size: " << s.len() << "\n\n";

    // 4. Test peek()
    cout << "Top element (peek): " << s.peek() << "\n\n";

    // 5. Test pop()
    cout << "Popping top element...\n";
    s.pop();
    
    // 6. Verify changes
    s.display();
    cout << "New Top element: " << s.peek() << "\n";
    cout << "Final Size: " << s.len() << "\n";
    cout << "Is empty now? " << (s.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}

