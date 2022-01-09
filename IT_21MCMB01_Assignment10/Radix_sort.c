/*
Question: Take Input array from the User Sort it Using Radix Sort Algorithm
*/

#include<stdio.h>

//function for radix sort
void radixSort(int *arr, int n){
	int i,a[10],max=0,exp=1;
	
	for(i=0;i<n;i++){
		if(arr[i]>max)
		max=arr[i];
	}
	
	while(max/exp > 0){
		int result[10] = {0};
		for(i=0;i<n;i++)
			result[arr[i] / exp %10]++;
		for(i=1;i<10;i++)
			result[i] += result[i-1];
		for(i=n-1;i>=0;i--)
			a[--result[arr[i] / exp % 10]] =arr[i];
		for(i=0;i<n;i++)
			arr[i]=a[i];
		exp *= 10;
	}
}

//main function
int main(){
	int num,arr[100],i;
	
	printf("\nImplementation of radix sort.");
	printf("\n-------------------------------");
	
	printf("\n Enter the no of elements:- ");
	scanf("%d",&num);
	printf("\nEnter the elements of the array:-\n");
	for(i=0;i<num;i++)
		scanf("%d",&arr[i]);
		
	radixSort(&arr[0],num);
	
	printf("\nArray elements after radix sort:-\n");
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);
		
	return 0;	
}
