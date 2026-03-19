class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

def arrayToLL(arr,n):
    if n == 0:
        return None
    head = Node(arr[0])
    curr = head
    for i in range(1, n):
        new_node = Node(arr[i])
        curr.next = new_node
        new_node.prev = curr
        curr = new_node
    return head

def printLL(head):
    while head:
        print(head.data,end=" ")
        head = head.next
        
def deleteOccurenceDLL(head,x):
    cur = head
    while cur:
        next_node = cur.next
        if cur.data == x:
            if cur.prev:
                cur.prev.next = cur.next
            else:
                head = cur.next
            if cur.next:
                cur.next.prev = cur.prev
        cur = next_node
    return head

if __name__ == "__main__":
    n = int(input("Enter the number of elements in the linked list: "))
    x = int(input("Enter the x value: "))
    arr = list(map(int, input("Enter the elements of the linked list: ").split()))
    head = arrayToLL(arr, n)
    head = deleteOccurenceDLL(head, x)
    printLL(head)