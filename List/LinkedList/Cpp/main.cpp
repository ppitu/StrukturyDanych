#include <iostream>

#include "linkedlist.hpp"

int main()
{

	LinkedList<int> x1;

	x1.push(2);
	x1.push(4);
	x1.push(5);
	x1.push(7);
	x1.push(9);
	x1.append(3);
	x1.push(1);

	x1.printList();
	std::cout << std::endl;

	x1.deleteNode(1);
	x1.printList();
	std::cout << std::endl;

	x1.deleteNode(5);
	x1.printList();

}
