//Implementation of merge sort
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define MAX 100

//function to merge the subarrays
void merge(int *a,int p,int q,int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int *left=(int *)malloc((n1+1)*sizeof(int));
	int *right=(int *)malloc((n2+1)*sizeof(int));;
	int i,j,k;
	
	for(i=0;i<n1;i++){
		left[i]=a[p+i-1];
	}
	for(j=0;j<n2;j++){
		right[j]=a[q+j];
	}
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	
	i=0;
	j=0;
	
	for(k=p;k<=r;k++){
		if(left[i]<=right[j]){
			a[k] = left[i];
			i++;
		}
		else{
			a[k] = right[j];
			j++;
		}
	}
	free(left);
	free(right);	
}

//function to perform merge sort
int mergeSort(int *a,int p, int r){
	if(p<r){
		int q = (p+r)/2;
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);
		merge(a,p,q,r);
	}
}

//main function 
int main(){
	int choice,i,p,temp;
	int *arr;
	FILE *fp;
	clock_t t1,t2;
	
	printf("Implementation of Merge sort.\n");
	printf("-------------------------------\n");
	
	while(1){
		printf("Enter choice:- \n");
		printf("1. Random input\n");
		printf("2. Sorted input\n");
		printf("3. Sorted with 1%% as random input\n");
		printf("4. Exit\n");
		scanf("%d",&choice);
		
	
		arr = malloc(sizeof(int)*MAX);
		
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
    	
       	mergeSort(arr,0,MAX-1);
       	
		printf("\nAfter sorting:-\n");
		for(i=0;i<MAX;i++){
			printf("%d ",arr[i]);
		}
		
		t2=clock();	
		
		double total_time=((double)(t2 -t1))/CLOCKS_PER_SEC;
    	printf("\n\nTotal time of execution  = %f, when array size = %d\n", total_time, MAX);	
		printf("\n");
		free(arr);
		fclose(fp);
	}
	return 0;
}
