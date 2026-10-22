// LeetCode 232. Implement Queue using Stacks
// Link: https://leetcode.com/problems/implement-queue-using-stacks/description/
// Pattern: Implement queue using 2 stacks(in_stack and out_stack)
// Time Complexity: Amortised O(1) , Space Complexity: O(N) 

//Push: Push every element into in_stack
//Pop: If out_stack is empty, move all the elements from in_stack to out_stack
//by alternate push and pop operations and return the top element before popping.
//If out_stack is not empty, just return the top element and pop.
//Peek: Same as pop logic but it just returns the top element without actually removing it.
class Stack{
    int * arr,top,capacity,Ssize;
    public:
    Stack(int cap){
        top = -1;
        Ssize = 0;
        capacity = cap;
        arr = new int[cap];
    }
    bool push(int x){
        if(isFull())return false;
        top++;
        arr[top]=x;
        Ssize++;
        return true;
    }
    bool pop(){
        if(isEmpty())return false;
        top--;
        Ssize--;
        return true;
    }
    int peek(){
        if (isEmpty())return -1;
        return arr[top];
    }
    bool isEmpty(){
        return (Ssize==0)?true:false;
    }
    bool isFull(){
        return (Ssize==capacity)?true:false;
    }
};
class MyQueue {
    Stack in_stack;
    Stack out_stack;
    int size;
public:
    MyQueue(): in_stack(100), out_stack(100) {
        size = 0;
    }
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        if(out_stack.isEmpty()){
            while(!in_stack.isEmpty()){
                int num = in_stack.peek();
                in_stack.pop();
                out_stack.push(num);
            }
        }
        int data = out_stack.peek();
        out_stack.pop();
        return data;
    }
    
    int peek() {
        if(out_stack.isEmpty()){
            while(!in_stack.isEmpty()){
                int num = in_stack.peek();
                in_stack.pop();
                out_stack.push(num);
            }
        }
        int data = out_stack.peek();
        return data;
    }
    
    bool empty() {
        return (in_stack.isEmpty() && out_stack.isEmpty())?true:false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */