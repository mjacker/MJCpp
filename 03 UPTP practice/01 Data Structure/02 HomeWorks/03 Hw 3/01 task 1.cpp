/** DATA Structure - 2028/05/28
 * @student:            MJacker, IFE
 * @topic:              DSHW03
 * @profesor:           Dr. Binayak Kar
 * @teacherasistand:    Horacio Sosa
 */
    
#include <iostream>
#include <iomanip> // setw(n)
using namespace std;

// Global variable
string MESSAGE = ""; // used to display error messages on loop menu

class Node{
    public:
        Node *prev;
        int data;
        Node *next;

        // Constructor
        Node(){
            prev = NULL;
            data = 0;
            next =  NULL;
        }
};

class DLinkedList{
    private:
        Node *head;
        Node *tail;
    public:
        // Constructor
        DLinkedList(){
            head = NULL;
            tail = NULL;
        }
        
        // Methods
        // InsertAnode
        /**
         * @brief Insert a node is used when de linked list is void.
         * this means when head and tail are pointing to null. 
         * 
         * @param key is used to take a data from the user and save it to data field.
         */
        void insertAnode(int key){
            if (head != NULL) MESSAGE = "You can't add a node when Double linked list is not void.";
            // If there ara only two nodes
            else {
                cout << "HEAD: " << head;
                head = new Node();
                head->data = key;
                tail = head;
            }
        }

        /**
         * @brief Insert a node at the beginning ot the linked list.
         * 
         * @pre Precondition: Need at least one node existing on current linked list.
         * 
         * @param key is used to take a data from the user and save it to data field.
         */
        void insertAtBeginning(int key){
            if (head == NULL) insertAnode(key); // If user tray to add at the beginning,
                                                // but there are not nodes yet, so we call
                                                // first to insertAnode to handle it.    
            else  {
                // creating a new node, assinging data.
                Node *ptr = new Node;
                ptr->prev = NULL;
                ptr->data = key;
                ptr->next = head;
                
                // the first node is connecting to the new node.
                head->prev = ptr;   

                // the node created is now the new head.
                head = ptr; 
            }
        }
        /**
         * @brief Insert a node at the end of the linked list, if the node is Empty 
         * when this methods is called, so this method will call to the method insertAnode
         * to handle it.
         * 
         * @param key is used to take a data from the user and save it to data field.
         */
        void insertAtEnd(int key){
            Node *ptrpass = new Node(); // just a pointer iterator.
            if (head == NULL) /*cout << "VACIO:" << endl;*/insertAnode(key);// If user tray to add at the beginning,
                                                // but there are not nodes yet, so we call
                                                // first to insertAnode to handle it. 
            else  {
                // creating new node - this node will be the new last node.
                Node *ptr = new Node();
                ptr->next = NULL;
                ptr->data = key;

                // Find the actual last node
                ptrpass = head;
                while (ptrpass->next != NULL){
                    ptrpass = ptrpass->next;
                } 

                // conecting old last node with new last node
                ptrpass->next = ptr;    // the next of olf last node is the new last node
                ptr->prev = ptrpass;    // the previous of the new last node is the old last node.

                // update tail
                tail = ptr;
            }
        }
        /**
         * @brief Insert a node at given position.
         * @attention If positions is less than 1, will print just a message.
         * @attention if position is greater than the number of nodes of current linked list
         * then the node will be added at the end.
         * 
         * @param key 
         * @param position 
         */
        void insertAtGiverPosition(int key, int position){
            if (position < 1){
                MESSAGE = "Position should be greater or equal than 1.";
            }
            else{
                // if head and tail are NULL, this means the linked list is empty.
                // so this method call to insertAnode to handle it.
                if (head == NULL && tail == NULL) {
                    //cout <<"TOTALMENTE VACIO" << endl;
                    insertAnode(key);
                }
                // this means there is only one node in current linked list.
                // so nodes are connected manually.
                else if (head->next == NULL && position == 1){
                    //cout<< "SOLO UN NODO"<< endl;

                    // creating new node
                    head->prev = new Node();
                    head->prev->prev = NULL;
                    head->prev->data = key;
                    head->prev->next = head;

                    //conectng head and tail yo new node.
                    head = head->prev;
                    tail = head->next;   
                }
                // this means there are more than two nodes, but
                // we need to add the new node to the first node.
                else if (head->next != NULL && position == 1){
                    //cout << "DOS NODOS" << endl;
                    Node *ptr = new Node();
                    ptr->prev = NULL;
                    ptr->data = key;
                    ptr->next = head;
                    head->prev = ptr;
                    head = ptr;
                }
                // this means we do have more than two nodes, 
                // and we are trying to add a new node in a position
                // greater than 1, so the linked list is iterated to find
                // that position.
                else {
                    //cout<<"MAS DE UN NODO"<< endl;
                    Node *ptrpass = new Node();
                    ptrpass = head;
                    for (int i = 1; i < position - 1; i++){
                        if (ptrpass->next != NULL)
                            ptrpass = ptrpass->next;
                    }

                    // created new node
                    Node * ptr = new Node();
                    ptr->prev = ptrpass;
                    ptr->data = key;
                    ptr->next = ptrpass->next;

                    // connecting nodes
                    ptrpass->next = ptr;
                    if (ptr->next != NULL)
                        (ptr->next)->prev = ptr;
                }
            }
        }

        void deleteAtBeginning(){
            if (head == NULL && tail == NULL) MESSAGE = "List is empty";
            else if (head->next == NULL){
                // the last node
                cout << "The element " << head->data << " will be deleted." << endl;
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
                head->prev = NULL;
                cout << "The element " << ptrToDelete->data << " will be deleted." << endl;
                delete(ptrToDelete); 
            }
        }

        void deleteAtEnd(){
            if (tail == NULL && head == NULL) MESSAGE = "List is empty";
            else if (tail->prev == NULL){
                // the last node
                cout << "The element " << tail->data << " will be deleted." << endl;
                delete(tail);
                head = NULL;
                tail = NULL;
            }
            else {
                Node *ptrToDelete = new Node();
                Node *ptrpass = new Node();

                ptrToDelete = tail;
                ptrpass = tail->prev;
                tail = ptrpass;
                tail->next = NULL;
                cout << "The element " << ptrToDelete->data << " will be deleted." << endl;
                delete(ptrToDelete);
            }
        }

        void deleteAtGivenData(int key){
            Node *toDelete = new Node();
            if (head == NULL && tail == NULL) MESSAGE = "List is empty.";
            else if (head->next == NULL){
                //cout << "ONLY ONE NODE"<< endl;
                // only one node
                if (head->data == key){
                    cout << "The element " << head->data << " will be deleted." << endl;
                    delete(head);
                    head = NULL;
                    tail = NULL;
                }
            }
            else if (head->next == tail){
                //cout << "TWO NODES" << endl;
                // there ara two nodes
                if (head->data == key){
                    cout << "BYE HEAD" << endl;
                    head = tail;
                    tail->prev = NULL;
                }
                else if (tail->data == key){
                    //cout << "BYE TAIL" << endl;
                    tail = head;
                    head->next = NULL;           
                }
            }
            else if (head->data == key){
                //cout << "more than two node, the first"<< endl;
                // if first node
                toDelete = head;
                head = head->next;
                head->prev = NULL;
                delete (toDelete);
            }
            else if (tail->data == key){
                //cout <<"more than two nodes, the last" << endl;
                // if it is the last node
                toDelete = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete(toDelete);
            }
            else {
                //cout << "MORE THAN TWO"<<endl;
                // more than two nodes
                Node *ptr = new Node();
                ptr = head;
                while (ptr->next != NULL){
                    if (ptr->data == key) {
                        //cout << "ITEM FOUND" << endl;
                        break;
                    }
                    ptr = ptr->next;
                }
                //cout << "HEAD: " << ptr->data;
                (ptr->next)->prev = ptr->prev;
                (ptr->prev)->next = ptr->next;
                cout << "The element " << ptr->data << " will be deleted." << endl;
                delete(ptr);
            }
        }

        void sortingList(){
            // cout << "Not implemented." << endl;
            // with selection sort
            // 3 33 3 99 3 88 3 22 3 77 3 44 3 11 3 55
            // 3 10 3 30 3 20

            int tmp; // for swap values
            // If linked es empty.
            if (tail == NULL && head == NULL) MESSAGE = "List is empty";
            // If there ara only two nodes
            else if (head->next == tail){
                cout << "SOLO DOS NODOS" << endl;
                if (head->data > tail->data){
                    tmp = head->data;
                    head->data = tail->data;
                    tail->data = tmp;
                }
            }
            else{
                Node *i, *j, *small;
                i = head;
                //printNode(i);
                while (i->next != NULL){ 
                    displayListForward();
                    cout << "i: " <<  i-> data << ":" << endl;
                    j = i->next;
                    //printNode(j);
                    small = j;
                    while(j != NULL){
                        cout <<"########"<< endl;
                        cout << "j: " << ": " << j -> data <<"/ "<< endl;
                        cout << small ->data << ">" << j->data << "?" << ((small->data > j->data)?"yes":"no") << endl;;
                        if (small->data > j->data){
                            small = j;
                        }
                        j = j->next;
                    }
                    cout << endl << "\tSmallest: " << small->data;
                    if (i->data > small->data){
                        tmp = i->data;
                        i->data = small->data;
                        small->data = tmp;
                    }
                        cout << endl;
                        i = i->next;
                }
                // check the last two nodes
                //if (tail->prev != NULL){
                //    if (tail->prev->data > tail->data);
                //        tmp = tail->prev->data;
                //        tail->prev->data = tail->data;
                //        tail->data = tmp;
                //}
            }
        }

        void displayListForward(){
            Node *ptr = new Node;
            int p = 1;
            if (head == NULL && tail == NULL); 
            else{
                ptr = head;
                cout << "------------------------------------------------" << endl;
                cout << "Displaying Forward mode: " << endl;
                // printing <data>
                cout << "|  <data>  |";
                do { 
                    cout << setw(3) << ptr->data;
                    if (ptr->next != NULL) cout << setw(3) << "<->"; 
                    ptr = ptr->next;
                } while (ptr != NULL);

                // printing <position>
                cout << endl << "|<position>|";
                ptr = head;
                int pos = 1;
                do {
                    cout << setw(3) << pos << "   ";
                    ptr = ptr->next;
                    pos++;
                } while (ptr!= NULL);
                //cout << endl << "HEAD: " << head->data <<"\t\tTAIL: " << tail->data << endl;
                cout << endl;
                cout << "------------------------------------------------" << endl;
            }
        }

        void displayListReverse(){
            Node *ptr = new Node;
            if (tail == NULL) MESSAGE = "Empty double linked list";
            else{
                ptr = tail;
                cout << "------------------------------------------------" << endl;
                cout << "Displaying Reverse mode: " << endl;
                do { 
                    cout << setw(3) << ptr->data;
                    if (ptr->prev != NULL) cout << setw(3) << "<->";
                    ptr = ptr->prev;
                } while (ptr != NULL);
                //cout << endl << "HEAD: " << head->data <<"\t\tTAIL: " << tail->data << endl;
                cout << endl;
                cout << "------------------------------------------------" << endl;
            }
        }


    
        // Auxiliar method
        void displayListMemory(){
            Node *ptr = new Node;
            int p = 1;
            if (head == NULL && tail == NULL) MESSAGE = "Empty double linked list";
            else{
                ptr = head;
                cout << "------------------------------------------------" << endl;
                cout << setw(8) << "Previous " << setw(26) << "<--  Node   [pos] [data] -->" << setw(8) << " Next" << endl;
                do { 
                    cout << setw(8) << ptr->prev << " <-- ";
                    cout << ptr << "[" << setw(3) << p << "] [" << setw (4) << ptr->data << "]";
                    cout << " -->   " << ptr->next << endl;
                    ptr = ptr->next;
                    p++;
                } while (ptr != NULL);
                cout << endl << "HEAD: " << head <<"\t\tTAIL: " << tail << endl;
                cout << "------------------------------------------------" << endl;
            }
        }

        void printNode(Node *node){
        if (node == NULL) MESSAGE = "Node NULL";
        else {
            Node *ptr = new Node;
            ptr = node;
            cout << "[" << ptr->prev << " <-- ";
            cout << ptr->data;
            cout << " --> " << ptr->next  << "]" << endl;
        }
    }
};



int main(void)
{
    // terminal clear
    system("cls");

    // Instanciate Objects
    DLinkedList myLinkedList;

    /*//manyally testing
    myLinkedList.insertAnode(10);
    myLinkedList.insertAtBeginning(20);
    myLinkedList.insertAtEnd(30);
    myLinkedList.insertAtGiverPosition(40, 2); 
    myLinkedList.deleteAtBeginning();
    myLinkedList.deleteAtEnd();
    myLinkedList.deleteAtGivenData(10);
    myLinkedList.insertAtEnd(11);
    myLinkedList.insertAtEnd(22);
    myLinkedList.insertAtEnd(33);
    myLinkedList.insertAtEnd(44);
    myLinkedList.displayListMemory();
    myLinkedList.displayListForward();
    myLinkedList.displayListReverse();*/

    system("cls"); // clear screen 
    
    bool running = true;
    int option;
    int key, pos;
    int defaultDisplay = true; // 1: Forward, 2: Reverse, 3: Memory Address (bonus).
    while (running){
        system("cls");
        cout << " DATA STRUCTURE HOMEWORK 03 - " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "1) Insert a node. (Only insert a node when linked list is void.)" << endl;
        cout << "2) Insert at beginning." << endl;
        cout << "3) Insert at the end. " << endl;
        cout << "4) Insert at specific position." << endl;
        cout << "5) Deletion at the beginning. " << endl;
        cout << "6) Deletion at the end." << endl;
        cout << "7) Deletion by given value." << endl;
        cout << "8) Sort the linked list." << endl;
        cout << "9) Display Linked List - Forward." << endl;
        cout << "10) Display Linked List - Reverse." << endl;
        cout << "0) Exit." << endl;
        cout << "------------------------------------------------" << endl;
        cout << MESSAGE << endl; MESSAGE = "";

        // Default selecte display
        if (defaultDisplay == 1) myLinkedList.displayListForward();
        else if (defaultDisplay == 2) myLinkedList.displayListReverse();
        else myLinkedList.displayListMemory();

        cout << " >> "; cin >> option;
        switch (option){
        case 0:
            running = false;
            break;
        case 1:
            cout << "Insert a integer number: "; cin >> key;
            myLinkedList.insertAnode(key);
            break;
        case 2:
            cout << "Insert a integer number: "; cin >> key;
             myLinkedList.insertAtBeginning(key);
            break;
        case 3:
            cout << "Insert a integer number:"; cin >> key;
            myLinkedList.insertAtEnd(key);
            break;
        case 4:
            cout << "Insert a integer number: "; cin >> key;
            cout << "Insert position to add number: "; cin >> pos;
            myLinkedList.insertAtGiverPosition(key, pos); 
            break;
        case 5:
            myLinkedList.deleteAtBeginning();
            break;
        case 6:
            myLinkedList.deleteAtEnd();
            break;
        case 7:
            cout << "What value do you want to delete? "; cin >> key;
            myLinkedList.deleteAtGivenData(key);
            break;
        case 8:
            myLinkedList.sortingList();
            break;
        case 9:
            defaultDisplay = 1;
            break;
        case 10:
            defaultDisplay = 2;
            break;
        case 11:
            defaultDisplay = 3;
            break;
        default:
            break;
        }
    }

    return 0;
}
