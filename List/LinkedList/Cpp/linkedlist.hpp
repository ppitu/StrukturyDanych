#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

template <typename T>
class LinkedList
{
	public:
		void printList(Node* );

	private:

		struct Node
		{
			T data;
			Node* next;
		}

};

template <typename T>
LinkedList<T>::printList(Node* n)
{
	while(n != nullptr)
	{
		std::cout << n->data << " ";
		n = n->next;
	}
}

#endif //LINKEDLIST_HPP
