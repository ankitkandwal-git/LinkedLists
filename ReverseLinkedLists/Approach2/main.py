class Node:
    data = None
    next =  None
    def __init__(self, data):
        self.data = data
        self.next = None
def array_to_LL(arr, n):
    if n == 0:
        return None
    head = Node(arr[0])
    current = head
    for i in range(1, n):
        current.next = Node(arr[i])
        current = current.next
    return head

def print_LL(head):
    temp = head
    while temp is not None:
        print(temp.data, end = " ")
        temp = temp.next
    print()
    
def reverse_LL(head):
    temp = head
    prev = None
    while temp is not None:
        next_node = temp.next
        temp.next = prev
        prev = temp
        temp = next_node
    return prev 

n = int(input("Enter the size of Linked List: "))
result = list(map(int,input("Enter the Linked List elements: ").strip().split()))[:n]   
head = array_to_LL(result, n)
head = reverse_LL(head)
print("Reversed Linked List: ", end = "")
print_LL(head)