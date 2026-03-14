#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

Node* arrayToLL(int arr[], int n){
    if(n == 0) return NULL;
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
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* deleteMiddle(Node* head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    int n = 0;
    Node* temp = head;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    int mid = n/2;
    temp = head;
    int count = 0;
    while(temp != NULL){
        if(count == mid-1){
            Node* toDelete  = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            break;
        }
        count ++;
        temp = temp->next;
    }
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
    head = deleteMiddle(head);
    printLL(head);
    return 0;
}