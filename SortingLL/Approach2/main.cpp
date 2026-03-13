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

Node* arrayToLL(vector<int> arr, int n){
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
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* sortLL(Node* head){
    Node* temp = head;
    Node* prev0 = NULL;
    Node* prev1 = NULL;
    Node* prev2 = NULL;
    Node* first0 = NULL;
    Node* first1 = NULL;
    Node* first2 = NULL;
    while(temp != NULL){
        if(temp->data ==0){
            if(first0==NULL){
                first0 = temp;
            }
            else{
                prev0->next = temp;
            }
            prev0 = temp;
        }
        else if(temp->data ==1){
            if(first1==NULL){
                first1 = temp;
            }
            else{
                prev1->next = temp;
            }
            prev1 = temp;
        }
        else if(temp->data ==2){
            if(first2==NULL){
                first2 = temp;
            }
            else{
                prev2->next = temp;
            }
            prev2 = temp;
        }
        temp = temp->next;
    }
    if(prev0 != NULL){
        if(first1 != NULL){
            prev0->next = first1;
        }
        else if(first2 != NULL){
            prev0->next = first2;
        }
    }
    if(prev1 != NULL){
        if(first2 != NULL){
            prev1->next = first2;
        }
    }
    if(prev2 != NULL){
        prev2->next = NULL;
    }
    if(first0 != NULL){
        return first0;
    }
    else if(first1 != NULL){
        return first1;
    }
    else{
        return first2;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Node* head = arrayToLL(arr, n);
    head = sortLL(head);
    printLL(head);
    return 0;
}