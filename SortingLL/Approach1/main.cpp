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

Node* sortLL(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* temp = head;
    int count_0 = 0, count_1 = 0, count_2 = 0;
    while(temp!= NULL){
        if(temp->data ==0){
            count_0++;
        }
        else if(temp->data ==1){
            count_1++;
        }
        else{
            count_2++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(count_0){
            temp->data = 0;
            count_0--;
        }
        else if(count_1){
            temp->data = 1;
            count_1--;
        }
        else{
            temp->data = 2;
            count_2--;
        }
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
    head = sortLL(head);
    printLL(head);
    return 0;
}