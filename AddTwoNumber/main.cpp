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
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* addTwoNumbers(Node* L1 ,Node* L2){
    Node* temp1 = L1;
    Node* temp2 = L2;
    int carry = 0;
    Node* ans = new Node(-1);
    Node* cur = ans;
    cur =  ans;
    while(temp1 || temp2){
        int sum = carry;
        if(temp1){
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if(temp2){
            sum += temp2->data;
            temp2 = temp2->next;
        }
        cur->next = new Node(sum%10);
        carry = sum/10;
        cur = cur->next;
    }
    if(carry==1){
        cur->next = new Node(1);
    }
    return ans->next;
}

int main(){
    int m,n;
    cin>>m>>n;
    int arr1[m],arr2[n];
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    Node* L1 = arrayToLL(arr1,m);
    Node* L2 = arrayToLL(arr2,n);
    Node* ans = addTwoNumbers(L1,L2);
    printLL(ans);
    return 0;
}