#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

	int data;
	struct node* next;
}node;

node* createNode(int data){

	node* new  = (node*) malloc(sizeof(node));
	new->data= data;
	new->next = NULL;
	return new;
}

void append(node** headRef,int newData){

	node* new = createNode(newData); //creating the node to be added
	if(*headRef == NULL){
		//empty link list
		*headRef = new;
		return;
	}
	node* current = *headRef;
	while(current->next != NULL){
		current = current->next;
	}

	current->next = new;
	return;
}

void push(node **headRef, int newData){
	node* new = createNode(newData); //creating the node to be pushed
	if(*headRef == NULL){
		//empty link list
		*headRef = new;
		return;
	}
	new->next = *headRef;
	*headRef = new;
}


void printList(node* head){

	node* current = head;
	printf("start of list ");
	while(current!=NULL){
		printf("-- %i ",current->data);
		current = current->next;
	}
	printf(" -- end of list\n");
}


void recursivePrint(node* head){
	if(head==NULL) return;
	printf("-- %i ",head->data);
	recursivePrint(head->next);

}
void recursivePrintR(node* head){
	if(head==NULL) return;
	recursivePrintR(head->next);
	printf("-- %i ",head->data);
}

int countElement(node* head, int key){
	node* current = head;
	int count = 0;
	while(current!=NULL){
		if(current->data == key) count++;
		current = current->next;
	}
	return count;
}

void moveLastToFirst(node **headRef){
	node* secLast = *headRef;
	node* last = secLast->next;
	while(last->next!=NULL){
		secLast = secLast->next;
		last = last->next;
	}
	secLast->next = NULL;
	last->next= *headRef;
	*headRef = last;
}

int main(){

	node* head = NULL;
	printList(head);
	append(&head,9);
	printList(head);
	append(&head,10);
	printList(head);
	append(&head,11);
	printList(head);
	push(&head,1);
	printList(head);
	append(&head,11);
	//recursiveReverse(&head);
	printf("calling recursivePrint\n");
	recursivePrint(head);
	printf("\ncalling recursivePrint Reverse\n");
	recursivePrintR(head);
	printf("\ncount of key 11 in the list : %i \n",countElement(head,11));
	printList(head);
	printf("calling moveLastToFirst()\n");
	moveLastToFirst(&head);
	printList(head);
	return 0;
}