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

/*
        10
     /     \
    5      12
   / \     / \
  2   7  11  13
 / \          \
1   3           14
*/
void printPreOrder(Node *ptr){
    if (ptr != NULL){
        // root
        cout << ptr->data <<", ";

        // left
        printPreOrder(ptr->left);

        // right
        printPreOrder(ptr->right);
    }
}

void printInOrder(Node *ptr){
    if (ptr != NULL){
        // left
        printPreOrder(ptr->left);

        // root
        cout << ptr->data <<", ";

        // right
        printPreOrder(ptr->right);
    }
}

void printPostOrder(Node *ptr){
    if (ptr != NULL){
        // left
        printPreOrder(ptr->left);

        // right
        printPreOrder(ptr->right);

        // root
        cout << ptr->data <<", ";
    }
}

int main(void){
    system("CLS");
    Node *root = NULL;

    //int dataTest [] = {10, 5, 7, 2, 3, 1, 12, 13, 11, 14}; // set data not workingI
    int dataTest [] = {10, 5, 15, 7}; 

    for (int i = 0; i < (sizeof(dataTest)/sizeof(dataTest[0])); i++){
        root = insert(root, dataTest[i]);
    }

    cout << endl << "--------PRE-ORDER: ROOT-LEFT-RIGHT--------" << endl;
    printPreOrder(root);
    
    cout << endl << "---------IN-ORDER: LEFT-ROOT-RIGHT---------" << endl;
    printInOrder(root);

    cout << endl << "--------POS-ORDER: LEFT-RIGHT-RIGHT-------" << endl;
    printPostOrder(root);

    return 0;
}