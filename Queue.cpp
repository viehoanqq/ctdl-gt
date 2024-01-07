#include <iostream>
using namespace std;
class Node{
  public:
    int value;
    Node * next;
    Node(int val){
        value =val;
        next = NULL;
    }
};

class queue{
    private:
        Node * frontNode;
        Node * rearNode;
    public:
        bool isEmpty();
        int size();
        void enqueue(int val);
        int dequeue();
        int front();
        void clear();
        string toString();
        
};
bool queue::isEmpty(){
    return (frontNode == NULL);
    
}
int queue::size(){
    Node * node = frontNode;
    int i=0;
    while (node !=NULL){
        node = node->next;
        i++;
    }
    return i;
}
void queue::enqueue(int val){
    Node * node = new Node(val);
    if (isEmpty()){
        frontNode = node;
        rearNode = frontNode;
    }else{
        node->next = frontNode;
        frontNode = node;
    }
}
int queue::dequeue(){
    if (isEmpty()){
        return -1;
    }
    else{
        Node * node = frontNode;
        frontNode = frontNode  -> next;
        return node->value;
    }
}
void queue::clear(){
    while (!isEmpty()){
        dequeue();
    }
    
}
string queue::toString(){
    string s="";
    if (isEmpty()) s="rong";
    else{
        Node * node =frontNode;
        while (node!=NULL){
            s+= to_string(node->value);
            node = node->next;
        }
    }
    return s;
}

int queue::front(){
    if (isEmpty()){
        return -1;
    }else{
        return frontNode ->value;
    }
}
void testQueue() {
    queue hangdoi;
    cout << "Is empty? " << (hangdoi.isEmpty() ? "true" : "false") << endl;
    cout << "Size: " << hangdoi.size() << endl;

    hangdoi.enqueue(1);
    hangdoi.enqueue(2);
    hangdoi.enqueue(3);
    hangdoi.enqueue(4);
    cout << "After enqueue: " << hangdoi.toString() << endl;
    cout << "Front element: " << hangdoi.front() << endl;
    cout << "Size: " << hangdoi.size() << endl;

    cout << "Dequeued element: " << hangdoi.dequeue() << endl;
    cout << "After dequeue: " << hangdoi.toString() << endl;
    cout << "Front element: " << hangdoi.front() << endl;
    cout << "Size: " << hangdoi.size() << endl;

    hangdoi.clear();
    cout << "After clear: " << hangdoi.toString() << endl;
    cout << "Is empty? " << (hangdoi.isEmpty() ? "true" : "false") << endl;
    cout << "Size: " << hangdoi.size() << endl;
}

int main() {
    testQueue();
    return 0;
}



















