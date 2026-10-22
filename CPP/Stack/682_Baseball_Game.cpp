// LeetCode 682: Baseball Game
// Link: https://leetcode.com/problems/baseball-game/
// Pattern: Linear Dynamic Record Simulation (Custom Array-Based Stack)
// Time Complexity: O(N) , Space Complexity: O(N) 

class Stack{
    int Ssize, capacity, top, * arr;
    public:
    Stack(int cap){
        Ssize = 0;
        capacity = cap;
        top = -1;
        arr = new int[cap];
    }
    bool push(int x){
        if (isFull())return false;
        top++;
        arr[top]=x;
        Ssize++;
        return true;
    }
    bool pop(){
        if(isEmpty())return false;
        Ssize--;
        top--;
        return true;
    }
    int peek(){
        if(isEmpty())return -1;
        return arr[top];
    }
    bool isEmpty(){
        return (Ssize==0)?true:false;
    }
    bool isFull(){
        return (Ssize==capacity)?true:false;
    }
};
class Solution {
public:
    int calPoints(vector<string>& operations) {
        Stack p(operations.size());
        for(string s: operations){
            if (s=="C"){
                p.pop();
            }else if (s=="+"){
                int num1 = p.peek();
                p.pop();
                int num2  = p.peek();
                p.push(num1);
                p.push(num1+num2);
            }else if(s=="D"){
                int num1 = 2*p.peek();
                p.push(num1);
            }else{
                p.push(stoi(s));
            }
        }
        int totalSum = 0;
        while (!p.isEmpty()) {
            totalSum += p.peek();
            p.pop();
        }
        return totalSum;
    }
};