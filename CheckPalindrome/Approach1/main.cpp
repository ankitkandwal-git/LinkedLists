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

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* cur = head;
    Node* front = NULL;
    while(cur != NULL){
        front = cur->next;
        cur->next = prev;
        prev = cur;
        cur = front;
    }
    return prev;
}

bool checkPalindrome(Node* head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* revHead = reverse(slow);
    Node* temp = head;
    while(temp != NULL && revHead != NULL){
        if(temp->data != revHead->data){
            reverse(revHead);
            return false;
        }
        temp = temp->next;
        revHead = revHead->next;
    }
    reverse(revHead);
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
        cout << " Yes it is Palindrome" << endl;
    }
    else{
        cout << "Not Palindrome" << endl;
    }
    return 0;
}