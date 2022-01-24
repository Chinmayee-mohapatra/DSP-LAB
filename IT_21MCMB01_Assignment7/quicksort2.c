//Implementation of quicksort that takes a random array element as pivot
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to do the partion operation on the array
int partition(int *arr, int p, int q){
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

//function to take any random element from the array as pivot element
int rand_pivot(int *arr, int p, int r)
{	int temp;
    int rnd = p + rand() % (r - p);
 
    temp=arr[rnd];
	arr[rnd]=arr[r];
	arr[r]=temp;
 
    return partition(arr, p, r);
}

//function to call quicksort recursively for every subarray
int quicksort(int *arr,int p,int r){
	int q,i;
	if(p<r){
		q=rand_pivot(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

//main function 
int main(){	
	int i,choice,temp,p,max;
	clock_t t1,t2;

	printf("Implementation of quicksort with random element as pivot.\n");
	printf("-----------------------------------------------------------\n");

	printf("Enter the no of elements:- \n");
	scanf("%d",&max);
	
	int arr[max];
	
	printf("\nEnter choice:- \n");
	printf("1. Random input\n");
	printf("2. Sorted input\n");
	printf("3. Sorted with 1%% as random input\n");
	printf("4. Exit\n");
	scanf("%d",&choice);
	
	if(choice == 1){
		printf("Enter array elements:-\n");
		for(i=0 ; i<max ; i++){
 		   	scanf("%d",&arr[i]);
		}
	}
	else 
	if(choice == 2){
		printf("Enter array elements:-\n");
		for(i=0 ; i<max ; i++){
		   	scanf("%d",&arr[i]);
		}
	}
	else 
	if(choice == 3){
		printf("Enter array elements:-\n");
		for(i=0 ; i<max ; i++){
		   	scanf("%d",&arr[i]);
		}

		p = max/100;
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
    
   	quicksort(arr,0,max-1);
	
	printf("\nAfter sorting:-\n");
	for(i=0;i<max;i++){
		printf("%d ",arr[i]);
	}
	
	t2=clock();	
	
	double total_time=((double)(t2 -t1))/CLOCKS_PER_SEC;
   	printf("\n\nTotal time of execution  = %f, when array size = %d\n", total_time, max);

	return 0;
}
