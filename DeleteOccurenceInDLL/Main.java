package LinkedLists.DeleteOccurenceInDLL;
import java.util.Scanner;

public class Main{
    static class Node{
        int data;
        Node prev;
        Node next;
        Node(int data){
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }
    public static Node arrayToLL(int arr[], int n){
        Node head = new Node(arr[0]);
        Node temp = head;
        for(int i=1; i<n; i++){
            Node newNode = new Node(arr[i]);
            temp.next = newNode;
            newNode.prev = temp;
            temp = temp.next;
        }
        return head;
    }
    public static void printLL(Node head){
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static Node deleteOccurrenceDLL(Node head, int key){
        Node temp = head;
        Node prev = null;
        Node next;
        while(temp != null){
            if(temp.data==key){
                if(temp==head) head = temp.next;
                prev = temp.prev;
                next = temp.next;
                if(prev != null) prev.next = next;
                if(next != null) next.prev = prev;
                temp = next;
            }
            else{
                temp = temp.next;
            }
        }
        return head;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the number of elements in the linked list:");
            int n = sc.nextInt();
            int[] arr = new int[n];
            for(int i=0; i<n; i++){
                arr[i] = sc.nextInt();
            }
            Node head = arrayToLL(arr, n);
            System.out.println("Enter the key to be deleted:");
            int key = sc.nextInt();
            head = deleteOccurrenceDLL(head, key);
            printLL(head);
        }
    }
}