#include <iostream>
#include <iomanip> // using setw(int n)
using namespace std;

const int MAXLENGT = 5;

// Global message string
string MESSAGE = "";
string TEMP = "";

// class declaraation
class Queue{
    int top;
    int arr[MAXLENGT];
    public:
        // constructor
        Queue(){
            top = -1;
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
            if(top == -1){
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
            
            if (top == (MAXLENGT - 1)) 
            {
                return true;}

            else {
                return false;}

        }

        void push(int key){
            // if full
            if (isFull()){
                MESSAGE = "Stack is full!";
            }
            // if empty
            else if (isEmpty()){
                //cout << "flag1" << endl;
                top = 0;

                arr[top] = key;
            }
            else{
                //cout << "flag2" << endl;
                top++;
                arr[top] = key;
            }
        }

        int pop(){
            // if full
            int value = -1;
            // if empty
            if (isEmpty()){
                MESSAGE = "You can not delete an empty list.";
            }
            else if (isFull()){
                //TEMP = "falg1";
                value = arr[top];
                arr[top] = 0;
                top--;
            }
            else{
                //TEMP = "FLAG2";
                value = arr[top];
                arr[top] = 0;
                top--;
            }

            return value; 
        }

        void count(){

        }

        void displayQueue(){
            cout << endl;
            for (int i = MAXLENGT - 1; i >= 0; i--){
                cout << " | " << setw(5) <<  arr[i] << " | " << endl;
            }
            
            //cout << arr[MAXLENGT - 1] << "]";
            cout << "---------" << endl;
            cout << endl << "Front: " << top; 
            cout << endl;

            cout << MESSAGE << endl << endl << TEMP << endl;
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
        cout << "1) Push()." << endl;
        cout << "2) Pop() . " << endl;
        cout << "3) isEmpty?. " << endl;
        cout << "4) isFull?." << endl;
        cout << "0) Exit." << endl;
        cout << " >> "; cin >> option;
        MESSAGE = "";

        switch (option)
        {
        case 0:
            running = false;
            break;
        case 1:
            cout << "Enter value: "; cin >> key;
            myQueue.push(key);
            break;
        case 2:
            myQueue.pop();
            break;
        case 3:
            MESSAGE =  (myQueue.isEmpty())? "Is Empty!." : "is NOT Empty";
            break;
        case 4:
            MESSAGE =  (myQueue.isFull())? "Is Full!." : "is NOT Full";
            
        default:
            break;
        }
    }

    return 0;
}