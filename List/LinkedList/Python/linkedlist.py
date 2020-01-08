
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None;

class LinkedList:
	def __init__(self):
		self.head = None;

	def push(self, data):
		newnode = Node(data)
		
		newnode.next = self.head

		self.head = newnode

	def append(self, data):
		newnode = Node(data)

		if self.head is None:
			self.head = newnode
			return

		last = self.head

		while(last.next):
			last = last.next

		last.next = newnode

	def printList(self):
		temp = self.head
		while(temp):
			print(temp.data)
			temp = temp.next
