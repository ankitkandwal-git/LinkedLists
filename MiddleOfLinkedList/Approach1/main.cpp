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
    Node* head = NULL;
    Node* tail = NULL;
    for(int i=0; i<n; i++){
        Node* newNode = new Node(arr[i]);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* middleOfLL(Node* head){
    if(head==NULL){
        return NULL;
    }
    int n = 0;
    int  count = 0;
    Node* temp = head;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    int middle = n/2;
    temp = head;
    while(temp != NULL && middle>0){
        if(middle == count){
            break;
        }
        count++;
        temp =  temp->next;
    }
    return temp;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Node* head = arrayToLL(arr, n);
    // printLL(head);
    Node* middle = middleOfLL(head);
    if(middle != NULL){
        cout<<"Middle of the linked list is: "<<middle->data<<endl;
    }
    else{
        cout<<"Linked list is empty"<<endl;
    }
    return 0;
}