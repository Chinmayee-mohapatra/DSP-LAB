/*
Question - 2
Create a singly link list which contains either 0 or 1 as element only

1. Provide an Insert function for inserting nodes with value either 0 or 1
only.(insert it at beginning or end)
2. Provide a function to calculate equivalent decimal value by taking singly link
list elements as binary number.
*/


#include<stdio.h>
#include<stdlib.h>

//created a node of type structure 
struct node{
	int data;
	struct node *next;
};

int calculate(struct node* head){
	int res=0;
	while(head!=NULL){
		res=(res*2) + head->data;							//calculate the decimal equivalent of the binary number
		head=head->next;
		}    	
	return res;
}

//main function
void main(){
	struct node *head=NULL,*p=NULL;
	int number;
	
	printf("Implementation of singly linked list to convert binary to decimal:-\n");
	printf("--------------------------------------------------------------------\n");
	
	printf("Enter the size of binary number:-\n");
	scanf("%d",&number);
	printf("\nEnter value (only 0's and 1's are allowed): \n");
	while(number!=0){
		p=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&p->data);                        
		
		if(p->data==0 || p->data==1){
			if(head==NULL){
				p->next=NULL;
				head=p;
			}
			else{
				p->next=head;
				head=p;
			}
			number--;	
		}
		else{
			printf("Not a binary number!\n");
		}
	}
	printf("\nDecimal:- %d\n",calculate(head));	
}
