/*
Q:2 Design a HashTable (atleast size &gt;= 10) for Integers
(Use Collision Resolution Technique :- Double Hashing)
Provide following Function
1. Insert a Key
2. Delete a Key
3. Search a Key Using key Value
4. Calculate Load Factor
*/

#include<stdio.h>
#include<stdlib.h>

int MAX;

//function to insert a value into the hash table
void insert(int arr[]){
	int key, index, i,hkey;
	printf("\nEnter the value for insertion:- \n");
	scanf("%d",&key);
	
	hkey=key%MAX;
	
	for(i=0;i<MAX;i++){
		index=(hkey+(i*i))%MAX;
		int temp=arr[index];
		if(temp==0 || temp==-1){
			arr[index]=key;
			temp=arr[index];
			break;
		}	
	}
	
	if(i==MAX){
		printf("\nNo more insertion is possible as the hash table is full\n");
		return;
	}
}

//function used to search for a value in the hash table
void search(int arr[]){
	int key, hkey, i, index;
	printf("\nEnter the element for searching:- \n");
	scanf("%d",&key);
	
	hkey=key%MAX;
	
	for(i=0;i<MAX;i++){
		index=(hkey+(i*i))%MAX;
		int temp=arr[index];
		if(temp==key){
			printf("\nValue is found at index %d\n",index);
			break;
		}
	}
	
	if(i==MAX){
		printf("\nElement doesn't exist \n");
		return;
	}
}

//function used to delete a value from the hash table
void delete_value(int arr[]){
	int key, hkey, i, index;
	printf("\nEnter the element for deletion:- \n");
	scanf("%d",&key);
	
	hkey=key%MAX;
	
	for(i=0;i<MAX;i++){
		index=(hkey+(i*i))%MAX;
		int temp=arr[index];
		if(temp==key){
			arr[index]=-1;
			printf("\nValue at index %d has been deleted\n",index);
			break;
		}
	}
	if(i==MAX){
		printf("\nElement doesn't exist\n");
		return;
	}
}

//function to display the entire hash table
void display(int arr[]){
	int i;
	printf("\nIndex		Value\n");
	for(i=0;i<MAX;i++){
		printf("%d	%d\n",i, arr[i]);	
	}	
}

//function to calculate load factor
float load_factor(int arr[]){
	int n=0, i;
	for(i=0;i<MAX;i++){
		if(arr[i]>0){
			n++;
		}
	}
	return (float)n/(float)MAX;
}

//main function
int main(){
	int i,choice;
	
	printf("Implementation of hashtable (collision resolution technique: Quadratic probing)\n");
	printf("---------------------------------------------------------------------------------\n");
	
	printf("\nEnter size of the array:- \n");
	scanf("%d",&MAX);
	
	int arr[MAX];
	
	for(i=0;i<MAX;i++){
		arr[i]=0;
	}
	
	while(1){
		printf("\n");
		printf("Enter choice for the hash operation:-\n");	
		printf("1. Insert a key\n");
		printf("2. Search a key\n");
		printf("3. Delete a key\n");
		printf("4. Display the hashtable.\n");
		printf("5. Calculate load factor\n");
		printf("6. Exit \n");
		scanf("%d",&choice);
		
		if(choice == 1){
			insert(arr);
		}
		else 
		if(choice == 2){
			search(arr);
		}
		else 
		if(choice == 3){
			delete_value(arr);
		}
		else 
		if(choice == 4){
			display(arr);
		}
		else 
		if(choice == 5){
			float loadfactor=load_factor(arr);
			printf("\nLoad Factor= %f\n",loadfactor);
		}
		else 
		if(choice == 6){
			exit(1);
		}
		else{
			printf("\nInvalid choice.. Try again !!\n");
		}
	}
	return 0;
}
