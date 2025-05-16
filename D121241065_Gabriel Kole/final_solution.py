class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        

def print_singly_linked_list(node, sep=' => '):
    while node:
        print(node.data, end='')
        node = node.next
        if node:
            print(sep, end='')
    print()

def insertNodeAtHead(llist, data):
    new_node = SinglyLinkedListNode(data)
    new_node.next = llist
    return new_node

if __name__ == '__main__':
    llist_count = int(input("Input : "))

    llist = SinglyLinkedList()

    for _ in range(llist_count):
        llist_item = int(input())
        llist.head = insertNodeAtHead(llist.head, llist_item)

    print_singly_linked_list(llist.head)

    