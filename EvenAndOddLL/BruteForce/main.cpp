#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
    public:
        Node(int value, Node* address){
            data = value;
            next = address;
        }
    public:
        Node(int value){
            data = value;
            next = nullptr;
        }
    public:
        Node(){
            data = 0;
            next = nullptr;
        }
};

Node* array_to_LL(int arr[], int n){
    if(n == 0){
        return nullptr;
    }
    Node* head = new Node(arr[0]);
    Node* cur = head;
    for(int i=1; i<=n-1; i++)
    {
        Node* temp = new Node(arr[i]);
        cur->next = temp;
        cur = cur->next;
    }
    return head;
}
void print_LL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
}

Node* even_odd_list(Node* head){
    Node* temp = head;
    vector<int> v;
    
    while(temp != nullptr && temp->next != nullptr){
        v.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp != nullptr){
        v.push_back(temp->data);
    }
    temp = head->next;
    
    while(temp != nullptr && temp->next != nullptr){
        v.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp != nullptr){
        v.push_back(temp->data);
    }
    
    temp = head;
    for (int i = 0; i < v.size(); i++){
        temp->data = v[i];
        temp = temp->next;
    }
    return head;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Node* head = array_to_LL(arr, n);
    head = even_odd_list(head);
    print_LL(head);
    return 0;
}
