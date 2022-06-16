#include <iostream>
using namespace std;

// struct declaration
struct Node{
    int data;
    Node *left;
    Node *right;
};

// funcitons declarations
Node* newNode(int item){
    // cout << "[creando nodo]" << endl;
    Node *ptrNewNode = new Node();
    ptrNewNode->data = item;
    ptrNewNode->left = NULL;
    ptrNewNode->right = NULL;
    return ptrNewNode;
}

// insert a node recursiversly
Node* insert(Node * node, int key){
    // Return a new node if the tree is empty
    if (node == NULL)
        return newNode(key);

    // Traverse to the right place and insert the node
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
}

static int left = 0;
static int right = 0;
static int depth = 0;

/*
        10
     /     \
    5      12
   / \     / \
  2   7  11  13
     / \      \
    6   8      14
*/

void printTree(Node *root){
    //cout << "recibo root: " << root << endl;
    if (root != NULL){
        cout << endl << "root: " << root->data << "[" << root->left << "/" << root->right << "]"<< endl;

        // moving to left
        cout << "  <--";
        printTree(root->left);
        cout << "  -->";
        printTree(root->right);
    }
    else cout << "  NULL";
    
}


int main(void){
    system("CLS");
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 13);
    root = insert(root, 11);
    root = insert(root, 14);

    cout << "------------------" << endl;
    printTree(root);


    return 0;
}