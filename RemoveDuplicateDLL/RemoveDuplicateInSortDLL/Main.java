package LinkedLists.RemoveDuplicateDLL.RemoveDuplicateInSortDLL;

import java.util.Scanner;


class Main{
    static class Node{
        int data;
        Node next;
        Node prev;

        Node(int data){
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    };
    public static Node arrayToDLL(int[] arr, int n) {
        Node head = new Node(arr[0]);
        Node curr = head;
        for (int i = 1; i < n; i++) {
            Node temp = new Node(arr[i]);
            curr.next = temp;
            temp.prev = curr;
            curr = temp;
        }
        return head;
    }
    public void printDLL(Node head){
        Node temp = head;
        while(temp!=null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
    }

    public static Node removeDuplicate(Node head){
    Node cur = head;
    while(cur != null) {
        Node prev = cur.prev;
        Node next = cur.next;
        if(prev != null && cur.data == prev.data){
            prev.next = next;
            if(next != null) next.prev = prev;
            cur = next; // advance after removal
        } else {
            cur = cur.next;
        }
    }
    return head;
}
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int[]arr = new int[n];
            for(int i=0;i<n;i++) arr[i] = sc.nextInt();
            Node head = arrayToDLL(arr,n);
            head = removeDuplicate(head);
            Main m = new Main();
            m.printDLL(head);
        }
    }
}