#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* arrayToLL(int arr[], int n){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1; i<n; i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
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

Node* getKthNode(Node* head,int k){
    int count = 0;
    while(head != NULL && count !=k-1){
        head = head->next;
        count++;
    }
    if(count==k-1){
        return head;
    }
    else{
        return NULL;
    }
}

Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* cur = head;
    while(cur != NULL){
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

Node* reverseKGroup(Node* head,int k){
    Node* cur = head;
    Node* prev = NULL;
    Node* next;
    while(cur != NULL){
        Node* kthNode = getKthNode(cur,k);
        if(kthNode == NULL){
            break;
        }
        next = kthNode->next;
        kthNode->next = NULL;
        Node* newHead = reverseLL(cur);
        if(prev == NULL){
            head = newHead;
        }
        else{
            prev->next = newHead;
        }
        prev = cur;
        cur = next;
    }
    return head;

}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Node* head = arrayToLL(arr,n);
    head = reverseKGroup(head,k);
    printLL(head);
    return 0;
}