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

Node* startNodeCycle(Noed* head){
    map<Node*,int>m;
    Node* temp = head;
    while(temp != NULL){
        if(m.find(temp) != m.end()){
            m[temp] = 0;
        }
        else return temp;
        temp = temp->next;
    }
    return NULL;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Node* head = arrayToLL(arr,n);
    head = startNodeCycle(head);
    if(head == NULL) cout<<"No cycle";
    else cout<<head->data;
}