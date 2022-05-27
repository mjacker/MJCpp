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
void insertAtTheEnd(int key);
// Temp function
void printNode(Node * node);

int main(void){
    system("cls"); // clear screen 
    
    // Creating double linked list
    createDlist(10);
    //printForward();

    // Inserting at the beginning
    cout << endl << "Insert at the beginning: " << endl;
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtBeginning(40);
    //printForward();
    cout << endl << "Insert at the end (Before tail):" << endl;
    insertAtTheEnd(50);
    insertAtTheEnd(60);
    insertAtTheEnd(70);
    printForward();
    
    // Printing reverse.
    //cout << "Printing reverse: " << endl;
    printReverse();


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
    if (head == NULL) cout << "Empty double linked list." << endl;
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

void insertAtTheEnd(int key){
    Node *ptr = new Node;
    if (tail == NULL) cout << "Empty double linked list." << endl;
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
