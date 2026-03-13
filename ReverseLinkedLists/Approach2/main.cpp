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

Node* arrayToLL(vector<int>&arr,int n){
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

Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* cur = head;
    Node* front = head->next;
    while(cur !=NULL){
        front = cur->next;
        cur->next = prev;
        prev = cur;
        cur = front;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head = arrayToLL(arr,n);
    cout<<"Original Linked List: ";
    printLL(head);
    head = reverseLL(head);
    cout<<"Reversed Linked List: ";
    printLL(head);
    return 0;
}