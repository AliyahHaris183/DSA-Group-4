import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

def print_singly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))

        node = node.next

        if node:
            fptr.write(sep)

# Lengkapi fungsi insertNodeAtHead di bawah ini

def insertNodeAtHead(llist, data):
    # Membuat node baru dengan data yang diberikan
    new_node = SinglyLinkedListNode(data)
    
    # Node baru menunjuk ke head yang lama
    new_node.next = llist
    
    # Mengembalikan node baru sebagai head yang baru
    return new_node

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    llist_count = int(input())  # Membaca jumlah node

    llist = SinglyLinkedList()

    for _ in range(llist_count):
        llist_item = int(input())  # Membaca data untuk node baru
        llist.head = insertNodeAtHead(llist.head, llist_item)  # Sisipkan node baru di head
    
    # Mencetak linked list
    print_singly_linked_list(llist.head, '\n', fptr)
    fptr.write('\n')
    
    fptr.close()

