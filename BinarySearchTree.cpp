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
        int findLe(Node * node);
        int count(Node * node);
        int countLeaf(Node * node);
        int count1nhanh(Node * node);
        int sum(Node * node);
    public:
        void insert(int val);
        void printTreeInOrder();
        bool  search(int val);
        int findMax();
        int findMin();
        void remove(int val);
        void printTreePostOrder();
        void printTreePreOrder();
        int findLe();
        int count();
        int countLeaf();
        int count1nhanh();
        int sum();
};
int BinarySearchTree::sum(Node * node){
    if (node ==NULL) return 0;
    int s= node->value;
    s+= sum(node->left);
    s+=sum(node->right);
    return s;
}
int  BinarySearchTree::sum(){
    return sum(root);
}
int BinarySearchTree::count1nhanh(Node * node){
    if (node == NULL) return 0;
    int dem=0;
    if ((node->right == NULL && node->left != NULL) || (node->right !=NULL && node->left==NULL)){
      dem= 1;
    }
    dem+= count1nhanh(node->left);
    dem+= count1nhanh(node->right);
    return dem;
}

int BinarySearchTree::count1nhanh(){
    return count1nhanh(root);
}
int BinarySearchTree::countLeaf(Node * node){
    if (node == NULL ) return 0;
    int dem=0;
    if (node->right ==NULL && node->left == NULL);
        return 1;
    }
    dem+=countLeaf(node->left);
    dem+=countLeaf(node->right);
    return dem;

}

int BinarySearchTree::countLeaf(){
    return countLeaf(root);
}
int BinarySearchTree::count(Node * node){
    if (node == NULL) return 0;
    int dem=1;
    dem += count(node->left);
    dem+= count(node->right);
    return dem;
}
int BinarySearchTree::count(){
    return count(root);
}
int BinarySearchTree::findLe(Node * node){
    if (node == NULL) return 0;
    int count =0;
    if (node->value % 2 != 0) count++;
    count += findLe(node->left);
    count += findLe(node->right);
    return count;
}
int BinarySearchTree::findLe(){
    return findLe(root);
}
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

    Node * BinarySearchTree::remove(Node * node, int val) {
    if (node == NULL) {
        return node;
    }

    if (val < node->value) {
        node->left = remove(node->left, val);
    } else if (val > node->value) {
        node->right = remove(node->right, val);
    } else {
        // Case 1: No child or only one child
        if (node->left == NULL) {
            Node *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == NULL) {
            Node *temp = node->left;
            delete node;
            return temp;
        }

        // Case 2: Two children
        Node *minRightSubtree = node->right;
        while (minRightSubtree->left != NULL) {
            minRightSubtree = minRightSubtree->left;
        }

        node->value = minRightSubtree->value;
        node->right = remove(node->right, minRightSubtree->value);
    }

    return node;
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
    void BinarySearchTree::remove(int val){
        root = remove(root,val);
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
    cout<<"find le: "<<bst.findLe();cout<<endl;
    bst.printTreeInOrder();
    cout<<" count : "<<bst.count();cout<<endl;

    cout<<"count of leaf : "<<bst.countLeaf();cout<<endl;
    cout<<"count 1 nhanh : "<<bst.count1nhanh();cout<<endl;
    cout<<"sum = "<<bst.sum();
}
