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
void insertAtSpecificPosition(int key, int pos);
void deletionAtBeginning();
void deletionAtTheEnd();
void deletionByGivenvalue(int key);

// Temp function
void printNode(Node * node);

int main(void){
    system("cls"); // clear screen 
    
    bool running = true;
    int option;
    int key, pos;
    while (running){
        system("cls");
        printForward();
        cout << "1) Insert at beginning." << endl;
        cout << "2) Insert at the end using head. " << endl;
        cout << "3) Insert at the end using tail. " << endl;
        cout << "4) Insert at specific position." << endl;
        cout << "5) Deletion at the beginning. " << endl;
        cout << "6) Deletion at the end." << endl;
        cout << "7) Deletion by given value." << endl;
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
        case 4:
            cout << "Insert key number: "; cin >> key;
            cout << "Insert position to at number: "; cin >> pos;
            insertAtSpecificPosition(key, pos);
            break;
        case 5:
            deletionAtBeginning();
            break;
        case 6:
            deletionAtTheEnd();
            break;
        case 7:
            cout << "What value do you want to delete? "; cin >> key;
            deletionByGivenvalue(key);
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
    int p = 1;
    if (head == NULL && tail == NULL) cout << "Empty double linked list" << endl;
    else{
        ptr = head;
        cout << "------------------------------------------------" << endl;
        cout << setw(8) << "Previous " << setw(26) << "<--  Node   [pos] [data] -->" << setw(8) << " Next" << endl;
        do { 
            cout << setw(8) << ptr->previus << " <-- ";
            cout << ptr << "[" << setw(3) << p << "] [" << setw (4) << ptr->data << "]";
            cout << " -->   " << ptr->next << endl;
            ptr = ptr->next;
            p++;
        } while (ptr != NULL);
        cout << endl << "HEAD: " << head <<"\t\tTAIL: " << tail << endl;
        cout << "------------------------------------------------" << endl;
    }
}

void printReverse(){
    Node *ptr = new Node;
    if (tail == NULL) cout << "Empty double linked list" << endl;
    else{
        ptr = tail;
        cout << "----------------------------------------" << endl;
        cout << setw(8) << "Previus" << setw(23) << "<--   Node  [data] -->" << setw(8) << " Next" << endl;
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

// if pos is greater than the length of linked list, the new node will add at the end - not implemented
void insertAtSpecificPosition(int key, int pos){
    if (head == NULL && tail == NULL) {
        cout <<"TOTALMENTE VACIO" << endl;
       createDlist(key);
    }
    else if (head->next == NULL && pos == 1){
        cout<< "SOLO UN NODO"<< endl;
        head->previus = new Node();
        head->previus->previus = NULL;
        head->previus->data = key;
        head->previus->next = head;
        head = head->previus;
        tail = head->next;   
    }
    else if (head->next != NULL && pos == 1){
        cout << "DOS NODOS" << endl;
        Node *ptr = new Node();
        ptr->previus = NULL;
        ptr->data = key;
        ptr->next = head;
        head->previus = ptr;
        head = ptr;
    }
    else {
        cout<<"MAS DE UN NODO"<< endl;
        Node *ptrpass = new Node();
        ptrpass = head;
        for (int i = 1; i < pos - 1; i++){
            ptrpass = ptrpass->next;
        }

        Node * ptr = new Node();
        ptr->previus = ptrpass;
        ptr->data = key;
        ptr->next = ptrpass->next;

        ptr->next->previus = ptr;
        ptrpass->next = ptr;
    }
}

// Deletion at the beginning
void deletionAtBeginning(){
    if (head == NULL && tail == NULL) cout << "You can't delete a void linked list." << endl;
    else if (head->next == NULL){
        // the last node
        delete(head);
        head = NULL;
        tail = NULL;
    }
    else {
        Node *ptrToDelete = new Node();
        Node *ptrpass = new Node();
        ptrToDelete = head;
        ptrpass = head->next;
        head = ptrpass;
        head->previus = NULL;
        delete(ptrToDelete); 
    }
}

// Deletion at the end
void deletionAtTheEnd(){
    if (tail == NULL && head == NULL) cout << "You can't delete a void linked list." << endl;
    else if (tail->previus == NULL){
        // the last node
        delete(tail);
        head = NULL;
        tail = NULL;
    }
    else {
        Node *ptrToDelete = new Node();
        Node *ptrpass = new Node();

        ptrToDelete = tail;
        ptrpass = tail->previus;
        tail = ptrpass;
        tail->next = NULL;
        delete(ptrToDelete);
    }
}

void deletionByGivenvalue(int key){
    Node *toDelete = new Node();
    if (head == NULL && tail == NULL) cout << "You can't delete a void linked list." << endl;
    else if (head->next == NULL){
        cout << "ONLY ONE NODE"<< endl;
        // only one node
        if (head->data == key){
            delete(head);
            head = NULL;
            tail = NULL;
        }
    }
    else if (head->next == tail){
        cout << "TWO NODES" << endl;
        // there ara two nodes
        if (head->data == key){
            cout << "BYE HEAD" << endl;
            head = tail;
            tail->previus = NULL;
        }
        else if (tail->data == key){
            cout << "BYE TAIL" << endl;
            tail = head;
            head->next = NULL;           
        }
    }
    else if (head->data == key){
        cout << "more than two node, the first"<< endl;
        // if first node
        toDelete = head;
        head = head->next;
        head->previus = NULL;
        delete (toDelete);
    }
    else if (tail->data == key){
        cout <<"more than two nodes, the last" << endl;
        // if it is the last node
        toDelete = tail;
        tail = tail->previus;
        tail->next = NULL;
        delete(toDelete);
    }
    else {
        cout << "MORE THAN TWO"<<endl;
        // more than two nodes
        Node *ptr = new Node();
        ptr = head;
        while (ptr->next != NULL){
            if (ptr->data == key) {
                cout << "SE HA ENCONTRADO" << endl;
                break;
            }
            ptr = ptr->next;
        }
        //cout << "HEAD: " << ptr->data;
        (ptr->next)->previus = ptr->previus;
        (ptr->previus)->next = ptr->next;
        delete(ptr);
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
