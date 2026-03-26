package LinkedLists.ReverseLinkedLists.Approach2;
import java.util.Scanner;
public class Main {
    public static class Node{
        int data;
        Node next;
        Node(int val){
            this.data = val;
            this.next = null;
        }
    }
    public static Node arrayToLL(int[]arr,int n){
        Node head = new Node(arr[0]);
        for(int i=1;i<n;i++){
            head.next = new Node(arr[i]);
            head = head.next;
        }
        return head;
    }
    
    public static void printLL(Node head){
        while(head != null){
            System.out.print(head.data+" ");
            head = head.next;
        }
    }
    public static Node reverseLL(Node head){
        Node prev = null;
        Node temp = head;
        while(temp != null){
            Node next = temp.next;
            temp.next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the size of the linked list:");
            int n = sc.nextInt();
            int[] arr = new int[n];
            System.out.println("Enter the elements of the linked list:");
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            Node head = arrayToLL(arr,n);
            head = reverseLL(head);
            printLL(head);
        }
    }
}
