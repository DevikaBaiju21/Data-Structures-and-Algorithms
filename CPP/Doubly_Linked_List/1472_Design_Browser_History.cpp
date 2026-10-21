// LeetCode 1472: Design Browser History
// Link: https://leetcode.com/problems/design-browser-history/
// Pattern: Doubly linked list + current pointer (discard forward nodes on visit)
// Time: visit O(k) to free k forward nodes, back/forward O(steps)   Space: O(n)

class Page{
    public:
    Page * prev;
    Page * next;
    string url;
    Page(string x){
        prev = next = nullptr;
        url  = x;
    }
};
class BrowserHistory {
    Page * curr;
public:
    BrowserHistory(string homepage) {
        curr = new Page(homepage);
    }
    
    void visit(string url) {
        Page * extra = curr->next;
        while(extra!=nullptr){
            Page * next = extra->next;
            delete extra;
            extra = next;
        }
        Page * p1 = new Page(url);
        curr->next = p1;
        p1->prev = curr;
        p1->next = nullptr;
        curr = p1;
    }
    
    string back(int steps) {
        int k = 1;
        while(curr->prev!=nullptr && k<=steps){
            curr = curr->prev;
            k++;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        int k = 1;
        while(curr->next!=nullptr && k<=steps){
            curr = curr->next;
            k++;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */