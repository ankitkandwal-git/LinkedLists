package LinkedLists.StartNodeOfCycle.BruteForce;
import java.util.Scanner;
import java.util.HashMap;
public class Main {
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    };
    
    public static Node arrayToLL(int[] arr, int n){
        Node head = new Node(arr[0]);
        Node temp = head;
        for(int i=1;i<n;i++){
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
        HashMap<Node, Integer>  map = new HashMap<>();
        Node temp = head;
        while(temp != null){
            if(map.containsKey(temp) ){
                return temp;
            }
            map.put(temp, 1);
            temp = temp.next;
        }
        return null;
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the size of LL:");
            int n = sc.nextInt();
            System.out.println("Enter the elements of LL:");
            int[] arr = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            Node head = arrayToLL(arr, n);
            System.out.println("Enter the position of cycle:");
            int pos = sc.nextInt();
            if(pos != -1){
                Node temp = head;
                Node startNode = null;
                for(int i=0;i<n;i++){
                    if(i == pos){
                        startNode = temp;
                    }
                    temp = temp.next;
                }
                temp.next = startNode;
            }
            Node ans = startNodeOfCycle(head);
            if(ans != null){
                System.out.println("The starting node of cycle is: " + ans.data);
            }else{
                System.out.println("No cycle found in the linked list.");
            }
        }
    }
}
