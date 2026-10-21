// LeetCode 2296: Design a Text Editor
// Link: https://leetcode.com/problems/design-a-text-editor/
// Pattern: Doubly linked list with a cursor pointer
// Time: O(len) addText, O(k) deleteText and cursor moves   Space: O(n)

class Node{
    public:
    char ch;
    Node * prev, * next;
    Node(char c){
        ch = c;
        prev = next = nullptr;
    }
};
class TextEditor {
    Node dummy;
    Node * curr;
public:
    TextEditor() : dummy('|') {
        curr = &dummy;
    }
    
    void addText(string text) {
        Node* originalNext = curr->next;
        Node * addT = curr;
        for(char c: text){
            Node * n = new Node(c);
            addT->next = n;
            n->prev = addT;
            addT = n;
        }
        addT->next = originalNext;
        if (originalNext != nullptr) {
            originalNext->prev = addT;
        }
        curr = addT;
    }
    
    int deleteText(int k) {
        int charDel = 0;
        for(int i = 0;i<k && curr!=&dummy;i++){
            Node * toDelete = curr;
            curr = curr->prev;
            curr->next = toDelete->next;
            if (toDelete->next != nullptr) {
                toDelete->next->prev = curr;
            }
            delete toDelete;
            charDel++;
        }
        return charDel;
    }
    
string cursorLeft(int k) {
        // 1. Move left up to k times freely
        for(int i = 0; i < k && curr != &dummy; i++){
            curr = curr->prev;
        }
        
        // 2. Count exactly how many characters exist to our left (max 10)
        int steps = 0;
        Node* tempCount = curr;
        while (steps < 10 && tempCount != &dummy) {
            steps++;
            tempCount = tempCount->prev;
        }
        
        // 3. Read those characters backward
        string strLeft = "";
        Node * curr1 = curr;
        for(int i = 0; i < steps && curr1 != &dummy; i++){
            strLeft += curr1->ch;
            curr1 = curr1->prev;
        }
        reverse(strLeft.begin(), strLeft.end());
        return strLeft;
    }
    
    string cursorRight(int k) {
        // 1. Move right up to k times freely
        for(int i = 0; i < k && curr->next != nullptr; i++){
            curr = curr->next;
        }
        
        // 2. Count exactly how many characters exist to our left (max 10)
        int steps = 0;
        Node* tempCount = curr;
        while (steps < 10 && tempCount != &dummy) {
            steps++;
            tempCount = tempCount->prev;
        }
        
        // 3. Read those characters backward
        string strRight = "";
        Node * curr1 = curr;
        for(int i = 0; i < steps && curr1 != &dummy; i++){
            strRight += curr1->ch;
            curr1 = curr1->prev;
        }
        reverse(strRight.begin(), strRight.end());
        return strRight;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */