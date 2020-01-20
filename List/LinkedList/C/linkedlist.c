
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

//removes duplicates from a sorted list
void removeDuplicatesSort(struct Node* head)
{
	struct Node* current = head;

	struct Node* next_next;

	if(current == NULL)
		return;

	while(current->next != NULL)
	{
		if(current->data == current->next->data)
		{
			next_next = current->next->next;
			free(current->next);
			current->next = next_next;
		}
		else
		{
			current = current->next;
		}
	}
}

//removes duplicates from a unsorted linked list
void removeDuplicates(struct Node *head)
{
	struct Node *ptr1, *ptr2, *dup;
	ptr1 = head;

	while(ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;

		while(ptr2->next != NULL)
		{
			if(ptr1->data == ptr2->next->data)
			{
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(dup);
			}
			else
			{
				ptr2 = ptr2->next;
			}
		}

		ptr1 = ptr1->next;
	}
}

//return the last node of the list
struct Node *getTail(struct Node *cur)
{
	while(cur != NULL && cur->next != NULL)
		cur = cur->next;

	return cur;
}

//partitons the list talking the last element as the pivot
struct Node* partiton(struct Node *head, struct Node* end, struct Node** newHead, struct Node **newEnd)
{
	struct Node *pivot = end;
	struct Node *prev = NULL;
	struct Node *cur = head;
	struct Node *tail = pivot;

	while(cur != pivot)
	{
		if(cur->data < pivot->data)
		{
			if((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}
		else
		{
			if(prev)
				prev->next = cur->next;

			struct Node *temp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = temp;
		}
	}

	if((*newHead) == NULL)
		(*newHead) = pivot;

	(*newEnd) = tail;

	return pivot;
}

//here the sorting happens exclusive of the end node
struct Node *quickSortRecur(struct Node *head, struct Node *end)
{
	if(!head || head == end)
		return head;

	struct Node *newHead = NULL;
	struct Node *newEnd = NULL;

	struct Node *pivot = partiton(head, end, &head, &end);
	
	if(newHead != pivot)
	{
		struct Node *temp = newHead;

		while(temp->next != pivot)
			temp = temp->next;

		temp->next = NULL;

		newHead = quickSortRecur(newHead, temp);

		temp = getTail(newHead);
		temp->next = pivot;
	}
	
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;

}

//main function of quick sort
void quickSort(struct Node **head)
{
	(*head) = quickSortRecur(*head, getTail(*head));
	return;
}
