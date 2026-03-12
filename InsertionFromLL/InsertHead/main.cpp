#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* arrayToLL(int arr[],int n){
    Node* head = new Node(arr[0]);
    Node* cur = head;
    for(int i=1;i<n;i++){
        cur->next = new Node(arr[i]);
        cur = cur->next;
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

Node* insertAtHead(Node* head, int x){
    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
    return newNode;
}

int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head = arrayToLL(arr,n);
    head = insertAtHead(head,x);
    printLL(head);
    return 0;
}