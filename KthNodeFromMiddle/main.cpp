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
    Node* cur = head;
    for(int i=1;i<n;i++){
        cur->next = new Node(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printLL(Node* head){
    Node* cur = head;
    while(cur){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

Node* kthNodeFromMiddle(Node* head , int k){
    if(head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    int count = 0;
    while(fast && fast->next){
        slow = slow->next;
        fast  = fast->next->next;
        count++;
    }
    int target = count-k;
    if(target<0) return NULL;
    Node* cur = head;
    for(int i=0;i<target;i++){
        cur = cur->next;
    }
    return cur;
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head = arrayToLL(arr,n);
    Node* ans = kthNodeFromMiddle(head,k);
    if(ans) cout<<ans->data<<endl;
    else cout<<"NULL"<<endl;
    return 0;
}