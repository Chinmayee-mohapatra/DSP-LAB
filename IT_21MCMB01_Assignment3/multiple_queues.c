//Implementation of multiple queues using single array(arr[])

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//function to add elements into the array
void enqueue(int arr[], int front[], int rear[], int next[], int *fr,int k, int qn)
{
	int item;
	if(*fr==-1){
		printf("\nQueue Overflow.\n");				//check if the queue is full
		return;
	}
	printf("\nEnter the item to be inserted:- ");
    scanf("%d",&item);
    		
	int i=*fr;
	*fr=next[i];
	
	if(front[qn]==-1)
		front[qn]=i;
	else
		next[rear[qn]]=i;
	
	next[i]=-1;
	rear[qn]=i;
	arr[i]=item;
}

//function to delete elements from the queue with maximum number of elements
int dequeue(int arr[], int front[], int next[], int *fr, int qn)
{
	if(front[qn]==-1)
	{
		printf("\nQueue Underflow.");				//check if the queue is empty
		return INT_MAX;
	}
	
	int i=front[qn];
	front[qn]=next[i];	
	next[i]=*fr;
	*fr=i;
	int n = arr[i];
	arr[i]=0;
	return n;
}

//function to display all elements present in each queue
void display_all(int arr[], int front[],int rear[], int next[],int k){
	int n,i;
	
	printf("\nAll queues in array:\n");
	
	for(i=0;i<k;i++){	
		printf("\n Queue: %d \n",i+1);
		if(front[i]==-1){
			printf("\nQueue doesnot exist\n");
			continue;
		}
		printf("\n Queue %d : front = %d, rear = %d\n",i+1,front[i],rear[i]);
		n=front[i];
		while(n!=-1){
			printf("%d\n",arr[n]); 
			n=next[n];
			}
		}
}

//main function from where execution starts
int main(){
	int i,choice,k=4;                                                                                    
	int qn;
	int fr=0;

	printf("\nImplementing multiple queues using a single array:- ");
	printf("\n-----------------------------------------------------");
	/*
	printf("\n Enter the number of queues to be implemented : ");
	scanf("%d",&k);	
	*/
	int front[k],rear[k];  
	int n=k*20;	
	int next[n],arr[n];
	
	
	for(i=0;i<k;i++)		
		front[i]=-1;		//initializing front array as -1 to indicate all queues are empty 
	
	for(i=0;i<k;i++)		
		rear[i]=-1;			//initializing rear array as -1 to indicate all queues are empty 
	
	for(i=0;i<n;i++)		//arr[] is used to store the various queues
		arr[i]=0;			//initializing arr array as 0 to indicate all queues are empty 
	
	for(i=0;i<n-1;i++)		
		next[i]=i+1;		//next array initialized to i+1 for all,
	next[n-1]=-1;			//only the last cell stores -1
	
	while(1){
		printf("Enter choices:- \n");
		printf("1.Enqueue \n");
		printf("2.Insert item on the minimum number of elements in the queue\n");
		printf("3.Delete item from the maximum number of elements in queue\n");
		printf("4.Display_all queues\n");
		printf("5.Display (front,rear,arr)\n");
		printf("6.Exit\n");
		scanf("%d",&choice);
		
		if(choice==1)
		{	
    		printf("\nEnter the queue no :- ");
    		scanf("%d",&qn);
    		if(qn>k){
				printf("\nINVALID QUEUE NUMBER.");
				exit(1);
			}
			else{
				qn--;
    			enqueue(arr,front,rear,next,&fr,k,qn);
			}
		}
		else
		if(choice==2)
		{	
			int min=n*k+1;
        	for(i=0;i<k;i++){
        		int diff=rear[i]-front[i]+1;
        		if(min>diff){
        			min=diff;
        			qn=i;
				}
			}
			enqueue(arr,front,rear,next,&fr,k,qn);
		}
		else
		if(choice==3)
		{
			int max=-1;
			
        	for(i=0;i<k;i++)
        	{
        		int diff=rear[i]-front[i]+1;
        		if((max<diff)&& rear[i]!=-1) 
        		{
        			max=diff;
        			qn=i;
				}
			}
			printf("\n Element : %d has been deleted from the queue : %d \n",dequeue(arr,front,next,&fr,qn),qn+1);
		}
		else
		if(choice==4){
			display_all(arr,front,rear,next,k);
		}
		else
		if(choice==5){
			for(i=0;i<k;i++){
				printf("front: %d \n",front[i]);
			}
			for(i=0;i<k;i++){
				printf("rear: %d \n",rear[i]);
			}
			for(i=0;i<n;i++){
				printf("array: %d \n",arr[i]);
			}
			/*
			for(i=0;i<n;i++){
				printf("next: %d \n",next[i]);
			}
			*/		
		}
		else
		if(choice==6){
			exit(1);
		}
		else{
			printf("\nINVALID CHOICE !!");
		}
		
	}
	return 0;
}
