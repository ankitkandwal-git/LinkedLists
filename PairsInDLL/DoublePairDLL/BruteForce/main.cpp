#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node* arrayToLL(int arr[], int n){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<n;i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
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

vector<pair<int,int>> getPairs(Node* head, int x){
    vector<pair<int,int>>ans;
    Node* left = head;
    while(left){
        Node* right = left->next;
        while(right){
            if(left->data + right->data ==x ){
                ans.push_back({left->data, right->data});
            }
            right = right->next;
        }
        left = left->next;
    }
    return ans;
}

int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head = arrayToLL(arr,n);
    vector<pair<int,int>>ans = getPairs(head,x);
    for(auto p: ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}