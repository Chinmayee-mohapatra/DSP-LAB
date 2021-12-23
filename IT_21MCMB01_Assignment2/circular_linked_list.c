/* Question 3: */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node{
	char info[3][40];
	struct node *link;
};

struct node *head;
int count=0;


//function to display the list
void display()
{	int i;
	struct node *p;
	p=head;
	printf("\nThe list is as follows:\n");
	do{
		for(i=0;i<3;i++){
			printf("%s ",p->info[i]);
		}
		p=p->link;
		printf("\n");
	}while(p!=head);
}


//function to display only the second strings
void display2()
{
	struct node *p;
	char ch;
	int i;
	p=head;
	printf("\nSecond elements are:\n");
	do{
		printf("\n%s",p->info[1]);
		p=p->link;
	}while(p!=head);
}

//function to check the string rule
void checkstring()
{
	struct node *ptr;
	int flag=0;
	int i;
	ptr=head;
	if(head==NULL)
	{
		printf("\nLinked List is empty\n");
		exit(1);
	}
	do
	{
		if(strcmp(ptr->info[2],ptr->link->info[0]) != 0)
		{
			printf("\nThe element %s does not match with %s in the node",ptr->info[2],ptr->link->info[0]);
			flag=1;
		}
		ptr=ptr->link;
	}while(ptr!=head);
	
	if(flag==0)
		printf("\nString match sucessful\n");
	else
		printf("\nString not Matching\n");
}

//function to replace a string
void replace(){
	int i,n;
	int ch;
	struct node *p;
	printf("\nEnter the node number for replacement of string:\n");
	scanf("%d",&n);
	if((n>count) || (n<1))
	{
		printf("\nNode does not exist\n");
		return;
	}
	else
	{	
		p=head;
		for(i=1;i<n;i++)
		{
			p=p->link;
		}
	
		printf("\nChoose string to change:\n1. FIRST \n2. SECOND \n3. THIRD \n4. MENU\n");
		scanf("%d",&ch);
		if(ch==4)
			return;
		else 
		if(ch>=1 && ch<=3){	
			printf("\nEnter the string:\n");
			scanf("%s",p->info[ch-1]);
		}
		else{
			printf("\nInvalid Choice\n");
			exit(1);
		}
	}
	printf("\nString replaced.\n");
}

//function to add node 
void addnode()
{
	int i;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nMemory not allocated to new node\n");
		exit(1);
	}
	printf("\nEnter the three string elements for the node\n");
	count++;
	for(i=0;i<3;i++)
	{
		scanf("%s",newnode->info[i]);
	}
	struct node *ptr;
	ptr=head;
	if(head==NULL)
	{
		head=newnode;
		head->link=head;
	}
	else
	{
		while(ptr->link!=head)
		ptr=ptr->link;		
		ptr->link=newnode;
		ptr=newnode;
		ptr->link=head;
		printf("\nElements added to the node %d.\nChecking for string match rule\n",count);
		checkstring();
	}
}

//main function
void main()
{	
	int choice;
	
	while(1){
        printf("\n1.Insert node");
		printf("\n2.Display all ");
		printf("\n3.Display only second string of all nodes");
		printf("\n4.Replace string Values");
		printf("\n5.Exit");  
       	printf("\nEnter your choice:- \n");         
       	scanf("\n%d",&choice); 
       	
       	if(choice==1){      		
       		printf("\nchoice is 1\n");
			addnode();
		}
		else 
		if (choice==2){			
			display();
		}
		else 
		if (choice==3){
			display2();
		}
		else 
		if (choice==4){
			replace();
		}
		else 
		if (choice==5){
			exit(1);
		}
		else{
			printf("\nInvalid Input\n");
		}
	}
}









