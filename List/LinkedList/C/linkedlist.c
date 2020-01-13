
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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

//Delete the first occurrence of key
void deleteNode(struct Node **headref, int key)
{
	struct Node* temp = *headref, *prev;

	if(temp != NULL && temp->data == key)
	{
		*headref = temp->next;
		free(temp);
		return;
	}
	
	while(temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL)
		return;

	prev->next = temp->next;

	free(temp);

}

//Detele the entire linked list
void deleteList(struct Node** headref)
{
	struct Node* current = *headref;
	struct Node* next;

	while(current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*headref = NULL;
}

//Counts no. of node in list iterative
int getCountIter(struct Node* headref)
{
	int count = 0;

	struct Node* current = headref;

	while(current != NULL)
	{
		count++;
		current = current->next;
	}

	return count;
}

//Counts no. of node in list recursive
int getCountRec(struct Node* headref)
{
	if(headref == NULL)
		return 0;

	return 1 + getCountRec(headref->next);
}

//check whether the value x is present
bool search(struct Node* headref, int x)
{
	struct Node* current = headref;

	while(current != NULL)
	{
		if(current->data == x)
			return true;

		current = current->next;
	}

	return false;
}

//return data at index
int getNthIter(struct Node* head, int index)
{
	struct Node* current = head;

	int count = 0;

	while(current != NULL)
	{
		if(count == index)
		{
			return (current->data);
		}

		count++;
		current = current->next;
	}

	assert(0);
}

//return data at index
int getNthRec(struct Node* head, int index)
{
	int count = 1;

	if(count == index)
		return head->data;

	return getNthRec(head->next, index - 1);
}

//print middle of the list
void printMiddle(struct Node* head)
{
	struct Node *slow_ptr = head;
	struct Node *fast_ptr = head;

	if(head != NULL)
	{
		while(fast_ptr != NULL && fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}

		printf("The middle element is [%d]\n", slow_ptr->data);
	}
}
