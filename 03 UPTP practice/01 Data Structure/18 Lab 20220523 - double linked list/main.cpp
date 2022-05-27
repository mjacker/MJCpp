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

/*void printCircular(Node* ptr) ;
void insertAtend(Node * head, int key);
Node *insertAtBeginning(Node *head, int num);
void deleteAtEnd(Node * head);
Node *deleteAtBeginning(Node * head);*/

// variables with global scope
// Node *ptr;
Node *head;
Node *tail;

// Functions predefinitions
void createDlist(int key);
void printDlist();
void insertAtBeginning(int key);

// Temp function
void printNode(Node * node);

int main(void){
    system("cls"); // clear screen 
    
    // Creating double linked list
    createDlist(10);
    printDlist();

    // Inserting at the beginning
    cout << endl << "Insert at the beginning: " << endl;
    insertAtBeginning(20);
    insertAtBeginning(30);
    printDlist();


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
void printDlist(){
    Node *ptr = new Node;
    if (head == NULL) cout << "Empty double linked list" << endl;
    else{
        ptr = head;
        cout << "--------------------------------------" << endl;
        do { 
            cout << setw(8) << ptr->previus << " <-- ";
            cout << ptr << "[" << ptr->data << "]";
            cout << " --> " << ptr->next << endl;
            ptr = ptr->next;
        } while (ptr != NULL);
        cout << endl << "HEAD: " << head <<"\t\tTAIL: " << tail << endl;
        cout << "--------------------------------------" << endl;
    }
}

void insertAtBeginning(int key){
    Node *ptr;
    ptr = new Node;
    if (head == NULL) cout << "Empty double linked list." << endl;
    else  {
        ptr->previus = head;
        ptr->data = key;
        ptr->next = head->next;
        head->next = ptr;    
        
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


    
/*    // node creation
    Node * head =  new Node();
    Node * nodo1 =  new Node();
    Node * nodo2 =  new Node();
    Node * nodo3 =  new Node();

    // setting values
    nodo1->data = 10;
    nodo2->data = 20;
    nodo3->data = 30;

   // conectinc nodes
   head = nodo1;
   nodo1->next = nodo2;
   nodo2->next = nodo3;
   nodo3->next = nodo1; 

    // print linked list
    cout << "Print circular linked list: " << endl << "\t";
    printCircular(head);

    // insert node at the end
    cout << "Insert 40 at the end:" << endl << "\t";
    insertAtend(head, 40);
    printCircular(head);
    
    // insert node at the end
    cout << "Insert 50 at the end:" << endl << "\t";
    insertAtend(head, 50);
    printCircular(head);

    // insert at begginin
    cout << "insert 60 at beginning: " << endl << "\t";
    head = insertAtBeginning(head, 60);
    printCircular(head);


    // borrar al final
    cout << "Delete at the end: " << endl << "\t";
    deleteAtEnd(head);
    printCircular(head);

    // delete at start(head)
    cout << "Delete at beginning: " << endl << "\t";
    head = deleteAtBeginning(head);
    printCircular(head);*/
//}

/*

void printCircular(Node* head) {
    Node * ptr = new Node();
    ptr = head;
    if (ptr == NULL)
        cout << "circle listed list void.";
    else
        do{
            cout << ptr->data<<"-->";
            ptr = ptr->next;
        } while (ptr != head);
    cout << "HEAD" << endl;
}

void insertAtend(Node * head, int key){
    Node * ptr = new Node();
    ptr = head;
    if (head == NULL)
        cout << "Empty list" << endl;
    else {
        do{
            ptr = ptr->next;
        } while (ptr->next != head);
        ptr->next = new Node();
        (ptr->next)->data = key;
        (ptr->next)->next = head;
    }
}
Node *insertAtBeginning(Node *head, int num)
{
    Node *newNode = new Node();
    Node *temp = new Node();

    if (head == NULL)
    {
        cout << "Empty list" << endl;
    }
    else 
    {
        newNode -> data = num;
        temp = head;
        while (temp -> next != head)
        {
            temp = temp -> next;
        }
        newNode -> next = head;
        temp -> next = newNode;
        head = newNode;
    }
    return head;
}
// comment to myself, is there other way wihtout return a Node ?

void deleteAtEnd(Node * head){
    Node *ptr = new Node;
    ptr = head;
    if (head == NULL)
        cout << "Empty list" << endl;
    else {
        do{
            ptr = ptr->next;
        } while ((ptr->next)->next != head);
        // cout << "\n Current ptr: " << ptr->data << endl;
        delete (ptr->next);
        ptr->next = head;
    }
}

Node *deleteAtBeginning(Node * head){
    Node *ptr = new Node;
    Node *ptr2 = new Node;
    ptr = head; // pointing to the first node to delete
    if (head == NULL)
        cout << "Empty list" << endl;
    else {
        head = head->next; // new head
        ptr2 = head; // ptr2 will point to the last Node.
        do {
            ptr2 = ptr2->next;
        } while (ptr2->next != ptr);
        //cout << "Ptr2 pointing at: " << ptr2->data << endl;
    }
    delete(ptr); // deleting the first node
    ptr2->next = head; // conectig las Node to new head
    //cout << "Pointer: " << ptr->data << endl;
    //cout << "New head: " << head->data << endl;

    return head;
}*/