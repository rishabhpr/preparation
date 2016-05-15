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
int getCountR(node *head){
	if(head == NULL ){
		return 0;
	}

	return 1+ getCountR(head->next);
}


int getNthFromLast1(node *head , int index){
	node *current = head;
	int len = getCountR(head);
	int i;
	for(i=0; i<len-index; i++){
		current = current->next;
	}

	return current->data;

}

int getNthFromLast2(node *head, int index){
	node *main = head;
	node *ref = head;
	int i=0;
	for(;i<index;i++){
		ref = ref->next;
	}
	while(ref!=NULL){
		main = main->next;
		ref = ref->next;
	}
	return main->data;
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
	printf("\n");
	printf("1 from last : %i \n",getNthFromLast1(head,1));
	printf("2 from last : %i \n",getNthFromLast1(head,2));
	printf("3 from last : %i \n",getNthFromLast1(head,3));
	printf("1 from last : %i \n",getNthFromLast2(head,1));
	printf("2 from last : %i \n",getNthFromLast2(head,2));
	printf("3 from last : %i \n",getNthFromLast2(head,3));

	return 0;
}