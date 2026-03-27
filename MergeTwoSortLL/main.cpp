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

Node* arrayToLL(const vector<int>& arr){
    if(arr.empty()) return NULL;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for(int i=1; i<(int)arr.size(); i++){
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

Node* mergeTwoSortedLL(Node* head1, Node* head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummy = new Node(-1);
    Node* tail = dummy;
    while(temp1 && temp2){
        if(temp1->data <= temp2->data){
            tail->next = temp1;
            tail = tail->next;
            temp1 = temp1->next;
        }
        else{
            tail->next = temp2;
            tail = tail->next;
            temp2 = temp2->next;
        }
    }
    if(temp1) tail->next = temp1;
    if(temp2) tail->next = temp2;
    return dummy->next;
}

int main(){
    int m,n;
    cout<<"Enter size of first linked list: ";
    cin>>m;
    cout<<"Enter size of second linked list: ";
    cin>>n;
    vector<int> arr1(m), arr2(n);
    cout<<"Enter elements of first linked list: ";
    for(int i=0; i<m; i++) cin>>arr1[i];
    cout<<"Enter elements of second linked list: ";
    for(int i=0; i<n; i++) cin>>arr2[i];
    Node* head1 = arrayToLL(arr1);
    Node* head2 = arrayToLL(arr2);
    Node* mergedHead = mergeTwoSortedLL(head1, head2);
    cout<<"Merged linked list: ";
    printLL(mergedHead);
}