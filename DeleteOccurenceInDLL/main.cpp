#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node* arrayToLL(int arr[], int n){
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1; i<n; i++){
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }
    return head;
}

void printLL(Node* head){
    Node* curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

Node* deleteOccurrenceDLL(Node* head , int key){
    Node* cur = head;
    Node* prev;
    Node* next;
    while(cur){
        if(cur->data == key){
            if(cur==head) head = cur->next;
            prev = cur->prev;
            next = cur->next;
            if(prev) prev->next = next;
            if(next) next->prev = prev;
            delete cur;
            cur = next;
        }else{
            cur = cur->next;
        }
    }
    return head;
}

int main(){
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    Node* head = arrayToLL(arr,n);
    head = deleteOccurrenceDLL(head,key);
    printLL(head);
    return 0;
}