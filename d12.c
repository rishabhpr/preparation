#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

	int data;
	struct node* next;
} node;

node* createNode(int newData){

	node* new = (node*) malloc(sizeof(node));
	new->data = newData;
	new->next=NULL;
	return new;
}

void append(node** headRef, int newData){
	node* new = createNode(newData);
	if(*headRef == NULL){
		printf("Appending node in empty list.....\n");
		*headRef = new;
		return;
	}
	node* current = *headRef;
	while(current->next!=NULL){
		current= current->next;
	}
	current->next = new;


}

void push(node **headRef,int newData){

	node* new = createNode(newData);
	if(*headRef == NULL){
		printf("Pushing node in empty list.....\n");
		*headRef = new;
		return;
	}
	new->next = *headRef;
	*headRef = new;

	return;

}


void printList(node* current){
	printf("Start of list ");
	while(current!=NULL){
		printf("-- %i ",current->data);
		current = current->next;
	}
	printf("-- End of list \n");
}

int listToNumber(node* current){
	int i=1;
	int number=0;
	while(current!=NULL){
		number=number+(i*current->data);
		current=current->next;
		i=i*10;
	}
	return number;

}
int isPowerOfTwo (int num)
{
 
  int res = n& (!n&(n-1));
  printf("Res = %i\n",res)
}


node* numberToList(int number){
	node* newHead = NULL;
	int copy=number;
	int temp=0;
	while(copy!=0){
		append(&newHead,copy%10);
		copy=copy/10;
	}

	return newHead;
}

int sumOfLists(node *h1 , node* h2){
	return listToNumber(h1) + listToNumber(h2);
}



int main(){

	node* head = NULL;
	int num1,num2;
	printf("Enter first number: ");
	scanf("%i",&num1);
	printf("Enter second number: ");
	scanf("%i",&num2);
	node* h1 = numberToList(num1);
	node* h2 = numberToList(num2);
	printf("Sum = %i\n",sumOfLists(h1,h2));
	isPowerOfTwo(200);

	//append(&head,5);
	//push(&head,7);
	//push(&head,4);
	//push(&head,3);
	//printList(head);
	//printf("list = %i\n",listToNumber(head));
	
	//node* test = numberToList(123);
	//printf("list = %i\n",listToNumber(test));
	return 0;
}