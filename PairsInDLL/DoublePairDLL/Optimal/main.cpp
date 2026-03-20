#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node* arrayToDLL(int arr[], int n){
    if(n == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for(int i=1; i<n; i++){
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }

    return head;
}

void printDLL(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

vector<pair<int,int>>findPairs(Node* head, int key){
    vector<pair<int,int>>ans;
    Node* left = head;
    Node* right = head;
    while(right->next) right = right->next;
    while(left->data < right->data){
        int x = left->data + right->data;
    if(x==key){
        ans.push_back({left->data, right->data});
        left = left->next;
        right = right->prev;
    }
    else if(x<key) left = left->next;
    else right = right->prev;
    }
    return ans;
}

int main(){
    int n,key;
    cin >> n>> key;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    Node* head = arrayToDLL(arr, n);
    vector<pair<int,int>>ans = findPairs(head, key);
    for(auto p: ans) cout << p.first << " " << p.second << endl;
    return 0;
}