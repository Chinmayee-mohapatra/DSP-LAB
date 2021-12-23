/*
Implement Stack using Linked lists [Push, Pop, Display].
*/

#include<stdio.h>
#include<stdlib.h>

//created a node of type structure
struct node {
	int data;
	struct node *next;
};

struct node * head;

//function to push an item into the stack
void push(){
	struct node *item;
	item=(struct node*)malloc(sizeof(struct node));
	
	int value;
	printf("\nEnter value for insertion :-\t");
	scanf("%d", &value);
	
	item->data=value;
	item->next=NULL;
	
	if(head == NULL){
		head=item;
	}
	else{
		struct node *temp;
		temp=head;
		head=item;
		head->next=temp;
	}
	printf("\nInsertion is successful.\n");
}

//function to pop an item from the stack
void pop(){
	struct node *p;
	if(head==NULL){
		printf("\n The list is empty:- \n");
	}
	else {
		printf("Item %d has been popped.\n",head->data);
		p=head;
		head=head->next;
		free(p);
	}
}

//function to display the stack
void display(){
	struct node *p;
	if(head == NULL){
		printf("\n The stack is empty:- \n");
	}
	else{
		printf("The elements in the stack are: \n");
		p=head;
		while(p!=NULL){
			printf("%d \t",p->data);
			p=p->next;
		}
	}
	printf("\n");
}

//main function
int main(){
	int choice;
	
	printf("\nImplementing Stack using Linked lists:- ");
	printf("\n--------------------------------------------\n");
	
	while(1){
		printf("Enter choices : \n 1. PUSH \n 2. POP \n 3. DISPLAY \n 4. EXIT \n");
		scanf("%d",&choice);
		
		if(choice==1)
			push();
			
		else 
		if(choice==2)
			pop();
			
		else
		if(choice==3)
			display();
		
		else
		if(choice==4)
			exit(1);	
		else
			printf("\n Invalid Choice. \n");
	}
	return 0;
}
