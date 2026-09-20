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

Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* newhead = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

int main() {
    Node* head = new Node(10);
    Node* sec = new Node(20);
    Node* third = new Node(30);

    head->next = sec;
    sec->next = third;

    cout<<"Befor ";
    printLL(head);
    cout<<endl;
    cout<<"after reverse ";
    head = reverseLL(head);
    printLL(head);

    return 0;
}