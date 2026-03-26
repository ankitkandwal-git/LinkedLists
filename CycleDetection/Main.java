package LinkedLists.CycleDetection;

import java.util.Scanner;

class Main{
    static class Node{
        int data;
        Node next;
        Node(int val){
            data = val;
            next = null;
        }
    }
    public static Node arrayToLL(int[]arr,int n){
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

    public static int detectCycle(Node head){
        Node slow = head;
        Node fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow==fast){
                return slow.data;
            }
        }
        return -1;
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
            System.out.print("Enter the position to create cycle: ");
            int pos = sc.nextInt();
            if(pos != -1){
                Node temp = head;
                Node cycleStartNode = null;
                int count = 1;
                while(temp.next != null){
                    if(count == pos){
                        cycleStartNode = temp;
                    }
                    temp = temp.next;
                    count++;
                }
                temp.next = cycleStartNode;
            }
            int cycleNode = detectCycle(head);
            if(cycleNode != -1){
                System.out.println("Cycle detected at node with value: " + cycleNode);
            }else{
                System.out.println("No cycle detected.");
            }
            
        }
    }
}