// LeetCode 155: Min Stack
// Link: https://leetcode.com/problems/min-stack/
// Pattern: Two parallel stacks 
// Time Complexity: O(1) , Space Complexity: O(N) 

class MinStack {
    stack<int> main_stack, min_stack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        main_stack.push(value);
        if(min_stack.empty()){
            min_stack.push(value);
            return;
        }
        if(min_stack.top()>value){
            min_stack.push(value);
        }else{
            min_stack.push(min_stack.top());
        }
    }
    
    void pop() {
        main_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */