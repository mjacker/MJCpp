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
         * @param key 
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

        void insertAtEnd(int key){
            
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
    myLinkedList.displayListMemory();

    return 0;
}