#include<stdio.h>
#include<malloc.h>

struct Node{
	int data;
	struct Node *next;
};

void printList(struct Node *node)
{
	while(node !=NULL){
		printf("%d\n", node->data);
		node = node->next;
	}
}

void push(struct Node **head_ref, int new_data)
{
	/*1. Allocate Node*/
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node *last = *head_ref;

	/*2.Put in the data */
	new_node->data = new_data;

	/*3.Make next of new node as head*/
	new_node->next = (*head_ref);

	/*4. Move the head to point to the new node */
	(*head_ref) =  new_node;
}

void insertAfter(struct Node *prev_node, int new_data)
{
	if(prev_node == NULL){
		printf("The given previous node cannot be NULL");
		return;
	}

	/*2. Allocate new node*/
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

	/*3. Put in the data*/
	new_node->data =  new_data;

	/*4. Make next of new node as next of prev_node*/
	new_node->next = prev_node->next;

	/*5. Move the next of prev_node as new_node*/
	prev_node->next = new_node;
}

void append(struct Node **head_ref, int new_data)
{
	struct Node  *new_node =  (struct Node*)malloc(sizeof(struct Node));

	struct Node *last =  *head_ref;

	/*Put in the data*/
	new_node->data = new_data;

	/*New node is going to be the last node, so make next node NULL*/
	new_node->next = NULL;

	if(*head_ref == NULL){
		*head_ref=new_node;
		return;
	}

	/*Else traverse till last node*/
	while(last->next != NULL){
		last = last->next;
	}

	last->next = new_node;
	return;

}

int main()
{
	struct Node * head = NULL;

	append(&head,6);

	push(&head,7);

	push(&head,1);

	append(&head,4);

	insertAfter(head->next,8);

	printf("\n Created Linked List is: ");

	printList(head);

	return 0;

}
