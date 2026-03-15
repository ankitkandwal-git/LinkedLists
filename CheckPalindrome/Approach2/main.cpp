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
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

bool checkPalindrome(Node* head){
    stack<int>st;
    Node* cur = head;
    while(cur != NULL){
        st.push(cur->data);
        cur = cur->next;
    }
    cur = head;
    while(cur != NULL){
        if(cur->data != st.top()){
            return false;
        }
        st.pop();
        cur = cur->next;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Node* head = arrayToLL(arr, n); 
    if(checkPalindrome(head)){
        cout<<"Yes it is Palindrome"<<endl;
    }
    else{
        cout<<" No it is not Palindrome"<<endl;
    }
}