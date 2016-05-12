#include <stdio.h>
#include <stdlib.h>

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

int main(){

	node *first = NULL;
	node second={"first",NULL};
	first = (node*)malloc(sizeof(node));
	first->data = "rishabh";
	first->next = &second;
	printList(first);

	return 0;
}