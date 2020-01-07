from linkedlist import *

lista = LinkedList()

lista.head = Node(1)
second = Node(2)
third = Node(3)

lista.head.next = second
second.next = third

lista.printList()
