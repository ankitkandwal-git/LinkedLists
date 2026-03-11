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

Node* arrayToLL(int arr[], int n){
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
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* deletekNode(Node* head,int k){
    if(head == NULL) return NULL;
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    int count = 0;
    while(temp->next != NULL){
        if(count==k-1){
            Node* todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;
            count = 0;
        }
        else{
            count++;
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head = arrayToLL(arr,n);
    head = deletekNode(head,k);
    printLL(head);
    return 0;
}