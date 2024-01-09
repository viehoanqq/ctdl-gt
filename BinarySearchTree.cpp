#include <iostream>
using namespace std;
class Node{
    public:
        int value;
        Node * left;
        Node * right;
        Node(int val){
            value = val;
            left = NULL;
            right = NULL;
        }
};


class BinarySearchTree{

    private: 
        Node * root;
    protected:
        Node * insert(Node * node, int val);
        void printTreeInOrder(Node * node);
        void printTreePostOrder(Node *node);
        void printTreePreOrder(Node * node);
        Node * search(Node *node,int val);
        int findMax(Node * node);
        int findMin(Node * node);
        Node * remove(Node * node, int val);
    public:
        void insert(int val);
        void printTreeInOrder();
        bool  search(int val);
        int findMax();
        int findMin();
        void remove(int val);
        void printTreePostOrder();
        void printTreePreOrder();
};


//----- protected :: code  ------ //
    Node * BinarySearchTree::insert(Node * node ,int val){
        Node * currentNode = new Node(val);
        if ( node == NULL){
            node = currentNode;
        }
        else{
            if (val > node->value)
            node->right = insert(node->right,val);
            else
            {
                node->left = insert(node->left,val);
            }
        }
        return node;
    }
    
    void BinarySearchTree::printTreeInOrder(Node * node){
        if (node == NULL) return;
        printTreeInOrder(node->left);
        cout<<node->value<<" ";
        printTreeInOrder(node->right);
        
    }
    void BinarySearchTree::printTreePostOrder(Node * node){
        if (node == NULL) return;
        printTreePostOrder(node->left);
        printTreePostOrder(node->right);
        cout<<node->value<<" ";
    }
    void BinarySearchTree::printTreePreOrder(Node *node){
        if (node == NULL) return;
        cout<<node->value<<" ";
        printTreePreOrder(node->left);
        printTreePreOrder(node->right);
    }
    
    Node * BinarySearchTree::search(Node *node, int val){
        if (node == NULL) return NULL;
        if ( node -> value == val) return node;
        else
        if (val > node->value){
        return search(node->right,val);
        }else
        return search(node->left , val);
    }
    
    int BinarySearchTree::findMax(Node * node){
        if (node == NULL) return -1;
        else 
        if (node->right == NULL)
        return node->value;
        else 
        return findMax(node->right);
    }
    
    int BinarySearchTree::findMin(Node *node){
        if (node == NULL) return -1;
        else
        if (node->left == NULL)
        return node->value;
        return findMin(node->left);
    }
    
//----- publlic :: code  ------ //
    void BinarySearchTree::insert(int val){
        root = insert(root,val);
    }
    void BinarySearchTree::printTreeInOrder(){
        printTreeInOrder(root);
        cout<<endl;
    }
    void BinarySearchTree::printTreePostOrder(){
        printTreePostOrder(root);
        cout<<endl;
    }
    void BinarySearchTree::printTreePreOrder(){
        printTreePreOrder();
    }
    bool BinarySearchTree::search(int val){
        Node * node = search(root,val);
        return !(node == NULL);
    }
    int BinarySearchTree::findMax(){
        return findMax(root);
    }
    int BinarySearchTree::findMin(){
        return findMin(root);
    }
    
int main(){
    BinarySearchTree bst;
    bst.insert(40);
    bst.insert(5);
    bst.insert(45);
    bst.insert(35);
    bst.insert(15);
    bst.insert(13);
    bst.insert(16);
    bst.insert(56);
    bst.insert(48);
    bst.insert(47);
    bst.insert(50);
    bst.printTreeInOrder();
    cout<<" search 53: " <<bst.search(53); cout<<endl;
    cout<<" search 48: " <<bst.search(48); cout<<endl;
    cout<<" findMax : " <<bst.findMax(); cout<<endl;
    cout<<" findMin : " <<bst.findMin(); cout<<endl;
    
}
    
    
    
    
    
    
    
    
    
    
