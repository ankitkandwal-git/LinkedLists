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

Node* getKNode(Node* head,int k){
    Node* temp = head;
    int count = 0;
    while(temp && count !=k-1){
        temp = temp->next;
        count++;
    }
    if(count==k-1) return temp;
    else return NULL;
}

Node* rotatek(Node* head,int k){
    if(!head) return head;
    int count = 1;
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
        count++;
    }
    k = k % count;
    if(k==0) return head;
    k = count - k;
    Node* cur = getKNode(head,k);
    tail->next = head;
    head = cur->next;
    cur->next = NULL;
    return head;
}
int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];
    Node* head = arrayToLL(arr,n);
    cout<<"Enter the value of k: ";
    int k;
    cin>>k;
    head = rotatek(head,k);
    cout<<"Rotated Linked List: ";
    printLL(head);
    return 0;
}