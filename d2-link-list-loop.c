#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

	char *data;
	struct node *next;
} node;

void append(node** headRef, char *newData){
	node* new = (node*) malloc(sizeof(node));
	node *last = *headRef;
	new->data = strdup(newData);
	new->next=NULL;
	if(*headRef==NULL){
		*headRef= new;
		return;
	}

	while(last->next!=NULL){
		last=last->next;
	}
	last->next = new;
	return;
}
void printList(node *head){
	node *current = head;
	while(current!=NULL){
		printf("%s\n",current->data);
		current = current->next;
	}
}
int checkLoop(node *head){

	node *fast = head;
	node *slow = head;
	while(fast && slow && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			return 1;
		}

	}
	return 0;
}
int main(){

	node *head = NULL;
	append(&head,"a");
	append(&head,"b");
	append(&head,"c");
	append(&head,"d");
	head->next->next->next->next = head;
	if(checkLoop(head)==0)
		printList(head);
	else printf("LOOP detected\n");
	return 0;
}