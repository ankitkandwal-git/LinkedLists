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
    Node* tail = head;
    for(int i=1; i<n; i++){
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* evenAndOdd(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* even = head;
    Node* odd = head->next;
    Node* oddHead = head->next;
    while(odd != NULL && odd->next != NULL){
        even->next = even->next->next;
        odd->next = odd->next->next;
        even = even->next;
        odd = odd->next;
    }
    even->next = oddHead;
    return head;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Node* head = arrayToLL(arr, n);
    head = evenAndOdd(head);
    printLL(head);
    return 0;
}