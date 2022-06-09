#include <iostream>
using namespace std;

#define SIZE 5

class Node{
    public:
    int data;
    Node *next;
};

class Deque{
    private:
        Node *head;
        Node *tail;
        Node *front;
        Node *rear;
        int element;

        //int arr[SIZE];
        //int front;
        //int rear;
        //int element;

    public:
        // constructor
        Deque(){
            /*for (int i = 0; i < SIZE; i++){
                arr[i];
            }*/
            head = NULL;
            tail = NULL;
            front = NULL;
            rear = NULL;
            element = 0;
        }

        // methods
        // no aplica
        /*bool isFull(){
            return (((rear + 1 ) % SIZE) == front);
        }*/

        // if head is null
        bool isEmpty(){
            if (head == NULL) return true;
            else return false;
            //return ((front == -1) && (rear == -1));
        }

        void enqueueAtFront(int key){
            // solo existe overflow si se llena la ram de la pc
            /*if (isFull())
            {
                cout << "Overflow" << endl;
                return;
            }*/
            if (isEmpty()){
                // creating node
                Node *newNode = new Node();
                newNode->data = key;
                newNode->next = NULL;

                head = tail = newNode;
                //head = newNode;
                tail = newNode;

            }
            /*else if (front != NULL){
                // creating node
                Node *newNode = new Node();
                newNode->data = key;
                newNode->next = NULL;
                
                front = SIZE - 1;

            }
            //else
                //front = front - 1;*/
        }
        /*void enqueueAtRear(int key){
            // not copy paste
            if (isFull())
            {
                cout << "Overflow" << endl;
                return;
            }
            else if (isEmpty()){
                front = rear = SIZE - 1;
            }
            else if (front == SIZE - 1)
                rear = (rear + 1 ) % SIZE;
            else
                rear++;
        }
        int dequeueAtFront(){
            int key;
            if (isEmpty()){
                cout << "Underflow" << endl;
                return 0;
            }
            else if (rear == front){
                key = arr[rear];
                arr[rear] = 0; // ?
                front = rear = 0;
            }
            // cunado front esta al final
            else if (front  == SIZE - 1){
                key = arr[front];
                arr[front] = 0;
                front = 0;
            }
            else {
                key = arr[front];
                arr[front] = 0;
                front++;
            }

            element--;
            return key;
        }
        int dequeueAtRear(){
            int key = 0;
            if (isEmpty()){
                cout << "Underflow" << endl;
                return 0;
            }
            else if (rear == front){
                key = arr[rear];
                arr[rear] = 0; // ?
                front = rear = -1;
            }
            // cunado front esta al final
            else if (rear  == 0){
                key = arr[rear];
                arr[rear] = 0;
                rear = SIZE - 1;
            }
            else {
                key = arr[rear];
                arr[rear] = 0;
                rear--;
            }

            element--;
            return key;
        }*/

        int count(){
            return element; 
        }

        void display(){
            if (isEmpty()){
                cout << "empty";
            }
            else {
                Node *ptr = new Node();
                ptr = head;
                while (ptr != NULL){
                    cout << ptr->data << ", ";
                    ptr = ptr-> next;
                }
            }
        }
};

int main(void){

    Deque adeque;

    adeque.enqueueAtFront(10);
    adeque.enqueueAtFront(20);
    adeque.enqueueAtFront(30);
    //adeque.enqueueAtRear(20);
    adeque.display();

    return 0;
}