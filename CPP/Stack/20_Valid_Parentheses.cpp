// LeetCode 20: Valid Parentheses
// Link: https://leetcode.com/problems/valid-parentheses/
// Pattern: Stack (Custom Array-Based Implementation)
// Time: O(N)   Space: O(N)

class Stack{
    int Ssize, capacity, top;
    char * arr;
    public:
    Stack(int cap){
        Ssize = 0;
        capacity = cap;
        top = -1;
        arr = new char[cap];
    }
    bool push(char x){
        if(isFull())return false;
        top+=1;
        arr[top]=x;
        Ssize++;
        return true;
    }

    bool isFull(){return (Ssize==capacity)?true:false;}
    bool isEmpty(){return (Ssize==0)?true:false;}
    bool pop(){
        if(isEmpty())return false;
        Ssize--;
        top--;
        return true;
    }
    char peek(){
        if(isEmpty())return '\0';
        return arr[top];
    }
};
class Solution {
public:
    bool isValid(string s) {
        char openBrackets[3] = {'{','(','['};
        char closeBrackets[3] = {'}',')',']'};
        Stack p(s.length());
        for(int i = 0;i<s.length();i++){
            for(int j = 0;j<3;j++){
                if (openBrackets[j]==s[i]){
                    p.push(s[i]);
                    break;
                }else if(closeBrackets[j]==s[i] && p.peek()==openBrackets[j]){
                    p.pop();
                    break;
                }else if(closeBrackets[j]==s[i]){
                    return false;
                }
            }
        }
        if(p.isEmpty())
            return true;
        else
            return false;
    }
};