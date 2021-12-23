/*
Implement Queues using Linked Lists [Enqueue and Dequeue].
*/

#include<stdio.h>
#include<stdlib.h>

//creating a node of type structure
struct node{
	int data;
	struct node *next;
};

struct node *head;

//function for enqueue operation
void enqueue(){
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
		struct node * temp;
		temp=head;
		head=item;
		head->next=temp;
	}
	printf("\nInsertion operation is successful.");
}

//function for dequeue operation
void dequeue(){
	struct node *p, *temp;

	if(head==NULL){
		printf("\n List is empty:- \n");
	}
	else {
		p=head;
		while(p->next->next!=NULL){
			p=p->next;
		}
		temp=p->next;
		p->next=NULL;
		free(temp);
		printf("\nDequeue operation is successful.\n");
	}
}

//function to display the queue
void display(){
	struct node *p;
	if(head == NULL){
		printf("\n EMPTY QUEUE. \n");
	}
	else{
		printf("\n Queue elements are:- \n");
		p=head;
		while(p!=NULL){
			printf("%d \t",p->data);
			p=p->next;
		}
	}
}

//main function
void main(){
	int choice;
	
	printf("\nImplementation of Queues using Linked Lists:-");
	printf("\n-------------------------------------------------\n");
	
	while(1){
		printf("\nEnter choice:-\n 1. ENQUEUE \n 2. DEQUEUE \n 3. DISPLAY \n 4. EXIT \n");
		scanf("%d",&choice);
		
		if(choice==1)
			enqueue();			
		else
		if(choice==2)
			dequeue();
		else
		if(choice==3)
			display();
		else
		if(choice==4)
			exit(1);
		else
			printf("\nInvalid choice..Try again!!");

	}
}
