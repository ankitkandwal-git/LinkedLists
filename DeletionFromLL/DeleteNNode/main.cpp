#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next  = NULL;
    }
};

Node* arrayToLL(int arr[],int n){
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1;i<n;i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* deleteNthNode(Node* head , int x){
    if(head == NULL) return 0;
    if(x==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL){
        if(x==temp->next->data){
            Node* n = temp->next;
            temp->next = temp->next->next;
            delete n;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head = arrayToLL(arr,n);
    head = deleteNthNode(head,x);
    printLL(head);
    return 0;
}