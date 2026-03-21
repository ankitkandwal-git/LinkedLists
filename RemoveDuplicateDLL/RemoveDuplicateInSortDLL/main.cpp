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
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* removeDuplicate(Node* head){
    if(head ==NULL) return head;
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr){
        prev = curr->prev;
        next = curr->next;
        if(prev && curr->data == prev->data){
            prev->next = next;
            if(next) next->prev = prev;
            delete curr;
        }
        curr = next;
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    Node* head = arrayToLL(arr, n);
    head = removeDuplicate(head);
    printLL(head);
    return 0;
}