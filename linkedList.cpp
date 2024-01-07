#include <iostream>
using namespace std;
class Node{
    public:
        int value;
        Node * next;
        Node (int val){
            value = val;
            next = NULL;
        }
};
class linkedlist{
    private:
        int m_count=0;
    public:
        Node *Head;
        Node *Tail;
        
        int Count(){
            return m_count;
        }
        void insertHead(int val){
            Node * node = new Node(val);
            if (m_count == 0){
                Head= node;
                Tail=node;
            }
            else{
                node->next = Head;
                Head = node;
            }
            m_count++;
        }
        
        void insertTail(int val){
            Node * node = new Node (val);
            if ( m_count == 0){
                Head = node;
                Tail = node;
            }
            else{
                Tail->next = node;
                Tail = node;
            }
            m_count++;
            
        }
        
        void insert(int val,int index){
            Node * node = new Node(val);
            Node * currentNode = Head;
            if (index == 0){
                insertHead(val);
                return;
            }
            if (index == m_count -1)
            {
                insertTail(val);
                return;
            }
            for (int i=0;i<index-1;i++){
                currentNode = currentNode->next; //3 4 2 1 5
            }
            node ->next = currentNode->next;
            currentNode->next =node;
            
            m_count++;
        }
        
        void removeHead(){
            if (m_count==0) 
            return;
            if (m_count==	1){
            	Head=NULL;
            	Tail = NULL;
            	m_count--;
            	return;
			}
            Node * node =Head;
            Head = node ->next;
            delete node;
            m_count--;
        }
        void removeTail(){
            if (m_count == 0) return;
            if (m_count== 1){
                Tail = NULL;
                Head = NULL;
                delete Tail;
                m_count --;
                return;
            }
            Node * currentNode = Head;
            for (int i=0;i<m_count-2;i++)
            {
                currentNode = currentNode -> next;
            }
            delete Tail;
            currentNode -> next = NULL;
            Tail = currentNode;
            m_count--;
        }
        
        void remove(int index){
            if (index == 0) return;
            if (index == m_count-1){
                removeTail();
                return;
            }
            Node * currentNode = Head;
            for (int i=0;i<index -1;i++)
            {
                currentNode = currentNode->next;
            }
            currentNode->next = currentNode->next->next;
            m_count--;
            
        }
        int search(int val){
        	Node * currentNode = Head;
        	int i=0;
        	while (currentNode !=  NULL){
        		if (currentNode->value == val)
        		return i; 
        		currentNode = currentNode -> next;
        		i++;
			}
			return -1;
		}
        
        void printList(){
            if (m_count == 0){
                cout<<"danh sach trong!";
                return;
            }
            cout<<"so pt: "<<m_count<<endl;
            Node * currentNode =Head;
            while (currentNode != NULL){
                cout<<currentNode->value<<" ";
                currentNode = currentNode->next;
            }
            cout<<endl;
        }
        
        int *toArray() {
        int *a = new int[m_count];
        int i = 0;
        Node *currentNode = Head;
        while (currentNode != NULL) {
            a[i] = currentNode->value;
            i++;
            currentNode = currentNode->next;
        }
        return a;
        }
		
		int findMax() {
        Node *currentNode = Head;
        int max = currentNode->value;
        while (currentNode != NULL) {
        if (currentNode->value > max) {
            max = currentNode->value;
        }
            currentNode = currentNode->next;  // Added this line
        }
        return max;
        }   
        
        
	    void findUnique(){
			Node *node = Head;
			
			while (node!= NULL){
				Node * node2 = Head;
				bool flag = false;
				int i=0;
				while (node2!=node){
					if (node2->value == node->value)
						flag = true;
					i++;
					node2 = node2->next;
						
				}
				node = node->next;
				
				if (flag){
					remove(i);
				}
			}
		}
        
        
		void reverse() {
        Node *current = Head;
        Node *previous = NULL;
        Node *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        Head = previous;
        }
        
        
	    void removeAll() {
	    int count = m_count;
        while(Head!=NULL)
        {
    	    removeHead();
	    }
        }
        
};

int main(){
    linkedlist list;
    list.insertHead(1);
    list.insertHead(2);
    list.insertHead(4);
    list.insertTail(5);
    list.insertTail(10);
    list.insertHead(3); //3 4 2 1 5
    list.printList();
    cout<<endl<<endl;
    list.insert(6,1); //3 6 4 2 1 5
    list.insert(7,0); // 7 3 6 4 2 1 5   
    list.insert(8,7); // 7 3 6 4 2 1 5 8
    list.printList();
    cout<<endl<<endl;
    list.removeHead();
    list.removeTail();
    list.remove(3);
    list.printList();
    
    
    cout<<"tim 1: "<<list.search(1);
    int * arr = list.toArray();
    cout<<endl;
    cout<<"to array:"<<endl;
    for (int i=0;i<list.Count();i++)
    	cout<<arr[i]<<" ";
	cout<<endl<<endl;
    list.insertHead(2);
    list.insertHead(4);
    list.insertHead(2);
    list.insertHead(4);
    list.printList();
	cout<<"sau khi xoa pt trung lap:"<<endl;
	list.findUnique();
	list.printList();
	list.reverse();
	cout<<"sau khi dao nguoc:"<<endl;
	list.printList();
	cout<<"sau khi xoa all"<<endl;
	list.removeAll();
	list.printList();
	cout<<endl<<"tim max "+list.findMax();
}

