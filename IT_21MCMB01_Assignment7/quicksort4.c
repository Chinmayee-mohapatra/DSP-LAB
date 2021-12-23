//Implementation of quicksort taking median of {n/4th element, middle element, 3n/4th element} as pivot
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

//function to take median of {n/4th element, middle element, 3n/4th element} from the array as pivot element
int m_pivot(int *arr,int p,int r){
	int x,y,z,t,pivot;
	x=arr[r/4];
	y=arr[(3*r)/4];
	t=p+((r-p)/2);
	z=arr[t];
	
	if(x<=y && x<=z){
		pivot=((y<=z)?y:z);
	}
	else
	if(y<=x && y<=z){
		pivot=((x<=z)?x:z);
	}
	else
	if(z<=x && z<=y){
		pivot=((x<=y)?x:y);
	}
	
	return pivot;
}

//function to do the partion operation on the array
int partition(int *arr, int p, int q){
	int x,i,j,temp;
	x=m_pivot(arr,p,q);
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
void quicksort(int *arr,int p,int r){
	int q,i;
	if(p<r){
		q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

//main function
int main(){
	FILE* fp;	
	int i,choice,temp,p;
	int *arr;
	
	clock_t t1,t2;

	printf("Implementation of quicksort with {n/4th , middle & 3n/4th element} as pivot.\n");
	printf("-------------------------------------------------------------------------------\n");

	while(1){
		printf("Enter choice:-\n ");
		printf("1. Random input\n");
		printf("2. Sorted input\n");
		printf("3. Sorted with 1% as random input\n");
		printf("4. Exit\n");
		scanf("%d",&choice);
		
		arr = (int)malloc(sizeof(int)*MAX);
		if(choice == 1){
			fp = fopen("random_input.txt","r");
			for(i=0 ; i<MAX ; i++){
 			   	fscanf(fp,"%d",&arr[i]);
			}
		}
		else 
		if(choice == 2){
			fp = fopen("sorted_input.txt","r");
			for(i=0 ; i<MAX ; i++){
 			   	fscanf(fp,"%d",&arr[i]);
			}
		}
		else 
		if(choice == 3){
			fp = fopen("sorted_input.txt","r");
			for(i=0 ; i<MAX ; i++){
 			   	fscanf(fp,"%d",&arr[i]);
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
		fclose(fp);
		free(arr);
	}
	return 0;
}
