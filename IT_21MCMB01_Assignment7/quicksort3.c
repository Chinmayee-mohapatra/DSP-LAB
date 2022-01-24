//Implementation of quicksort taking median of {first, middle and last element} as pivot
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//function to take median of {first element, middle element, last element} from the array as pivot element
int pivot_last(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1),j;
 
	for (j = low; j < high; j++) {
		if (arr[j] < pivot) {
		swap(&arr[++i], &arr[j]);
		}
	}
 
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int pivot_median(int arr[], int low, int high) {
	
	int pivot;
	int mid = (low + high) / 2;
	if (arr[mid] < arr[low]) 
		swap(&arr[mid], &arr[low]);
		
	if (arr[high] < arr[low])
		swap(&arr[high], &arr[low]);
		
	if (arr[high] < arr[mid])
		swap(&arr[high], &arr[mid]);
		
	swap(&arr[mid], &arr[high-1]);
	
	pivot = arr[high-1];
 
	return pivot_last(arr, low, high);
}
 
void quickSort(int array[], int low, int high) {	
	if (low < high) {
		int pi = pivot_median(array, low, high);
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}

//main function
int main(){
	int i,choice,temp,p,max;
	clock_t t1,t2;

	printf("Implementation of quicksort with median of {first, middle and last element} as pivot.\n");
	printf("---------------------------------------------------------------------------------------\n");

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
	    
	quickSort(arr,0,max-1);
		
	printf("\nAfter sorting:-\n");
	for(i=0;i<max;i++){
		printf("%d ",arr[i]);
	}	
	
	t2=clock();	
	
	double total_time=((double)(t2 -t1))/CLOCKS_PER_SEC;
    printf("\n\nTotal time of execution  = %f, when array size = %d\n", total_time, max);
	
	return 0;
}
