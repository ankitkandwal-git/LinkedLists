#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
      int data;
      Node* next;
      Node(int val){
        this->data = val;
        this->next = NULL;
      }
};

Node* arrayToLL(int arr[],int n){
    if(n==0) return NULL;
    Node* head = new Node(arr[0]);
    Node* cur = head;
    for(int i=1;i<n;i++){
        Node* temp = new Node(arr[i]);
        cur->next = temp;
        cur = cur->next;
    }
    return head;
}

void printLL(Node* head){
    Node* cur = head;
    while(cur != NULL){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
}

Node* deleteHead(Node* head){
    if(head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head = arrayToLL(arr,n);
    head = deleteHead(head);
    printLL(head);
    return 0;
}