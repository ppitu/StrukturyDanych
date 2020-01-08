#include <iostream>

#include "linkedlist.hpp"

int main()
{

	LinkedList<int> x1;

	x1.push(2);
	x1.push(4);
	x1.append(3);
	x1.push(1);

	x1.printList();

}
