//Implementing quicksort that takes the first element as pivot
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

//function to do the partion operation on the array
int partition(int *arr,int p,int q){
	int x,i,j,temp;
	x=arr[p];
	i=p;
	
	for(j=p+1;j<=q;j++){
		if(arr[j]<=x){
			i=i+1;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[p];
	arr[p]=arr[i];
	arr[i]=temp;
	return i;
}

//function to call quicksort recursively for every subarray
int quicksort(int *arr,int p, int r){
	if(p<r){
		int q = partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

//main function
int main(){	
	int i,choice,temp,p;
	int l = 1, r = MAX;
	int *arr;
	clock_t t1,t2;
	
	printf("Implementation of quicksort with first element as pivot.\n");
	printf("----------------------------------------------------------\n");
	
	while(1){
		printf("Enter choice:- \n");
		printf("1. Random input\n");
		printf("2. Sorted input\n");
		printf("3. Sorted with 1%% as random input\n");
		printf("4. Exit\n");
		scanf("%d",&choice);
		
	
		arr = malloc(sizeof(int)*MAX);
		
		if(choice == 1){
			for(i=0 ; i<MAX ; i++){
	 		   	arr[i] = (rand() % (r - l + 1)) + l;
			}
		}
		else 
		if(choice == 2){
			for(i=0 ; i<MAX ; i++){
 			   	arr[i] = i;
			}
		}
		else 
		if(choice == 3){
			for(i=0 ; i<MAX ; i++){
 			   	arr[i] = i;
			}
	
			p = MAX/100;
			for(i=0;i<p;i++){
				temp = arr[i];
				arr[i]  = arr[p+i];
				arr[p+i] = temp;
			}	
		
		}
		else 
		if(choice == 4){
			exit(1);
		}
		else{
			printf("\nInvalid choice!!\n");
		}
		
    	t1=clock();	
    	
       	quicksort(arr,0,MAX-1);
       	
		printf("\nAfter sorting:-\n");
		for(i=0;i<MAX;i++){
			printf("%d ",arr[i]);
		}
		
		t2=clock();	
		
		double total_time=((double)(t2 -t1))/CLOCKS_PER_SEC;
    	printf("\n\nTotal time of execution  = %f, when array size = %d\n", total_time, MAX);	
		printf("\n");
		free(arr);
	}
	return 0;
}