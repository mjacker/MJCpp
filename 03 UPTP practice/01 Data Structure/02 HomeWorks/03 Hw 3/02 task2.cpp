#include <iostream>
using namespace std;

// struct declaration
struct Node{
    int coefficient;
    int power;
    Node *next;
};

// function predenition
void printPolinomial(Node *ptr);

Node* append(Node *tail, int power, int coefficient){
    cout << "#################"<<endl;
    cout << "resiviendo: " << endl;
    cout << "tail:  " << tail << endl;
    cout << "power: " << power << endl;
    cout << "coeffi:" << coefficient<< endl<< endl;
    Node *ptr = new Node();
    ptr = tail;

    // new node
    Node * newNode = new Node();
    newNode->power = power;
    newNode->coefficient = coefficient;
    newNode->next = NULL;

    // conect tail to new node;
    if (ptr != NULL){
        ptr->next = newNode;
    }
    else 
        ptr = newNode;
    cout << "$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "OUT:" << endl;
    printPolinomial(ptr);
    return ptr;
}

Node* polynomialAdd(Node *head1, Node *head2){
    Node *head = new Node();
    Node *tail = new Node();
    head = tail = NULL;
    Node *p1 = head1;
    Node *p2 = head2;
    int coefficient;
    while (p1 != NULL && p2 != NULL)
    {
        cout << "---WHILE: " << p1->power << "/" << p2->power << endl;
        if (p1->power > p2->power){
            cout << "FLAG UNO" << endl;
            tail = append(tail, p1->power, p1->coefficient);
            p1 = p1->next;
        }
        else if(p2->power > p1->power){
            cout << "FLAG DOS" << endl;
            tail = append(tail, p2->power, p2->coefficient);
            p2 = p2->next;
        }
        else{
            cout << "FLAG TRES" << endl;
            coefficient = p1->coefficient + p2->coefficient;
            if (coefficient != 0){
                tail = append(tail, p1->power, coefficient);
            }
            p1 = p1->next;
            p2 = p2->next;
        } 
        if (head == NULL){
            cout << "TEMP3 - tail: " << tail << endl;
            head = tail;
        }

        while(p1 != NULL){
            tail = append(tail, p1->power, p1->coefficient);
            p1 = p1->next;
        }

        while(p1 != NULL){
            tail = append(tail, p2->power, p2->coefficient);
            p2 = p2->next;
        }
    }
    cout << "TEMP2 head:" << head << endl;

    printPolinomial(tail);
    return head;
}

void printPolinomial(Node *head){
    Node *ptr = new Node;
    ptr = head;
    if (ptr == NULL) cout << "Empty linked list" << endl;
    else{
        //ptr = head;
        do { 
            cout << " +" << ptr->coefficient<< "x^" << ptr->power;
            ptr = ptr->next;
        } while (ptr != NULL);
    }
    cout << endl;
}

int main(void){
    //Node *poly1, *poly2, *resul;

    Node *poly1 = new Node();
    poly1->coefficient = 1;
    poly1->power = 2;

    Node *poly2 = new Node();
    poly2->coefficient = 3;
    poly2->power = 4;

    printPolinomial(poly1);
    printPolinomial(poly2);

    cout << endl <<"----------------" << endl;
    

    Node *resul = new Node();
    resul = polynomialAdd(poly1, poly2);
    cout << "TEMP: " << resul << endl;

    printPolinomial(resul);

    return 0;
}