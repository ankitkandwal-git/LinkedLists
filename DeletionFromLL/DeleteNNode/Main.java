package LinkedLists.DeletionFromLL.DeleteNNode;

import java.util.Scanner;

class Main{
    static class Node{
        int data;
        Node next;
        Node(int val){
            this.data = val;
            this.next = null;
        }
    }
    public static Node arrayToLL(int[] arr,int n){
        Node temp = new Node(arr[0]);
        for(int i=1;i<n;i++){
            temp.next = new Node(arr[i]);
            temp = temp.next;
        }
        return temp;
    }
    public static void printLL(Node head){
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
    public static Node deleteNNode(Node head,int n){
        if(head == null) return null;
        if(n==1){
            Node temp = head;
            head.next = head;
            return head;
        }
        Node temp = head;
        while(temp.next != null){
            if(temp.next.data==n){
                Node x = temp.next;
                temp.next = temp.next.next;
                return head;
            }
            temp = temp.next;
        }
        return head;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter the size of LL: ");
            int n = sc.nextInt();
            System.out.print("Enter the element in LL: ");
            int[] arr = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            Node head = arrayToLL(arr,n);
            head = deleteNNode(head,n);
            printLL(head);
        }
    }
}