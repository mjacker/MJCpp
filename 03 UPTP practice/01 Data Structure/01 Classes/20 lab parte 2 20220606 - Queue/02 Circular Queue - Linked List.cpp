#include <iostream>
using namespace std;

const int MAXLENGT = 5;

// Global message string
string MESSAGE = "";


// class declaration
class Node{
    public:
        int data;
        Node *next;
        // constructor
        Node(){
            data = 0;
        }
};

class QueueLink{
    Node *front;
    Node *rear;
    //int arr[MAXLENGT];
    //int items;
    public:
        // constructor
        QueueLink(){
            front = NULL;
            rear = NULL;
            //items = 0;
            //for (int i = 0; i < MAXLENGT; i++){
            //    arr[i] = 0;
            //}
        }

        // methods
        /**
         * @brief Compute the next position in a circular array,
         * this is a representation of rear++, front++ for a circular
         * array.
         * 
         * @return int return the next position
         */
        int nextPosition(int referencePosition){
            //cout << endl << "Next position: " << ((referencePosition + 1) % (MAXLENGT)) << endl;;
            return (((referencePosition + 1) % (MAXLENGT))); 
        }

        /**
         * @brief return true if there are not element in queue.
         * 
         * @return true 
         * @return false 
         */
        bool isEmpty(){
            // Updating to a circular Array
            //if((front == -1) && (rear == -1)){
            /*if(front == rear){
                return true;
            }
            else
                return false;*/

            /*if (items > 0) return false;
            else return true;*/
            return -1;
        }

        /**
         * @brief return true if all element had values different to zero. 
         * 
         * @return true 
         * @return false 
         */
        bool isFull(){
            //cout << "Front: " << front<< " Rear: " << rear<< endl << endl;
            
            /*if (nextPosition(rear) == front) 
            {
                MESSAGE = "IT IS FULL!!";
                return true;
            }

            else {
                return false; 
            }*/
        }

        void enqueue(int key){
            // if full
            /*if (isFull()){
                MESSAGE = "Queue is full!";
            }*/
            // if empty
            if (1){
                cout << "flag1" << endl;

                // Creating node
                Node *newNode = new Node();
                newNode->data = key;
                
                rear = newNode;
                front = newNode;
                //arr[rear] = key;
                //items++;
            }
            else{
                //cout << "flag2" << endl;
                //rear ++;

                //rear = nextPosition(rear);                
                //arr[rear] = key;
                //items++; 
            }
        }

        int denqueue(){
            // if full
            /*int value = -1;
            // if empty
            if (isEmpty()){
                MESSAGE = "You can not delete an empty list.";
            }
            else if (rear == front){
                //cout << "flag1:";
                value = arr[front];
                arr[front] = 0;
                front = 4;
                rear = 4;
                items--;
            }
            else{
                //cout << "flag2:";
                value = arr[front];
                arr[front] = 0;
                front = nextPosition(front);
                items--;*/

            /*if (front > rear){
                front = -1;
                rear = -1;
            }*/
            return -1; 
        }

        void count(){
            // not implemented
        }

        void displayQueue(){
            cout << endl;
            cout << "Circular Queue - Using Linked List." << endl;
            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl << endl;
            cout << "     [";
            
            Node *ptr = front;
            if (ptr == NULL) MESSAGE = "Empty.";
            else if (ptr != NULL){
                cout << ptr->data << ", ";
                ptr = ptr->next; 
            }
            //for (int i = 0; i < MAXLENGT - 1; i++){
            //    cout << arr[i] << ", ";
            //}
            //cout << arr[MAXLENGT - 1] 
            
            cout << "]" << endl;
            // rear printing
            /*cout << endl << " ";
            for (int i = 0; i< rear; i++){
                cout <<", ";
            }
            cout << " R"<< endl;*/

            // Printing Front and rear Values
            cout << endl << "Front: " << front << "   Rear: " << rear << /*"   Count: "<< items << */endl;
            cout << endl;

            cout << MESSAGE << endl << endl;
        }

};


int main(void){
    //system("cls"); // clear terminal
    QueueLink myQueueLinked;

    /*myQueue.displayQueue();
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);
    myQueue.displayQueue();
    cout << "Quitando: " << myQueue.denqueue() << endl;
    cout << "Quitando: " << myQueue.denqueue() << endl;
    cout << "Quitando: " << myQueue.denqueue() << endl;
    cout << "Quitando: " << myQueue.denqueue() << endl;
    cout << "Quitando: " << myQueue.denqueue() << endl;
    cout << "Quitando: " << myQueue.denqueue() << endl;
    myQueue.displayQueue();

    myQueue.enqueue(10);
    myQueue.displayQueue();*/

    bool running = true;
    int option;
    int key, pos;
    while (running){
        system("cls");
        myQueueLinked.displayQueue();
        cout << "1) Insert at the rear." << endl;
        cout << "2) Delete from front. " << endl;
        cout << "0) Exit." << endl;
        cout << " >> "; cin >> option;
        MESSAGE = "";

        switch (option)
        {
        case 0:
            running = false;
            break;
        case 1:
            cout << "Insert key number: "; cin >> key;
            myQueueLinked.enqueue(key);
            break;
        case 2:
            cout << "Delete front.: "; 
            myQueueLinked.denqueue();
            break;
        default:
            break;
        }
    }

    return 0;
}
