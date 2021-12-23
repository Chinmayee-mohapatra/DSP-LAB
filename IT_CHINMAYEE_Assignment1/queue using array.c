/* 
Implement Queues using Arrays [Enqueue and Dequeue].
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX],item,front=-1,rear=-1,n;

//function for enqueue operation on the queue
void enqueue(){
	if(rear == n-1){
		printf("\n QUEUE IS FULL. \n");
	}
	else{
		printf("\nEnter item to insert:-  ");
		scanf("%d",&item);
	
		if(front==-1)
			front = 0;
		rear++;
		queue[rear]=item;
		printf("\nInsertion is successful.\n");
	}
}

//function for dequeue operation on the queue
void dequeue(){
	if(front == -1)
		printf("\n QUEUE IS EMPTY. \n");
	else{
		printf("\n Element popped is:- %d",queue[front]);
		front++;
		if(front > rear){
			front=rear=-1;
		}
	}
}

//function to display the queue
void display(){
	int i;
	if(rear==-1){
		printf("\n The queue is empty. \n");
	}
	else{
		printf("The queue elements are as follows:-");
		for(i=front;i<=rear;i++){
			printf("\t %d",queue[i]);
		}
	}
}

//main function
void main(){
	int choice;
	
	printf("\n Implementing Queues using Arrays:-");
	printf("\n---------------------------------------");
	
	printf("\n Enter array size(max size=%d):-",MAX);
	scanf("%d",&n);
	
	menu:
		printf("\n Enter your choice: \n 1. ENQUEUE \n 2. DEQUEUE \n 3. DISPLAY \n 4. EXIT \n");
		scanf("%d",&choice);
	
		if(choice==1){
			enqueue();
			goto menu;
		}
		else
		if(choice==2){
			dequeue();
			goto menu;	
		}
		else
		if(choice==3){
			display();
			goto menu;	
		}
		else
		if(choice==4)
			exit(1);
		else{
			printf("Invalid choice. Try again !");
			goto menu;
		}
}


