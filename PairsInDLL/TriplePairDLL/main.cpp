vector<tuple<int,int,int>> getTriplets(Node* head, int x) {
    vector<tuple<int,int,int>> result;
    for(Node* first = head; first != NULL; first = first->next) {
        for(Node* second = first->next; second != NULL; second = second->next) {
            for(Node* third = second->next; third != NULL; third = third->next) {
                if(first->data + second->data + third->data == x) {
                    result.push_back({first->data, second->data, third->data});
                }
            }
        }
    }
    return result;
}
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

void printLL(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

vector<pair<int,int>>getPairs(Node* head,int x){
    vector<pair<int,int>>result;
    Node* first = head;
    Node* second = head;
    while(second->next != NULL){
        second = second->next;
    }
    while(first != NULL && second != NULL && first != second && first->data < second->data){
        int sum = first->data + second->data;
        if(sum == x){
            result.push_back({first->data,second->data});
            if(result.size() == 3) break;
            first = first->next;
            second = second->prev;
        }
        else if(sum < x){
            first = first->next;
        }
        else{
            second = second->prev;
        }
    }
    return result;
}

int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Node* head = arrayToDLL(arr,n);
    vector<tuple<int,int,int>> triplets = getTriplets(head,x);
    for(auto t: triplets){
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    }
    return 0;
}