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

void LLmatch(Node* head1 , Node* head2){
    if(head1 == NULL){
        cout<<"NO";
        return;
    }

    Node* temp = head2;
    while(temp != NULL){
        Node* check = head1;
        Node* temp1 = temp;
        while(check != NULL && temp1 != NULL){
            if(check->data == temp1->data){
                check = check->next;
                temp1 = temp1->next;
            }
            else{
                break;
            }
        }
        if(check == NULL){
            cout<<"YES";
            return;
        }
        temp = temp->next;
    }
    cout<<"NO";
    return;
}


int main() {
    //first LL
    Node* head1 = new Node(10);
    head1->next = new Node(20);

    //second LL
    Node* head2 = new Node(1);
    head2->next = new Node(10);
    head2->next->next = new Node(20);

    LLmatch(head1 , head2);

    return 0;
}