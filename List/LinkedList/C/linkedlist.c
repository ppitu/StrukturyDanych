
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
