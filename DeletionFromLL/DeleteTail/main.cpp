#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
      int data;
      Node* next;
      Node(int val){
            data = val;
            next = NULL;
      }
};

Node* arrayToLL(int arr[],int n){
    if(n==0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<n;i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<< " ";
        temp = temp->next;
    }
}

Node* deleteTail(Node* head){
    if(head ==NULL) return NULL;
    if(head->next ==NULL){
        delete head;
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* n = temp->next;
    temp->next = NULL;
    delete n;
    return head;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head = arrayToLL(arr,n);
    head = deleteTail(head);
    printLL(head);
    return 0;
 }