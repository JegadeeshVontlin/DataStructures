#include<stdio.h>
#include<string.h>
#include<malloc.h>


struct Node {
	int data;
	struct Node* next;
};

void PrintList(struct Node* List);

void PrintList(struct Node* List)
{
	while (List != NULL) {
		printf("%d\t", List->data);
		List = List->next;
	}
}

int main()
{

	/*Declaring and Initialization of Linked List variables */
	struct Node* head = NULL;
	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth = NULL;
	struct Node* fifth = NULL;
	struct Node* sixth = NULL;
	struct Node* temp = NULL;
	struct Node* temp2 = NULL;


	head   = (struct Node*)malloc(sizeof(struct Node));
	first  = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third  = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	fifth  = (struct Node*)malloc(sizeof(struct Node));
	sixth  = (struct Node*)malloc(sizeof(struct Node));
	temp   = (struct Node*)malloc(sizeof(struct Node));
	temp2  = (struct Node*)malloc(sizeof(struct Node));

	printf("0 is referred as head, not counted in list");
	/*Creating LinkedList*/
	head->data		= 0;
	head->next		= first;

	first->data = 1;
	first->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = fourth;

	fourth->data = 4;
	fourth->next = fifth;

	fifth->data = 5;
	fifth->next = sixth;

	sixth->data = 6;
	sixth->next = NULL;

	printf("Listing all the numbers\n");
	PrintList(head);
	printf("\n\n");

	/*Removing first one from linkedList and assigning it to temp*/
	printf("Removing first one from list\n");
	head->next = second;
	temp->next = first;

	PrintList(head);
	printf("\n\n");

	/*Remove Last one from LinkedList */
	printf("Removing last one from list\n");
	fifth->next = NULL;
	temp2->next = sixth;

	PrintList(head);
	printf("\n\n");

	/*Assigning last removed to first*/
	printf("Assign last removed to first\n");
	head->next  = sixth;
	sixth->next = second;
	temp2->next = NULL;

	PrintList(head);
	printf("\n\n");

	/*Assigning first removed to fifth*/
	printf("Assign first removed to fifth\n");
	fourth->next = first;
	first->next  = fifth;

	PrintList(head);
	printf("\n\n");

	/*Removing 6th put into last*/
	printf("Removing 6th put into last\n");
	fifth->next = sixth;
	sixth->next = NULL;

	head->next = second;

	PrintList(head);
	printf("\n\n");
}
