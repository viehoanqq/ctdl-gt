#include <iostream>
using namespace std;
class Node{
	public:
		int value;
		Node* next;
		Node* prev;
		Node(int val){
			value = val;
			next=NULL;
			prev= NULL;
		}
};

class DoublyLinkedList{
	private:
		int m_count=0;
	public:
		Node * Head;
		Node * Tail;
		int Count(){
			return m_count;
		}
		void printList(){
			if (m_count==0){
				cout<<"danh sach rong"<<endl;
			}
			Node * node = Head;
			while (node != NULL){
				cout<<node->value<<" ";
				node= node ->next;
			}
			cout<<endl;
		}
		void printReverseList(){
			if (m_count==0){
				cout<<"danh sach rong"<<endl;
			}
			Node *node = Tail;
			while (node !=NULL){
				cout<<node->value<<" ";
				node = node->prev;
			}
			cout<<endl;
		}
		void insertHead(int val){
			Node * node = new Node(val);
			if (m_count==0){
				Head=node;
				Tail=node;
				m_count++;
			}else{
			
				node->next = Head;
				Head->prev = node;
				Head= node;
				m_count++;
			}
		}
		void insertTail(int val){
			Node *node  = new Node(val);
			node->prev = Tail;
			Tail->next = node;
			Tail = node;
			if (m_count==0){
				Head=Tail;
			}
			m_count++;	
		}
		void insert(int val,int index){
			if (index < 0 || index >m_count){
				cout<<"loi";
				return;
			}
			Node * node = new Node(val);
			Node * currentNode = Head;
			if (index == 0){
				insertHead(val);
				return;
			}
			if (index == Count()-1){
				insertTail(val);
				return;
			}
			for (int i=0;i<index-1;i++){
				currentNode = currentNode->next; //1 3 6 2
			}
			node->next = currentNode->next;
			node->prev = currentNode;
			currentNode->next->prev = node;
			currentNode->next= node;
			m_count++;
		}
		
		void removeHead(){
			if (m_count==0) return;
			if (m_count ==1){
				Head = NULL;
				Tail = Head;
				m_count--;
				return;
			}
			Node * node = Head;
			Head = node->next;
			Head->prev =NULL;
			delete node;
			m_count--;
		}
		void removeTail(){
			if (m_count==0) return;
			if (m_count==1){
				Tail= NULL;
				Head= NULL;
				m_count--; 
				return;
			}
			Node * temp = Tail;
			Tail =temp->prev;
			Tail->next=NULL;
			delete temp;
			m_count--;
		}
		void remove(int val){
			Node * node = Head;
			bool flag = true;
			while(node!=NULL){
				if (node->value == val ){ // 2 3 7 1
					if (node == Head){
						removeHead();
					} else 
					if (node == Tail){
						removeTail();
					} else 
						{
						node->prev->next = node->next;
						node->next->prev = node->prev;
						}
					flag =false;
					m_count--;
				}
				node = node->next;
			}
			if (flag){
				cout<<"khong ton tai!"<<endl;
			}
		}
		int search(int val){
			Node * node = Head;
			int i=0;
			while (node!= NULL){
				if (node ->value == val)
				return i;
				i++;
				node = node->next;
			}
			return -1;
		}
		Node * getValue(int index){
			if (index < 0 || index >= m_count){
				cout<<"loi!";
				return NULL ;
			}
			Node * node = Head;
			for (int i=0;i<index;i++){
				node = node->next;
			}
			return node;
		}
		int * toArray(){
			int *a;
			int i=0;
			Node * node = Head;
			while (node != NULL){
				a[i] == node->value;
				node = node ->next;
				i++;
			}
			return a;
		}
		DoublyLinkedList findUnique(){
		    DoublyLinkedList temp;
		    Node * node = Head;
		    while (node !=NULL){
		        if ( node == Head){
		            temp.insertHead(node->value);
		        }else{
		            if (temp.search(node-> value) == -1){
		                temp.insertTail(node->value);
		            }
		        }
		        node = node->next;   
		    }
		    return temp;
		}
};

int main(){
	DoublyLinkedList list;
	list.insertHead(1);
	list.insertHead(3);
	list.insertHead(2);
	list.insertTail(5);
	list.insertTail(4);
	list.insertHead(6); // 6 2 3 1 5 4
	list.printList();
	list.printReverseList(); // 4 5 1 3 2 6
	list.insert(7,3);
	list.insert(8,0); // 8 6 2 3 7 1 5 4
	list.printList();
	list.printReverseList();
	
	cout<<endl<<endl;
	cout<<"remove"<<endl;
	list.removeHead(); 
	list.removeHead();// 2 3 7 1 5 4
	list.printList();
	list.removeTail();
	list.printList(); // 2 3 7 1 5
	list.removeTail();  // 2 3 7 1
	list.printList();
	list.remove(7); // 2 3 1
	list.remove(71); // 2 3 1
	list.printList();
	list.printReverseList();
	cout<<endl<<endl;
	cout<<"search 1 : " <<list.search(1)<<endl;
	cout<<"get value from 1 : "<<list.getValue(1)->value;
	cout<<endl;
		list.insertHead(2);
	list.insertTail(5);
	list.insertTail(4);
		list.insertHead(2);
	list.insertTail(3);
	list.insertTail(4);
	list.printList();
	cout<<"List findUnique: ";
	DoublyLinkedList test = list.findUnique();
	test.printList();
}
