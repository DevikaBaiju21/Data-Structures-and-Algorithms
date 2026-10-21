//Array Stack
#include<iostream>
using namespace std;

class Stack{
    int Ssize,capacity,top;
    int * arr;
    public:
        Stack(int cap);
        bool push(int x);
        bool pop();
        int peek() const;
        bool isEmpty() const;
        bool isFull() const;
        int size() const;
        ~Stack();
};

//Constructor
Stack::Stack(int cap){
    Ssize = 0;
    capacity = cap;
    arr = new int[cap];
    top = -1;
}

//Inserting x at the end of the array
bool Stack::push(int x){
    if(isFull())return false;
    top+=1;
    arr[top] = x;
    Ssize++;
    return true;
}

//Deleting the last element of the array
bool Stack::pop(){
    if(isEmpty()) return false;
    Ssize--;
    top--;
    return true;
}

//Returning the last element's value.
int Stack::peek() const{
    return arr[top];
}

//Returns whether the array is empty or not.
bool Stack::isEmpty() const{
    return (Ssize==0)?true:false;
}

//Returns whether the array is full or not.
bool Stack::isFull() const{
    return (Ssize==capacity)?true:false;
}

//Returns the current number of elements in an array.
int Stack::size() const{
    return Ssize;
}

//Destructor
Stack::~Stack(){
    delete[] (arr);
}

int main(){
    Stack s(3);

    cout<<"Is the stack empty? "<<(s.isEmpty()?"Yes":"No")<<"\n";
    cout<<"Current size: "<<s.size()<<"\n";

    cout<<"Pushing 15...\n";
    cout<<(s.push(15)?"Pushed 15.\n":"The array is full!\n");
    cout<<"Pushing 30...\n";
    cout<<(s.push(30)?"Pushed 30.\n":"The array is full!\n");
    cout<<"Pushing 45...\n";
    cout<<(s.push(45)?"Pushed 45.\n":"The array is full!\n");
    cout<<"Pushing 50...\n";
    cout<<(s.push(50)?"Pushed 50.\n":"The array is full!\n");

    cout<<"Peek: "<<s.peek()<<"\n";
    cout<<"Size: "<<s.size()<<"\n";

    cout<<"Popping the top element...\n";
    cout<<(s.pop()?"Popped...\n":"The array is empty");
    cout<<"Peek: "<<s.peek()<<"\n";
    cout<<"Size: "<<s.size()<<"\n";

    return 0;
}