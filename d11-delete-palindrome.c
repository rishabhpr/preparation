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
	new->next = NULL;
	return new;
}

void append(node** headRef, int newData){
	node* new = createNode(newData);
	if(*headRef == NULL){
		printf("list is currently empty. \n");
		*headRef = new;
		printf("new node appended to empty list. \n");
		return;
	}
	node* current = *headRef;
	while(current->next !=NULL){
		current = current->next;
	}
	current->next = new;
	return;
}

void printList(node* current){
	printf("Start of list -- ");
	while(current!=NULL){
		printf("-- %i ",current->data);
		current = current->next;
	}
	printf(" -- End of list \n");
}
void deleteNode(node* current){

	node* temp = current->next;
	current->data = temp->data;
	current->next = temp->next;
	free(temp);
}
void reverse(node** headRef){

	node *prev = NULL;
	node* current = *headRef;
	node* temp = NULL;
	while(current!=NULL){
		temp = current->next;
		current->next = prev;
		prev= current;
		current=temp;
	}

	*headRef = prev;
}
void reverseN(node** headRef){
	//this function is giving Segmentation fault (core dumped) error
	node *prev = NULL;
	node* current = *headRef;
	node* temp = current->next;
	while(current!=NULL){
		current->next = prev;
		prev= current;
		current=temp;
		temp=temp->next;
	}

	*headRef = prev;
}

int compareLists(node* temp1, node* temp2){
	while(temp1 && temp2){
		if(temp1->data == temp2->data){
			temp1 = temp1->next;
			temp2 = temp2->next;

		}
		else return 0;
	}
	if(temp1 == NULL && temp2==NULL){
		return 1;
	}

	return 0;
}

int isPalindrome(node* head){
	node* slow = head;
	node* fast = head;
	node* secondHalf= NULL;
	node* prevSlow= head;
	node *midNode = NULL;
	int result = 1;
	if (head!=NULL && head->next!=NULL){
		while(fast!=NULL && fast->next!=NULL){
			prevSlow = slow;
			slow= slow->next;
			fast= fast->next->next;
		}
		if(fast!=NULL){
			//odd number of elements
			midNode = slow;
			slow= slow->next;
		}
		secondHalf = slow;
		prevSlow->next = NULL;
		reverse(&secondHalf);
		result = compareLists(head,secondHalf);
		printf("result == %i\n",result);

		//constructing original list
		reverse(&secondHalf);
		if(midNode!=NULL){
			prevSlow->next = midNode;
			midNode->next=secondHalf;
		}
		else prevSlow->next = secondHalf;
	}
	return result;
}

int main(){
	node* head = NULL;
	append(&head,5);
	append(&head,2);
	append(&head,4);
	printList(head);
	deleteNode(head->next);//deleting 2nd node
	append(&head,4);
	append(&head,5);
	printList(head);
	reverse(&head);
	printList(head);
	int result = isPalindrome(head);
	if(result==1) printf("palindrome\n");
	else printf("not a palindrome\n");
	return 0;
}