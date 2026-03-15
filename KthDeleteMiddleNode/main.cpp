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
    while(curr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* kthDeleteMidNode(Node* head, int k){
    if(!head) return NULL;
    if(k == 1) return head->next;
    Node* fast  = head;
    Node* slow = head;
    int count = 0;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        count++;
    }
    slow = head;
    for(int i=0;i<(count-k-1); i++){
        slow = slow->next;
    }
    if(slow->next != NULL){
        slow->next = slow->next->next;
    }
    return head;
}

int main(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    Node* head = arrayToLL(arr, n);
    head = kthDeleteMidNode(head, k);
    printLL(head);
    return 0;
}