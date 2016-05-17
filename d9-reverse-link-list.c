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

void reverseI(node** headRef){

	node* prev;
	node* current;
	node* temp;
	current = *headRef;
	prev = NULL;
	while(current!=NULL){
		temp = current->next;
		current->next=prev;
		prev = current;
		current = temp;
	}
	*headRef = prev;

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

void recursiveReverse(node** headRef){
	node* first;
	node* rest;

	if(*headRef == NULL){
		return;
	}

	first =*headRef;
	rest = first->next;

	if(rest == NULL){
		return;
	}

	recursiveReverse(&rest);

	first->next->next = first;
	first->next = NULL;
	*headRef = rest;


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
	reverseI(&head);
	printList(head);
	recursiveReverse(&head);
	printList(head);
	return 0;
}