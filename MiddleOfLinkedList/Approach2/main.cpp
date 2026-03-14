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

Node* arrayToLL(int arr[], int n){
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1; i<n; i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
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

Node* middle(Node* head){
    if(head==NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Node* head = arrayToLL(arr, n);
    Node* mid = middle(head);
    cout << mid->data << endl;
    return 0;
}