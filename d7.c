#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

	int data;
	struct node *next;
} node;



node* createNode(int newData){

	node *new = (node*) malloc(sizeof(node));
	new->data = newData;
	new->next = NULL;
	return new;
}

void append(node** headRef, int newData){

	node *current = *headRef;
	node* new = createNode(newData);
	if(*headRef == NULL){
		*headRef = new;
		printf("emply list. NEW node at beginning \n");
		return;
	}
	while(current->next!=NULL){
		current = current->next;
	}
	current->next = new;
	printf("New node inserted at the end\n");
	return;
}

void printList(node* head){

	node *current = head;
	printf("Start of link list -- ");
	while(current!=NULL){
		printf("%i -- ",current->data);
		current = current->next;
	}
	printf("End of link list \n");
}

void push(node** headRef, int newData){

	node *new = createNode(newData);
	if(*headRef == NULL){
		*headRef = new;
		printf("push() added node to the empty list\n");
		return;
	}
	printf("push() inserting node at the top\n");
	new->next = *headRef;
	*headRef = new;
	return;


}



int getNth(node *head , int index){
	node *current = head;
	int i=0;
	for(i=0; i<index; i++){
		current = current->next;
	}

	return current->data;

}

void printMiddle(node *head){

	node* fast = head;
	node* slow  = head;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("middle element in list = %i \n",slow->data);

}
int main(){

	node* head = NULL;
	int index=0;

	printList(head);
	push(&head, 1);
	append(&head,100);
	append(&head,101);
	append(&head,102);
	printList(head);
	push(&head, 0);
	printList(head);
	index = 0; printf("data at index %i: %i\n",index,getNth(head,index));
	index = 1; printf("data at index %i: %i\n",index,getNth(head,index));
	index = 2; printf("data at index %i: %i\n",index,getNth(head,index));
	printMiddle(head);
	return 0;
}