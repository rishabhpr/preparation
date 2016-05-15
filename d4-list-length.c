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

int getCount(node *head){
	node *current = head;
	int count = 0;
	while(current!=NULL){
		count++;
		current = current->next;
	}
	return count;

}

int getCountR(node *head){
	if(head == NULL ){
		return 0;
	}

	return 1+ getCountR(head->next);
}

void searchI(node* head, int key){

	node* current = head;
	while(current!=NULL){
		if(current->data == key) break;
		current = current->next;
	}

	if(current!=NULL)
		printf("%i found in list\n",current->data);
	else printf("%i not found\n",key);


}

int searchR(node* head , int key ){

	if(head == NULL) return 0;
	if(head->data == key) return 1;
	return searchR(head->next,key);
}
int main(){

	node* head = NULL;
	printf("Number of nodes : %i\n",getCount(head));
	printList(head);
	push(&head, 1);
	printf("Number of nodes : %i\n",getCountR(head));
	append(&head,100);
	printf("Number of nodes : %i\n",getCount(head));
	append(&head,101);
	printf("Number of nodes : %i\n",getCountR(head));
	append(&head,102);
	printf("Number of nodes : %i\n",getCount(head));
	printList(head);
	push(&head, 0);
	searchI(head,100);
	searchI(head,999);
	searchR(head, 100)? printf("100 found\n") : printf("100 not found\n");
	searchR(head, 999)? printf("999 found\n") : printf("999 not found\n");
	printf("Number of nodes : %i\n",getCount(head));
	printList(head);;
	return 0;
}