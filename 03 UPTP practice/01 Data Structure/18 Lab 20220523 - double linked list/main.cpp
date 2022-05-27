/** DATA Structure - 2022/04/05
 * @student:            David Colman, IFE
 * @topic:              Delete element in Array
 * @profesor:           Dr. Binayak Kar
 * @teacherasistand:    Horacio Sosa
 */

#include <iostream>
#include <iomanip> // using setw(int n)
using namespace std;

struct Node{
    Node *previus;
    int data;
    Node *next;
};

// variables with global scope
// Node *ptr;
Node *head;
Node *tail;

// Functions predefinitions
void createDlist(int key);
void printForward();
void printReverse();
void insertAtBeginning(int key);
void insertAtTheEndUsingHead(int key);
void insertAtTheEndUsingTail(int key);
// Temp function
void printNode(Node * node);

int main(void){
    system("cls"); // clear screen 
    
    bool running = true;
    int option;
    int key;
    while (running){
        system("cls");
        printForward();
        cout << "1) Insert at beginning." << endl;
        cout << "2) Insert at the end using head. " << endl;
        cout << "3) Insert at the end using tail. " << endl;
        cout << "0) Exit." << endl;
        cout << " >> "; cin >> option;
        switch (option)
        {
        case 0:
            running = false;
            break;
        case 1:
            cout << "Insert key number: "; cin >> key;
            insertAtBeginning(key);
            break;
        case 2:
            cout << "Insert key number: "; cin >> key;
            insertAtTheEndUsingHead(key);
            break;
        case 3:
            cout << "Insert key number:"; cin >> key;
            insertAtTheEndUsingTail(key);
            break;
        default:
            break;
        }
    }
    return 0;
}

// Functions declarations
void createDlist(int key){
    Node *ptr = new Node();
    ptr->previus = NULL;
    ptr->data = key;
    ptr->next = NULL; 
    //printNode(ptr);
    head = ptr;
    tail = ptr;
}

// Print Double linkded list
void printForward(){
    Node *ptr = new Node;
    if (head == NULL) cout << "Empty double linked list" << endl;
    else{
        ptr = head;
        cout << "----------------------------------------" << endl;
        cout << setw(8) << "Previus " << setw(23) << "<--   Node  [data] -->" << setw(8) << " Next" << endl;
        do { 
            cout << setw(8) << ptr->previus << " <-- ";
            cout << ptr << "[" << setw(4) << ptr->data << "]";
            cout << " --> " << ptr->next << endl;
            ptr = ptr->next;
        } while (ptr != NULL);
        cout << endl << "HEAD: " << head <<"\t\tTAIL: " << tail << endl;
        cout << "----------------------------------------" << endl;
    }
}

void printReverse(){
    Node *ptr = new Node;
    if (tail == NULL) cout << "Empty double linked list" << endl;
    else{
        ptr = tail;
        cout << "----------------------------------------" << endl;
        cout << setw(8) << "Previus " << setw(23) << "<--   Node  [data] -->" << setw(8) << " Next" << endl;
        do { 
            cout << setw(8) << ptr->previus << " <-- ";
            cout << ptr << "[" << setw(4) << ptr->data << "]";
            cout << " --> " << ptr->next << endl;
            ptr = ptr->previus;
        } while (ptr != NULL);
        cout << endl << "HEAD: " << head <<"\t\tTAIL: " << tail << endl;
        cout << "----------------------------------------" << endl;
    }
}


void insertAtBeginning(int key){
    Node *ptr = new Node;
    if (head == NULL) createDlist(key);
    else  {
        ptr->previus = NULL;
        ptr->data = key;
        ptr->next = head;
        
        // the first node is connecting to the new node.
        head->previus = ptr;   

        // the node created is now the new head.
        head = ptr; 
    }
}

// using Tail
void insertAtTheEndUsingHead(int key){
    Node *ptr = new Node(); // create a new node with data.
    Node *ptrpass = new Node(); // just a pointer iterator.
    if (head == NULL) createDlist(key);
    else  {
        ptrpass = head;
        // Find the last node
        while (ptrpass->next != NULL){
            ptrpass = ptrpass->next;
        } 
        cout << "PTRPASS : " <<ptrpass->data << endl;
        ptr->next = NULL;
        ptr->data = key;
        ptr->previus = ptrpass; 
        ptrpass->next = ptr;

        // new tail
        tail = ptr;
    }
}

// using Tail
void insertAtTheEndUsingTail(int key){
    Node *ptr = new Node;
    if (tail == NULL) createDlist(key);
    else  {
        ptr->previus = tail;
        ptr->data = key;
        ptr->next = NULL;
        
        // the first node is connecting to the new node.
        tail->next = ptr;

        // the node created is now the new head.
        tail = ptr;    
    }
}


void printNode(Node *node){
    if (node == NULL) cout << "Node NULL" << endl;
    else {
        Node *ptr = new Node;
        ptr = node;
        cout << ptr->previus << " <-- ";
        cout << ptr->data;
        cout << " --> " << ptr->next << endl;
    }
}
