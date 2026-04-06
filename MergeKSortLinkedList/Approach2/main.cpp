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
    for(int i=1;i<n;i++){
        head->next = new Node(arr[i]);
        head = head->next;
    }
    return head;
}

void printLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* mergeKList(vector<Node*>&arr){
    priority_queue<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
    int k = arr.size();
    if(k==0) return NULL;
    if(k==1) return arr[0];
    Node* cur = new Node(-1);
    for(int i=0;i<k;i++){
        if(arr[i]){
            pq.push({arr[i]->data,arr[i]}); 
        }
    }
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        cur->next = x.second;
        cur = cur->next;
        if(x.second->next){
            pq.push({x.second->next->data,x.second->next});
        }
    }
    return cur->next;
}
int main(){
    int k,n;
    cin>>k>>n;
    vector<Node*>arr(k);
    for(int i=0;i<k;i++){
        Node* head = new Node(-1);
        Node* cur = head;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            cur->next = new Node(x);
            cur = cur->next;
        }
        arr[i] = head->next;
    }
    Node* ans = mergeKList(arr);
    while(ans){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    cout<<endl;
    return 0;

}