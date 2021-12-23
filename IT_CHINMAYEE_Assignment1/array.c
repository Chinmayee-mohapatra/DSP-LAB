/*
Given an array of integers and a number ‘n’, find the smallest subarray with sum greater
than the given value. Display the smallest subarray by adding the size of the subarray to
each element in the subarray.
*/

#include<stdio.h>
#define MAX 100

//function to calculate the sub-array sum
int subArraySum(int arr[], int n, int sum){
	int curr_sum, i, j,k;

	
	for (i = 0; i < n; i++) {
		curr_sum = arr[i];

		
		for (j = i + 1; j <= n; j++) {
			if (curr_sum == sum) {
				printf("Adding the size of the sub-array (%d) to each element\n",(j-i));
				for(k=i; k<=j-1;k++)
				{
					printf("%d ", arr[k]+(j-i));
				}
				
				return 1;
			}
			if (curr_sum > sum || j == n)
				break;
			curr_sum = curr_sum + arr[j];
		}
	}
	printf("No subarray found");
	return 0;
}

//main function
int main(){
	int arr[MAX] ;
    int n, i, size;
    
    printf("\nProgram to find the smallest subarray with sum greater than the given value");
    printf("\n------------------------------------------------------------------------------");
    
    printf("\nEnter the array size (MAX = %d):- ",MAX);
    scanf("%d",&size);
    
    printf("\nEnter the array elements:-\n");
    for(i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }
    
    printf("\nEnter the no:-");
    scanf("%d",&n);
	subArraySum(arr, size, n);
	return 0;
}

