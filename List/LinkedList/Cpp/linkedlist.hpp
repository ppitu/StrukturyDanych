#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

template <typename T>
class LinkedList
{
	public:
		LinkedList() : head(nullptr) {};
		void printList();
		void push(T );
		void append(T );
		void deleteNode(T );

	private:

		struct Node
		{
			T data;
			Node* next;
			
			Node(T data) : next{nullptr}, data(data) {}
			Node(Node* next, T data) : next(next), data(data) {}
		};

		Node* head;

};

template <typename T>
void LinkedList<T>::printList()
{
	typename LinkedList<T>::Node* n = head;
	
	while(n != nullptr)
	{
		std::cout << n->data << " ";
		n = n->next;
	}
}

template <typename T>
void LinkedList<T>::push(T data)
{
	typename LinkedList<T>::Node* newnode = new Node(head, data);

	head = newnode;
}

template <typename T>
void LinkedList<T>::append(T data)
{
	typename LinkedList<T>::Node* newnode = new Node(data);

	typename LinkedList<T>::Node* last = head;

	if(head == nullptr)
	{
		head = newnode;
		return;
	}

	while(last->next != nullptr)
		last = last->next;

	last->next = newnode;
}

template <typename T>
void LinkedList<T>::deleteNode(T data)
{
	typename LinkedList<T>::Node *temp = head;
	typename LinkedList<T>::Node *prev;

	if(temp != NULL && temp->data == data)
	{
		head = temp->next;
		delete(temp);
		return;
	}

	while(temp != NULL && temp->data != data)
	{
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL)
		return;

	prev->next = temp->next;

	delete(temp);
}

#endif //LINKEDLIST_HPP
