/*
Q:3 Implement Heap-sort Algorithm Using Min-Heapify and Max-Heapify
Procedures.
Your Program Should Work Like This
Choose option
1. Using min-heapify
2. Using Max-heapify

After selecting either of the option

Implement following functions(for both options) :
1. Build Heap by inserting some integers.
2. Insert a key into heap.
3. Delete function.
4. Sort function.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr1[MAX],*arr2;

//function to perform max-heapify
void max_heapify(int arr[], int i, int heapsize){
	int temp, largest, l, r;
	l = (2*i + 1);
	r = (2*i + 2);
	largest = i;
	
	if(l<heapsize && arr[l]>arr[i])
		largest = l;
	if(r<heapsize && arr[r]>arr[largest])
		largest = r;
	if(largest != i){
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heapify(arr,largest,heapsize);
	}		
}

//function to build a max heap
int *buildMaxHeap(int arr[], int items){
	int heapsize = items;
	int j;
	for(j = items/2; j>=0; j--){
		max_heapify(arr,j,heapsize);
	}
	return arr;
}

//function to insert element into max heap
void insert_max(int element, int items){
	int parent;
	while(items>0){
		parent = (items-1)/2;
		if(element<=arr1[parent]){
			arr1[items]=element;
			return;
		}
		arr1[items]  = arr1[parent];
		items = parent;
	}
	arr1[0] = element;
}

//function to delete element from max heap
void delete_max(int arr[],int items){
	int last = arr[items-1];
	arr[0] = last;
	items=items-1;
	max_heapify(arr,0,items);
}

//function to perform heapsort on max heap
void heapsort_max(int arr[],int items){
	int i,temp;
	
	for(i=items/2-1; i>=0; i--)
		max_heapify(arr,i,items);
	for(i=items-1; i>0; i--){
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		max_heapify(arr,0,i);
	}	
}

//function to perform min-heapify
void min_heapify(int arr[], int i, int heapsize){
	int temp, smallest, l, r;
	l = (2*i +1);
	r = (2*i + 2);
	smallest = i;
	
	if(l<heapsize && arr[l]<arr[i])
		smallest = l;
	if(r<heapsize && arr[r]<arr[smallest])
		smallest = r;
	if(smallest != i){
		temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
		min_heapify(arr,smallest,heapsize);
	}
}

//function to build a min heap
int *buildMinHeap(int arr[], int items){
	int heapsize = items;
	int j;
	for(j=items/2; j>=0; j--){
		min_heapify(arr,j,heapsize);
	}
	return arr;
}

//function to insert element into min heap
void insert_min(int element, int items){
	int parent;
	while(items>0){
		parent = (items-1)/2;
		if(element>=arr1[parent]){
			arr1[items]=element;
			return;
		}
		arr1[items]  = arr1[parent];
		items = parent;
	}
	arr1[0] = element;
}

//function to delete element from min heap
void delete_min(int arr[],int items){
	int last = arr[items-1];
	arr[0] = last;
	items=items-1;
	min_heapify(arr,0,items);
}

//function to perform heapsort on min heap
void heapsort_min(int arr[],int items){
	int i,temp;
	
	for(i=items/2-1; i>=0; i--)
		min_heapify(arr,i,items);
	for(i=items-1; i>0; i--){
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		min_heapify(arr,0,i);
	}	
}

//function to print the array
void printArray(int arr[], int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

//main function
int main(){
	int i, items, choice, ch1, ch2, element;
	int flag=0;
	
	printf("\nImplementation of Heap-sort Algorithm Using Min-Heapify and Max-Heapify:- ");
	printf("\n-------------------------------------------------------------------------\n");
	
	menu:		
		printf("\nEnter choice: \n");
		printf("1. Using max_heapify \n");
		printf("2. Using min_heapify  \n");
		printf("3. Exit \n");
		scanf("%d",&choice);
		
		if(choice == 1){
			ch_1:
			printf("\nOperations on Max_heap :- ");
			printf("\n11. Build Max_heap by inserting integers");
			printf("\n12. Insert a key into heap");
			printf("\n13. Delete a key from heap");
			printf("\n14. Sort the elements");
			printf("\n15. Retun to MENU");
			printf("\n16. Exit\n");
			scanf("%d",&ch1);
			
			if(ch1 == 11){
				printf("\nEnter the no of elements (MAX = %d) :- ",MAX);
				scanf("%d",&items);	
					
				for(i=0;i<items;i++){
					scanf("%d",&arr1[i]);
				}

				arr2 = buildMaxHeap(arr1,items);
				
				printf("\nMax_heap :-\n");
				printArray(arr2,items);
				goto ch_1;
			}
			else 
			if(ch1 == 12){
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&element);
				
				insert_max(element,items);
				printf("\nMax_heap after insertion operation:-\n");				
				
				items = items+1;
				printArray(arr1,items);
				goto ch_1;
			}
			else 
			if(ch1 == 13){
				flag = 1;
				delete_max(arr1,items);
				printf("\nMax_heap after deletion opeartion:-\n");								
				printArray(arr1,items-1);
				goto ch_1;
			}
			else 
			if(ch1 == 14){
				if(flag == 1)
					items--;
				heapsort_max(arr1,items);
				printf("\nMax_heap after sorting:-\n");					
				printArray(arr1,items);
				goto ch_1;
			}
			else 
			if(ch1 == 15){
				goto menu;
			}
			else
			if(ch1 == 16){
				exit(1);
			}
			else{
				printf("\nInvalid choice..Try again.");
				goto menu;
			}
		}
		else
		if(choice == 2){
			ch_2:
			printf("\nOperations on Min_heap : ");
			printf("\n21. Build Min_heap by inserting integers");
			printf("\n22. Insert a key into heap");
			printf("\n23. Delete a key from heap");
			printf("\n24. Sort the elements");
			printf("\n25. Retun to MENU");
			printf("\n26. Exit\n");
			scanf("%d",&ch2);
			
			if(ch2 == 21){
				printf("\nEnter the no of elements (MAX = %d) :- ",MAX);
				scanf("%d",&items);
		
				for(i=0;i<items;i++){
					scanf("%d",&arr1[i]);
				}
				
				arr2 = buildMinHeap(arr1,items);
				printf("\nMin_heap :-\n");				
				printArray(arr2,items);
				goto ch_2;
				
			}
			else 
			if(ch2 == 22){
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&element);
				
				insert_min(element,items);
				printf("\nMin_heap after insertion operation:-\n");				
				items = items+1;
				printArray(arr1,items);
				goto ch_2;	
			}
			else 
			if(ch2 == 23){
				flag = 1;
				delete_min(arr1,items);
				printf("\nMin_heap after deletion operation:-\n");				
				printArray(arr1,items-1);
				goto ch_2;				
			}
			else 
			if(ch2 == 24){
				if(flag == 1)
					items--;
				heapsort_min(arr1,items);
				printf("\nMin_heap after sorting:-\n");								
				printArray(arr1,items);
				goto ch_2;
				
			}
			else 
			if(ch2 == 25){
				goto menu;
			}
			else
			if(ch2 == 26){
				exit(1);
			}
			else{
				printf("\nInvalid choice..Try again.");
				goto ch_2;
			}
		}
		else
		if(choice == 3){
			exit(1);
		}
		else{
			printf("\nInvalid choice..try again.");
			goto menu;
		}
	
	return 0;
}
