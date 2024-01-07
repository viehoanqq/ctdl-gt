#include <iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* next;
        Node(int val){
            value = val;
            next = NULL;
        }
};

class Stack{
    private:
        Node * topNode;
    public:
        bool isEmpty();
        void push(int val);
        int pop();
        int top();
        void clear();
        string toString();
};

bool Stack::isEmpty(){
    return (topNode == NULL);
}
void Stack::push(int val){
    Node * node = new Node(val);
    if (isEmpty()){
        topNode = node;   
    }else{
        node->next = topNode;
        topNode = node;
    }
}
int Stack::pop(){
    if (isEmpty()) return -1;
    Node * node = topNode;
    topNode = node->next;
    return node->value;
    
}

int Stack::top(){
    if (isEmpty()) return -1;
    return topNode->value; 
}


void Stack::clear(){
    while (!isEmpty())
    pop();
}
string Stack::toString(){
    string s="";
    if (isEmpty()) return s="rong";
    Node * node = topNode;
    while(node !=NULL){
        s+=to_string(node->value);
        node= node->next;
        
    }
    return s;
    
}
void testStack() {
    Stack stack;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout << "Stack: " << stack.toString() << endl;

    cout << "Top element: " << stack.top() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Stack: " << stack.toString() << endl;
    cout << "Top element: " << stack.top() << endl;

    stack.clear();


    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    cout << "Stack: " << stack.toString() << endl;
}

int main() {
    testStack();
    return 0;
}
