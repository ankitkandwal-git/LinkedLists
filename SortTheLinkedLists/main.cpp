#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* arrayToLL(int arr[],int n){
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

Node* sortLL(Node* head){
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    Node* temp = head;
    vector<int>v;
    while(temp != NULL){
        v.push_back(temp->data);
        temp = temp->next;
    }
    sort(v.begin(),v.end());
    temp = head;
    for(int i=0;i<v.size();i++){
        temp->data = v[i];
        temp = temp->next;
    }
    return head;
}
int main(){
    int arr[] = {4,2,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = arrayToLL(arr,n);
    cout<<"Before sorting: ";
    printLL(head);
    head = sortLL(head);
    cout<<"After sorting: ";
    printLL(head);
    return 0;
}