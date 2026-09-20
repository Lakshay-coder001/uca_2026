#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    public:
        Node(int d){
            this->data = d;
            this->next = NULL;
        }
};

void printLL(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* intersectionLL(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* newhead = NULL;
    Node* curr = NULL;
    while(temp1!= NULL && temp2 != NULL){
        if(temp1->data == temp2->data){
            Node* newnode = new Node(temp1->data);
            if(newhead == NULL){
                newhead = newnode;
                curr = newnode;
            }
            else{
                curr->next = newnode;
                curr = newnode;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data > temp2->data){
            temp2 = temp2->next;
        }
        else{
            temp1 = temp1->next;
        }
    }
    return newhead;
}

int main() {
    // first LL
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(2);
    head1->next->next->next = new Node(3);
    head1->next->next->next->next = new Node(4);

    //seond LL
    Node* head2 = new Node(2);
    head2->next = new Node(2);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(4);

    Node* intersected = intersectionLL(head1, head2);

    printLL(intersected);
    return 0;
} 

//output is 2->2->4