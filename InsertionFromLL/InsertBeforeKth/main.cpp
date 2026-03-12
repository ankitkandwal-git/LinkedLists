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
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* insertBeforeKthIndex(Node* head , int k, int x){
    if (k == 0) {
        Node* newNode = new Node(x);
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < k - 1) {
        temp = temp->next;
        count++;
    }
    if (temp != NULL) {
        Node* newNode = new Node(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

int main(){
    int n,k,x;
    cin>>n>>k>>x;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head = arrayToLL(arr,n);
    head = insertBeforeKthIndex(head,k,x);
    printLL(head);
    return 0;
}