/** DATA Structure - 2022/04/15
 * @student:            MJacker, IFE
 * @topic:              
 * @profesor:           Dr. Binayak Kar
 * @teacherasistand:    Horacio Sosa
 */
    
#include <iostream>
#include <iomanip> // setw(n)
using namespace std;

// Classes declarations
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
            head = new Node();
            head->data = key;
            tail = head;
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
                cout << "Position should be greater or equal than 1." << endl;;
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
            if (head == NULL && tail == NULL) cout << "List is empty" << endl;
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
            if (tail == NULL && head == NULL) cout << "List is empty" << endl;
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
            if (head == NULL && tail == NULL) cout << "List is empty" << endl;
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
    // with selection sort
    /*	Node *i, *j, *small;
	int tmp;
	i = head;
	while (i->next != NULL){ 
		cout << i-> data << ", ";
        j = i->next;
        small= j;
		while(j != NULL){
            cout << "\n\t: ";
			cout << j -> data <<"/ ";
            if (small->data > j->data){
                small = j;
            }
            j = j->next;
		}
        cout << endl << "\tSmallest: " << small->data;
        tmp = i->data;
        i->data = small->data;
        small->data = tmp;
        cout << endl << "\tswaped: " << i->data << ", " << small->data;
        cout << endl;
		i = i->next;
	}*/
}

    
        // Auxiliar method
        void displayListMemory(){
            Node *ptr = new Node;
            int p = 1;
            if (head == NULL && tail == NULL) cout << "Empty double linked list" << endl;
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
};



int main(void)
{
    // terminal clear
    system("cls");

    // Instanciate Objects
    DLinkedList myLinkedList;

    myLinkedList.insertAnode(10);
    myLinkedList.insertAtBeginning(20);
    myLinkedList.insertAtEnd(30);
    myLinkedList.insertAtGiverPosition(40, 2); 
    myLinkedList.deleteAtBeginning();
    myLinkedList.deleteAtEnd();
    myLinkedList.deleteAtGivenData(10);
    myLinkedList.displayListMemory();

    return 0;
}