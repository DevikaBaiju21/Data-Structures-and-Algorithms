// LeetCode 225: Implement Stack using Queues
// Link: https://leetcode.com/problems/implement-stack-using-queues/
// Pattern: Costly Push (Queue Rotation / Inversion on Push) 
// Time Complexity: O(N) for push | O(1) for pop, top, empty
// Space Complexity: O(N) total space to store N elements

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            int y = q1.front();
            q1.pop();
            q2.push(y);
        }
        swap(q1,q2);
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return (q1.empty())?true:false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
