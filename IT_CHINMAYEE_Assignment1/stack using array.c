/*
Implement Stack using Arrays [Push, Pop, Display].
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX],item,top=-1,n;

//function to push an element into the stack
void push(){
	top++;
	if(top<n){
		printf("Enter the element to be inserted in the stack :- ");
		scanf("%d",&item);
		stack[top]=item;
		printf("\nInsertion successful.\n");
	}
	else{
		printf("\n Stack overflow.\n");
	}
}

//function to pop an element from the stack
void pop(){
	if(top>=0){
		printf("The element popped is:- %d",stack[top]);
		top--;
	}
	else{
		printf("\n Stack underflow. \n");
	}
}

//function to display the stack
void display(){
	int i;
	if(top>=0){
		printf("The stack elements are as follows:-");
		for(i=top;i>=0;i--){
			printf("\t %d",stack[i]);
		}
	}
	else{
		printf("\n The stack is empty.\n");
	}
}

//main function
void main(){
	int choice;
	
	printf("\nImplementing Stack using Arrays:- ");
	printf("\n-------------------------------------\n");
	
	printf("\n Enter array size (max size = %d):- ",MAX);
	scanf("%d",&n);
	
	menu:
		printf("\n Enter your choice: \n 1.PUSH \n 2.POP \n 3.DISPLAY \n 4.EXIT \n");
		scanf("%d",&choice);
	
		if(choice == 1){
			push();
			goto menu;
		}		
		else
		if(choice == 2){
			pop();
			goto menu;
		}
		else
		if(choice == 3){
			display();
			goto menu;
		}
		else
		if(choice == 4){
			exit(1);
		}
		else{
			printf("Invalid choice. Try again !");
			goto menu;
		}
}



