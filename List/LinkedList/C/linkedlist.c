
#include <stdio.h>
#include <stdlib.h>

//A linked list node
struct Node
{
	int data;
	struct Node* next;
};

//Function prints contents of list
void printList(struct Node* n)
{
	while(n != NULL)
	{
		printf("%d ", n->data);
		n = n->next;
	}
}

//Insert a new node on the front od list
void push(struct Node** head_ref, int data)
{
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); //allocate node

	newnode->data = data; //put in the data

	newnode->next = (*head_ref); //make next of new node as head

	(*head_ref) = newnode; //move the head to point to the new node
}

//Insert a new node after the prev node
void insertAfter(struct Node* prevnode, int data)
{
	//check prev node == NULL
	if(prevnode == NULL)
	{
		return;
	}

	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); //allocate new node
	newnode->data = data; //put in the data
	newnode->next = prevnode->next;  //make newnode next as prevnode next
	prevnode->next = newnode;
}

//Insert a new node on the end of list
void append(struct Node** headref, int data)
{
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	
	struct Node *last = *headref;
	
	newnode->data = data;

	newnode->next = NULL;

	if(*headref == NULL)
	{
		*headref = newnode;
		return;
	}

	while(last->next != NULL)
		last = last->next;

	last->next = newnode;

	return;
}
