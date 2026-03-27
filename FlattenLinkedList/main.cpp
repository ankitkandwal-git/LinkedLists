#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* down;
    Node(int x){
        data = x;
        next = NULL;
        down = NULL;
    }
};

Node* arrayToLL(int arr[], int n){
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1; i<n; i++){
        curr->down = new Node(arr[i]);
        curr = curr->down;
    }
    return head;
}

void printLL(Node* head){
    Node* curr = head;
    while(curr){
        cout << curr->data << " ";
        curr = curr->down;
    }
    cout << endl;
}

Node* merge(Node* h1,Node* h2){
    Node* temp1 = h1;
    Node* temp2 = h2;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(temp1 & temp2){
        if(temp1->data <= temp2->data){
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;

        }
    }
    if(temp1) temp->next = temp1;
    else temp->next = temp2;
    return dummy->next;
}

Node* flattenLL(Node* head){
    Node* temp1 = head;
    Node* temp2 = head->next;
    Node* next;
    while(temp2){
        next = temp1->next;
        temp1 = merge(temp1,temp2);
        temp2 = next;
    }
    return temp1;
}

int main(){
    int n;
    cin >> n;
    Node* head = NULL;  
    Node* curr = NULL;
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        int arr[m];
        for(int j=0; j<m; j++){
            cin >> arr[j];
        }
        if(!head){
            head = arrayToLL(arr,m);
            curr = head;
        } else {
            curr->next = arrayToLL(arr,m);
            curr = curr->next;
        }
    }
    head = flattenLL(head);
    printLL(head);
}