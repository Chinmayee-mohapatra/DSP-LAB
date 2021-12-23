// Implementation of circular linked list.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// structure of type node
struct node
{
	int info;
	struct node *link;
};

// Insert new node at the end of the list
struct node *insert_node(struct node *head,int data)
{
	struct node *temp;
	struct node *temp2;

	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	if(head)
	{
		temp2=head;
        while(temp2->link!=head)
        {
            temp2=temp2->link;
        }
        temp2->link=temp;
        temp->link=head;
	}
	else
	{
		head=temp;
		head->link=head;
	}
	return head;
}

// Function to display the circular list before splitting
void display(struct node *head){
	
	struct node *p;
	if(head==NULL){
		printf("\nLIST IS EMPTY.\n"); 		//check for empty list
		return;
	}
	p=head;
	
	do{
		printf("%d -> ",p->info);
		p=p->link;
	}while(p!=head);
	
	printf("\n");
}

// Function to split the circular list
int split(struct node *head){
	
	int count=1,mid;
	
	if(head==NULL){
		printf("\nLIST IS EMPTY.\n"); 		//check for empty list
		return 0;
	}
	
	struct node *p,*q,*head2;
	p=head;
	
	while(p->link!=head){
		p=p->link;
		count++;
	}
	if(count%2!=0)
		mid=(count/2)+1;
	else
		mid=count/2;
	
	q=head;
	count=1;
	while(count!=mid){
		q=q->link;
		count++;
	}
	
	head2=q->link;
	q->link=head;
	p->link=head2;	
	q=head;
	p=head2;
	
	printf("\nThe circular linked lists after splitting:-\n");
	do{
		printf("%d -> ",q->info);
		q=q->link;
	}while(q!=head);
	printf("\n");
	do{
		printf("%d -> ",p->info);
		p=p->link;
	}while(p!=head2);
	
	return 0;
}

// main function
int main( )
{
	int choice,data,item;
	struct node	*head=NULL;
	
	printf("Program to split a circular linked list into two halves:-\n");
	printf("----------------------------------------------------------\n");
	while(1)
	{	
		printf("1.Insert new node\n");
		printf("2.Display\n");
		printf("3.Split the circular list\n");
		printf("4.Quit\n");
		
		printf("Enter your choice : \n");
		scanf("%d",&choice);

		if(choice==1){
			printf("\nEnter the element to be inserted : \n");
			scanf("%d",&data);
			head=insert_node(head,data);
		}
		else
		if(choice==2){
			display(head);
		}
		else
		if(choice==3){
			split(head);
		}
		else
		if(choice==4){
			exit(1);
		}
		else{
			printf("\nINVALID CHOICE\n");
		}
	}
	return 0;
}

