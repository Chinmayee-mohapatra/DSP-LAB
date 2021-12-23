//Implementation of priority queue.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

struct student{
	char name[30];
	int score;
};

struct student stu[MAX];
int p_queue[MAX];
int init;
int front=-1,rear=-1;

//function for insertion operation
int insert(){	
	if(front==-1)
		front=0;
	if(rear>=MAX)
	{
		printf("\n Overflow \n");				//checks overflow condition
		return;
	}	
	
	char name[MAX];
	int key;
	printf("Enter name:- \n");
	scanf("%s",name);
	printf("Enter GATE score:- \n");
	scanf("%d",&key);
	int i=rear++; 							//rear incremented while addition into the queue
	
	while(stu[i].score>key && i>=0){		//now find correct position of i
		stu[i+1].score=stu[i].score; 		// checks my whole queue until i>0 for each new entry, and for first entry this loop will not run
		strcpy(stu[i+1].name,stu[i].name);  
		i--;
	}
	
	strcpy(stu[i+1].name,name);
	stu[i+1].score=key;
}

//function for deletion operation
void delete_(){
	if(front==-1 || front>rear){
		printf("\n Underflow \n");			//checks underflow condition
		return;
	}
	
	stu[front].score=INT_MIN;
	printf("\nData for '%s' has been deleted.\n",stu[front++].name);	//front incremented while deletion from the queue
}

//function to display the queue
void display(){
	int i;
	if(front==-1 || front>rear){
		printf("\nUnderflow\n");
		return;
	}
	for(i=front;i<=rear;i++){ 
		printf("name: %s, score: %d\n",stu[i].name,stu[i].score); 
	}
}

//main function
void main(){
	int i,choice;
	printf("Implementation of priority queue: \n");
	printf("--------------------------------------\n");

	while(1){
		printf("Enter choice:-\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		scanf("%d",&choice);
		
		if(choice==1){
			insert();
		}
		else
		if(choice==2){
			delete_();
		}
		else
		if(choice==3){
			display();
		}
		else
		if(choice==4)
			exit(1);
		else
			printf("\n INVALID CHOICE \n");
		
	} 
}
