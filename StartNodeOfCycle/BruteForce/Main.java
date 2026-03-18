
package LinkedLists.StartNodeOfCycle.BruteForce;
import java.util.Scanner;

public class Main {
    static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static Node arrayToLL(int[] arr, int n) {
        Node head = new Node(arr[0]);
        Node temp = head;
        for (int i = 1; i < n; i++) {
            temp.next = new Node(arr[i]);
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
    }

    public static Node startNodeOfCycle(Node head){
        Node slow = head;
        Node fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                slow = head;
                while(fast != slow){
                    slow = slow.next;
                    fast = fast.next;
                }
                return slow;
            }
        }
        return null;
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the size of LL:");
            int n = sc.nextInt();
            System.out.println("Enter the elements of LL:");
            int[] arr = new int[n];
            for(int i = 0; i < n; i++){
                arr[i] = sc.nextInt();
            }
            Node head = arrayToLL(arr, n);
            System.out.println("Enter the position of cycle:");
            int pos = sc.nextInt();
            if(pos != -1){
                Node temp = head;
                Node cycleStartNode = null;
                for(int i = 0; i < n; i++){
                    if(i == pos){
                        cycleStartNode = temp;
                    }
                    if(i == n - 1){
                        temp.next = cycleStartNode;
                    }
                    temp = temp.next;
                }
            }
            Node startNode = startNodeOfCycle(head);
            if(startNode != null){
                System.out.println("The start node of the cycle is: " + startNode.data);
            } else {
                System.out.println("No cycle detected.");
            }
        }
    }
}
