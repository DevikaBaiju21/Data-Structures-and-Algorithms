// LeetCode 1047: Remove All Adjacent Duplicates In String
// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Pattern: Stack-Based String Reduction (Custom Array-Based Stack)
// Time Complexity: O(N) ,Space Complexity: O(N) 


class Stack{
    int top, Ssize, capacity;
    char * arr;
    public:
        Stack(int cap){
            capacity = cap;
            Ssize = 0;
            top = -1;
            arr = new char[cap];
        }
        bool push(char ch){
            if (isFull())return false;
            top+=1;
            arr[top]=ch;
            Ssize++;
            return true;
        }
        bool pop(){
            if(isEmpty())return false;
            Ssize--;
            top--;
            return true;
        }
        char peek(){
            if (isEmpty())return ' ';
            return arr[top];
        }
        bool isEmpty(){ return(Ssize==0)?true:false;}
        bool isFull(){ return (Ssize==capacity)?true:false;}
};
class Solution {
public:
    string removeDuplicates(string s) {
        Stack p(s.length());
        for (char c: s){
            if (p.peek()==c){
                p.pop();
            }else{
                p.push(c);
            }
        }
        string newS = "";
        while(!p.isEmpty()){
            newS+=p.peek();
            p.pop();
        }
        reverse(newS.begin(),newS.end());
        return newS;
    }
};