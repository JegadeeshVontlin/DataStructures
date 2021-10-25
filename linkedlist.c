#include<stdio.h>
#include<malloc.h>

struct Node {
	int  data;
	struct Node *next;
};

void printList(struct Node *n){
	while(n!= NULL){
		printf("%d\n",n->data);
		n=n->next;
	}
}

int main()
{
	struct Node *head, *second, *third;
	head  = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next= second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	printList(head);
}
