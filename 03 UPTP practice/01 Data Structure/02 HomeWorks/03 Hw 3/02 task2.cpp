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
    // new node
    Node * newNode = new Node();
    newNode->power = power;
    newNode->coefficient = coefficient;
    newNode->next = NULL;

    // conect tail to new node;
    if (tail != NULL){
        tail->next = newNode;
    }
    return newNode;
}

Node* polynomialAdd(Node *head1, Node *head2){
    Node *head = new Node();
    Node *tail = new Node();
    head = tail = NULL;
    Node *p1 = head1;
    Node *p2 = head2;
    int coefficient;
    while (p1 != NULL && p2 != NULL){
        if (p1->coefficient == 0){
            p1 = p1->next;
        }
        else if (p2->coefficient == 0){
            p2 = p2->next;
        }
        else if (p1->power > p2->power){
            tail = append(tail, p1->power, p1->coefficient);
            p1 = p1->next;

        }
        else if(p2->power > p1->power){
            tail = append(tail, p2->power, p2->coefficient);
            p2 = p2->next;
        }
        else{
            coefficient = p1->coefficient + p2->coefficient;
            if (coefficient != 0){
                tail = append(tail, p1->power, coefficient);
            }
            p1 = p1->next;
            p2 = p2->next;
        } 
    
        if (head == NULL){
            head = tail;
        }
    }

    printPolinomial(tail);

    while(p1 != NULL){
        tail = append(tail, p1->power, p1->coefficient);
        p1 = p1->next;
    }

    while(p1 != NULL){
        tail = append(tail, p2->power, p2->coefficient);
        p2 = p2->next;
    }

    return head;
}

void printPolinomial(Node *head){
    Node *ptr = new Node;
    ptr = head;
    if (ptr == NULL) cout << "Empty linked list" << endl;
    else{
        //ptr = head;
        do { 
            if (ptr->coefficient == 0) cout << "";
            else {
                if (ptr->coefficient < 0) cout << " ";
                else cout << " +";
                cout << ptr->coefficient;
                if (ptr->power == 0) cout << "";
                else cout << "x^" << ptr->power;
            }
            ptr = ptr->next;
        } while (ptr != NULL);
    }
    cout << endl;
}

//void polynomialAddTerms(Node *head, int coefficient, int power){

//}

int main(void){
    Node *term1 = new Node(); term1->coefficient = 1; term1->power = 4;
    Node *term2 = new Node(); term2->coefficient = 0; term2->power = 0;
    Node *term3 = new Node(); term3->coefficient =-3; term3->power = 2;
    Node *term4 = new Node(); term4->coefficient = 1; term4->power = 1;
    Node *term5 = new Node(); term5->coefficient = 1; term5->power = 0;    
    term1->next = term2;
    term2->next = term3;
    term3->next = term4;
    term4->next = term5;
    term5->next = NULL;
    Node *poly1 = term1;

    /*Node *poly1 = new Node();
    poly1 = NULL;
    poly1 = append(poly1, 1, 4);
    poly1 = append(poly1, 0, 0);
    poly1 = append(poly1, -3, 2);
    poly1 = append(poly1, 1, 1);
    poly1 = append(poly1, 1, 0);

    Node *poly2 = new Node();
    poly2 = NULL;
    poly2 = append(poly2, 1, 3);
    poly2 = append(poly2, -1, 2);
    poly2 = append(poly2, 5, 1);
    poly2 = append(poly2, -2, 0);
    poly2 = append(poly2, 1, 0);*/

    /*Node *poly2 = new Node();
    poly2->coefficient = 3;
    poly2->power = 4;*/

    term1 = new Node(); term1->coefficient = 1; term1->power = 3;
    term2 = new Node(); term2->coefficient =-1; term2->power = 2;
    term3 = new Node(); term3->coefficient = 5; term3->power = 1;
    term4 = new Node(); term4->coefficient =-2; term4->power = 0;
    term1->next = term2;
    term2->next = term3;
    term3->next = term4;
    term4->next = NULL;
    Node *poly2 = term1;

    cout << "---------------------------" << endl;

    Node *resul = new Node();
    resul = polynomialAdd(poly1, poly2);

    cout << endl << "The adition of both polynomial is: " << endl;
    cout << "p1: "; printPolinomial(poly1);
    cout << "p2: "; printPolinomial(poly2);
    cout << "---------------------------" << endl;
    printPolinomial(resul);

    return 0;
}
