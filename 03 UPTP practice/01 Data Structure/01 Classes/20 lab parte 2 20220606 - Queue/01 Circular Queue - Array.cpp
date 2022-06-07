#include <iostream>
using namespace std;

const int MAXLENGT = 5;

// Global message string
string MESSAGE = "";

// class declaraation
class Queue{
    int front;
    int rear;
    int arr[MAXLENGT];
    int items;
    public:
        // constructor
        Queue(){
            front = 4;
            rear = 4;
            items = 0;
            for (int i = 0; i < MAXLENGT; i++){
                arr[i] = 0;
            }
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

            if (items > 0) return false;
            else return true;
        }

        /**
         * @brief return true if all element had values different to zero. 
         * 
         * @return true 
         * @return false 
         */
        bool isFull(){
            //cout << "Front: " << front<< " Rear: " << rear<< endl << endl;
            
            if (nextPosition(rear) == front) 
            {
                MESSAGE = "IT IS FULL!!";
                return true;
            }

            else {
                return false; 
            }
        }

        void enqueue(int key){
            // if full
            if (isFull()){
                MESSAGE = "Queue is full!";
            }
            // if empty
            else if (isEmpty()){
                cout << "flag1" << endl;
                rear = nextPosition(rear);
                front = nextPosition(front);
                arr[rear] = key;
                items++;
            }
            else{
                //cout << "flag2" << endl;
                //rear ++;

                rear = nextPosition(rear);                
                arr[rear] = key;
                items++; 
            }
        }

        int denqueue(){
            // if full
            int value = -1;
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
                items--;
            }

            /*if (front > rear){
                front = -1;
                rear = -1;
            }*/
            return value; 
        }

        void count(){
            // not implemented
        }

        void displayQueue(){
            cout << endl;
            cout << "Circular Queue - Using Array." << endl;
            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl << endl;
            cout << "     [";
            for (int i = 0; i < MAXLENGT - 1; i++){
                cout << arr[i] << ", ";
            }
            cout << arr[MAXLENGT - 1] << "]" << endl;
            // rear printing
            /*cout << endl << " ";
            for (int i = 0; i< rear; i++){
                cout <<", ";
            }
            cout << " R"<< endl;*/

            // Printing Front and rear Values
            cout << endl << "Front: " << front << "   Rear: " << rear << "   Count: "<< items << endl;
            cout << endl;

            cout << MESSAGE << endl << endl;
        }

};


int main(void){
    //system("cls"); // clear terminal
    Queue myQueue;

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
        myQueue.displayQueue();
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
            myQueue.enqueue(key);
            break;
        case 2:
            cout << "Delete front.: "; 
            myQueue.denqueue();
            break;
        default:
            break;
        }
    }

    return 0;
}