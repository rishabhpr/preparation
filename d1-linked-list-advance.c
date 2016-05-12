#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char *data;
	struct node *next;

} node;

void printList(node *head){
	node *current = head;
	for(;current !=NULL;current = current->next){
		printf("%s \n",current->data);
	}

}
node* create (char *data){
	node* node1 = (node*)malloc(sizeof(node));
	node1->data = strdup(data);
	node1->next=NULL;
	return node1;
}

void append(node** head, char *newData){
	node* appendNode = create(newData);
	node* current = *head;
	if(*head == NULL){
		*head = appendNode;
		return;
	}

	// Bring current till the last element in the list.
	while(current->next !=NULL){
		current= current->next;
	}
	current->next = appendNode;
}
void push( node **headRef, char *newData){
	node *new = (node*)malloc(sizeof(node));
	new->data = strdup(newData);
	new->next = (*headRef);
	*headRef = new;

}
void insertAfter(node* prevNode, char* newData){

	 if (prevNode == NULL) 
    { 
       printf("the given previous node cannot be NULL");       
       return;  
    }  
    node *new = (node*)malloc(sizeof(node));
    new->data = strdup(newData);
    new->next = prevNode->next;
    prevNode->next=new;
       
}
void appendNode(node** headRef, char *newData){

	node *new = (node*)malloc(sizeof(node));
	node *last = *headRef;
	new->data = strdup(newData);
	new->next = NULL;
	if(*headRef == NULL){
		*headRef = new; 
		return;
	}
	while (last->next != NULL)
        last = last->next;
  
    last->next = new;
    return;  
}

int main(){

	node *first = create("first");
	node *second = create("second");
	first->next = second;
	//printing initial list
	printf("initial link list\n");
	printList(first);
	append(&first,"third");
	printf("after append()\n");
	printList(first);
	push(&first,"zero");
	printf("after push()\n");
	printList(first);
	insertAfter(second,"two and half men");
	printf("after insertAfter()\n");
	printList(first);
	appendNode(&first,"fourth");
	printList(first);
	return 0;
}