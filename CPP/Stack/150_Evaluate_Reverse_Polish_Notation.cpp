// LeetCode 150: Evaluate Reverse Polish Notation
// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
// Pattern: Push elements into a stack if numbers. 
// Else pop 2 elements and perform the desired operation. 
// Push the result into the stack. 
// Time Complexity: O(N) , Space Complexity: O(N) 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string &Token : tokens) {
            if (Token == "+" || Token == "-" || Token == "/" || Token == "*") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                if (Token == "+") st.push(a + b);
                else if (Token == "-") st.push(a - b);
                else if (Token == "*") st.push(a * b);
                else if (Token == "/") st.push(a / b); 
            }
            else {
                st.push(std::stoi(Token));
            }
        }
        return st.top();
    }
};