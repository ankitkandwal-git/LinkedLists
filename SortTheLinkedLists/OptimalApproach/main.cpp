#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* arrayToLL(int arr[],int n){
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for(int i=1;i<n;i++){
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* sortLL(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next != NULL){
        slow = fast;
        fast = slow;
        slow = slow->next;
        fast = fast->next;
    }
    return head;
}
int main(){
    int arr[] = {4,2,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = arrayToLL(arr,n);
    cout<<"Original Linked List: ";
    printLL(head);
    head = sortLL(head);
    cout<<"Sorted Linked List: ";
    printLL(head);
    return 0;
}