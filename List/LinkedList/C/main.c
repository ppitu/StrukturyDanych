#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.c"

int main()
{

	struct Node *head = NULL;

	append(&head, 6);

	push(&head, 7);

	push(&head, 1);

	append(&head, 4);

	insertAfter(head->next, 8);

	printList(head);

	deleteNode(&head, 7);

	printList(head);

	//deleteList(&head);
	printf("\n");

	//printList(head);

	printf("%i\n", getCountIter(head));
	push(&head, 8);
	printf("%i\n", getCountRec(head));
	
	return 0;	
}
