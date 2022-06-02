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
    public:
        // constructor
        Queue(){
            front = -1;
            rear = -1;
            for (int i = 0; i < MAXLENGT; i++){
                arr[i] = 0;
            }
        }

        // methods
        /**
         * @brief return true if there are not element in queue.
         * 
         * @return true 
         * @return false 
         */
        bool isEmpty(){
            if((front == -1) && (rear == -1)){
                return true;
            }
            else
                return false;
        }

        /**
         * @brief return true if all element had values different to zero. 
         * 
         * @return true 
         * @return false 
         */
        bool isFull(){
            //cout << "Front: " << front<< " Rear: " << rear<< endl << endl;
            
            if (rear == (MAXLENGT - 1)) 
            {
                return true;}

            else {
                return false;}

        }

        void enqueue(int key){
            // if full
            if (isFull()){
                MESSAGE = "Queue is full!";
            }
            // if empty
            else if (isEmpty()){
                //cout << "flag1" << endl;
                rear = 0;
                front = 0;
                arr[rear] = key;
            }
            else{
                //cout << "flag2" << endl;
                rear ++;
                arr[rear] = key;
            }
        }

        int denqueue(){
            // if full
            int value = -1;
            // if empty
            if (isEmpty()){
                MESSAGE = "You can not delete an empty list.";
            }
            else if (isFull()){
                //cout << "flag1:";
                value = arr[front];
                arr[front] = 0;
                front++;
            }
            else{
                //cout << "flag2:";
                value = arr[front];
                arr[front] = 0;
                front++;
            }

            if (front > rear){
                front = -1;
                rear = -1;
            }
            return value; 
        }

        void count(){

        }

        void displayQueue(){
            cout << endl;
            cout << "[";
            for (int i = 0; i < MAXLENGT - 1; i++){
                cout << arr[i] << ", ";
            }
            cout << arr[MAXLENGT - 1] << "]";
            cout << endl << "Front: " << front << "\t" << "Rear: " << rear << endl;
            cout << endl;

            cout << MESSAGE << endl << endl;
        }

};


int main(void){
    system("cls"); // clear terminal
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