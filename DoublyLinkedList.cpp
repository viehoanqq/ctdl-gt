#include <iostream>
using namespace std;
struct Node{
	int data;
	Node * prev;
	Node * next;
};

Node *newNode(int val)
{
	Node *node = new Node();
	node ->data =val;
	node->next= NULL;
	node ->prev = NULL;
	return node;
}

class DoublyLinkedList{
	private :
		int m_count=0;
	public:
		Node * Head = NULL ;
		Node * Tail = NULL;
		void printList()
		{
			Node *currentNode = Head;
			while (currentNode != NULL)
			{
				cout<<currentNode ->data<<" ";
				currentNode = currentNode ->next;
			}
			
		}
		void printDownList()
		{
			Node * currentNode = Tail;
			while ( currentNode != NULL)
			{
				cout<<currentNode->data<< " ";
				currentNode = currentNode ->prev;
			}
		}
	void insertHead(int val)
	{
    	Node *node = newNode(val);
    	if (Head !=NULL){
    	Head->prev = node;
    	node ->next = Head;
    	Head = node;
    	}
    	if ( Head == NULL)
    	{
    	Head=node;
		Tail=Head;
		}	
    	m_count++;
}
		void insertTail(int val)
		{
			Node * node = newNode(val);
			node ->prev = Tail;
			Tail->next = node;
			Tail = node;
			if (m_count == 0)
			{
				Head= Tail;
			}
			m_count++;
		}
		void insert(int index , int val)
		{
			Node * node = newNode(val);
			Node * currentNode = Head;
			if ( index < 0 && index > m_count) return;
			for (int i=0;i<index -1 ;i++)
			{
				currentNode = currentNode->next;
			}
			node -> next = currentNode->next;
			node -> prev = currentNode;
			currentNode->next->prev = node;
			currentNode->next = node;
			m_count++;
			
		}
		
		void removeHead()
		{
			if (m_count==0) return;
			if (m_count==1)
			{
				Head = NULL;
				Tail = Head;
				m_count--;
				return;
			}
			Node *temp = Head;
			Head = Head ->next;
			Head->prev = NULL;
			m_count--;
			delete temp;
		}
		void removeTail()
		{
			Node * node= Tail;
			if (m_count==0) return;
			if (m_count ==1 ) 
			{
				Tail=NULL;
				Head = Tail;
				m_count--;
				return;
			}
			Tail=Tail->prev;
			Tail->next = NULL;
			m_count--;
			delete node;
		}
		
		int search(int val)
		{
			Node * currentNode = Head;
			int i=0;
			while ( currentNode != NULL)
			{
				if ( currentNode->data == val)
				{
					return i;
				}
				currentNode = currentNode->next;
				i++;
			}
		}
		void remove(int index)
		{
			if (index < 0 and index >=m_count)
			{
				return ;
			}
			Node * currentNode = Head;
			if (index == 0)
			{
				removeHead();
				return;
			}
			if ( index == m_count-1)
			{
				removeTail();
				return;
			}
			for (int i=0;i<index-1;i++)
			{
				currentNode = currentNode ->next;
			}
			
			currentNode->next =currentNode->next->next;
			currentNode->next->prev = currentNode;
			m_count--;
		}
};

int main()
{
	DoublyLinkedList list;
//	list.Head = newNode(1);
	list.insertHead(9);
	list.insertHead(3);
	list.insertHead(2);
	list.insertTail(999);
	list.insertTail(11);
	list.insertHead(0);
	list.insert(3,4);
	list.printList();
	cout<<endl;
	list.removeHead();
	list.removeTail();
	list.printList();
	cout<<endl;
	list.printDownList();
	cout<<endl;
	cout<<list.search(999);
	cout<<endl;
	list.printList();
	cout<<endl;
	list.remove(4);
	list.printList();
}
