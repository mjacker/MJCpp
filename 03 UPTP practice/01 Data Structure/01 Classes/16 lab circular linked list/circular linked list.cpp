#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};

void printCircular(Node* ptr) ;
void insertAtend(Node * head, int key);
Node *insertAtBeginning(Node *head, int num);
void deleteAtEnd(Node * head);
Node *deleteAtBeginning(Node * head);


int main(void){
    system("cls"); // clear screen
    
    // node creation
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
    printCircular(head);
}

/**
 * @brief Allows you to print the nodes of the circular node. 
 * 
 * @param ptr pointer point to head.
 */
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

/**
 * @brief Insert a node at the end of a circle linked list 
 * 
 * @param head pointer point to head
 * @param key data to save into struct data-field. 
 */
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

// para corregir que hice
/*void addToStart(Node * head, int key){
    Node * ptr = new Node();
    ptr = head;
    ptr2 = new Node();
    ptr2 = head;
    if (head == NULL){
        head = new Node();
        head->data = key;
        (head->next)->next = head;
    }
    else{
        ptr = new Node();
        ptr->data = key;
        ptr->next = head;
        do{
            ptr2 = ptr2->next;
        } while(ptr2-> next != head);
    }
    ptr2-> next = ptr;
}*/

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

/**
 * @brief Delete the last node
 * 
 * @param head pointer a head
 */
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
}