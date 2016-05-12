#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *next;
} node;

void push(node** headRef, int newData){

	node* newNode = (node*) malloc(sizeof(node));
	newNode->data = newData;
	newNode->next = *headRef;
	(*headRef) = newNode;

}

void printList(node* head){
	node *current = head;
	while(current!=NULL){
		printf("%i\n",current->data);
		current = current->next;
	}
}
void deleteNode(node **headRef, int key){
	node *temp = *headRef;
	node *prev;

	if(temp!= NULL && temp->data == key){
		*headRef = temp->next;
		free(temp);
		return;
	}

	while(temp!= NULL && temp->data !=key){
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL) return;
	prev->next = temp->next;
	free(temp);

}

void deleteAtPosition(node **headRef, int position){

	if (*headRef == NULL)
      return;

	node *temp = *headRef;
	node *prev;

	if(position==0){
		*headRef = temp->next;
		free(temp);
		return;
	}
	int i=0;
	for(;temp != NULL && i<=position -1 ; i++){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);


}

int main(){

	node* head = NULL;
	push(&head,1);
	push(&head,2);
	printList(head);
	deleteNode(&head,1);
	push(&head,3);
	push(&head,4);
	printList(head);
	deleteAtPosition(&head,1);
	printList(head);

	return 0;
}