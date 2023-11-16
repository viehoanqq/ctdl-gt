#include <iostream>
using namespace std;
struct Node{
	int data;
	Node * next;
};

Node* newNode(int Data)
{
	Node * node = new Node();
	node->data = Data;
	node->next = NULL;
	return node;
}
class LinkedList{
	private: 
		int m_count=0;
	public:
		Node *Head;
		Node *Tail;
		void insertHead(int val)
		{
			Node * currentNode = newNode(val);
			currentNode ->next = Head;
			Head = currentNode;
			if (m_count == 0)
			{
				Tail = Head;
			}
			m_count++;
		}
		void insertTail(int val)
		{
			Node * currentNode = newNode(val);
			if (m_count == 0)
			{
				Tail = currentNode;
				Head = Tail;
				m_count++;
				return;
			
				
			}
			Tail->next= currentNode;
			Tail = currentNode;
			m_count++;
	
		}
		void printList()
		{
			Node * currentNode = Head;
			while (currentNode != NULL)
			{
				cout<< currentNode->data<<" ";
				currentNode = currentNode->next;
			}
		}
		void insert(int index, int val)
		{
			if (index < 0 && index >m_count)
			{
				cout<<"loi!";
				return;
			}
			if (index== 0)
			{
				insertHead(val);
				m_count++;
				return;
			}
			Node * node=  newNode(val);
			Node *currentNode = Head;
			for (int i=0;i<index-1;i++)
			{
				currentNode = currentNode->next;
			}
			node ->next = currentNode->next;
			currentNode->next = node;
			m_count++;
		}
		
		void removeHead()
		{
			Node *temp = Head;
			Head = Head->next;
			delete temp;
			m_count--;
		}
		void removeTail()
		{
			Node *temp = Tail;
			Node *currentNode = Head;
			for (int i=0;i<m_count-2;i++)
			{
				currentNode = currentNode ->next;
			}
			currentNode->next = NULL;
			Tail = currentNode;
			m_count--;
			delete temp;
		}
		
		int getData(int index)
		{
			Node * currentNode = Head;
			for (int i=0; i<index ;i++)
			{
				currentNode = currentNode -> next;
			}
			return currentNode->data;
		}
		int  search(int val)
		{
			Node *currentNode = Head;
			for (int i=0;i<m_count;i++)
			{
				if (currentNode ->data == val)
				{
					return i;
				}
				currentNode = currentNode->next;
			}
		}
		
};

int main()
{
	LinkedList list;
	list.insertHead(3); //3 
	list.insertHead(10) ; //10 3
	list.insertTail(9); // 10 3 9
	list.insert(2,999);// 10 3 999 9
	list.insert(3,1); // 10 3 999 1 9
	list.printList();
	cout<<endl<<endl;
	list.removeHead(); // 3 999 1 9
	
	list.printList();
	
	cout<<endl<<list.getData(1);
	cout<<endl<<list.search(9);
}
