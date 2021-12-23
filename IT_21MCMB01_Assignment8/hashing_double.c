/*
Q:1 Design a HashTable (atleast size &gt;= 10) for Integers
(Use Collision Resolution Technique :- Quadratic Probing)
Provide following Function
1. Insert a Key
2. Delete a Key
3. Search a Key Using key Value
4. Calculate Load Factor
*/


#include<stdio.h>
#include<stdlib.h>

int MAX, prime;

//function to calculate the prime number that will be used in the hkey2 for double hashing
void Prime(){
	int n=MAX;
	int flag;
	while(n>0){
		flag=0;
		int m = n/2,i;
		for(i=2;i<=m;i++){
			if(n%i==0)
				flag=1;
		}
		
		if(flag==0){
			prime=n;
			break;
		}
		else{
			n--;
		}
	}	
}

//function to insert the values into the hashtable
void insert(int arr[]){
	int key, index, i, hkey1, hkey2;
	printf("\nEnter the value for insertion:- \n");
	scanf("%d",&key);
	
	hkey1 =  key%MAX;
	hkey2 = prime - (key % prime);
	
	for(i=0;i<MAX;i++){
		index=(hkey1+(i * hkey2))%MAX;
		int temp=arr[index];
		if(temp==0 || temp==-1){
			arr[index]=key;
			temp=arr[index];
			break;
		}	
	}
	
	if(i==MAX){
		printf("\nThe hash function couldn't find a location to insert this key. \n");
		return;
	}
}

//function to search a value in the hashtable
void search(int arr[]){
	int key, index,i,hkey2, hkey1;
	printf("\nEnter the element for searching:- \n");
	scanf("%d",&key);
	
	hkey1=key%MAX;
	hkey2=prime - (key % prime);
		
	for(i=0;i<MAX;i++){
		index=(hkey1+(i * hkey2))%MAX;
		int temp=arr[index];
		if(temp==key){
			printf("\nValue found at index %d\n",index);
			break;
		}
	}
	if(i==MAX){
		printf("\nElement doesn't exist\n");
		return;
	}
}

//function to delete a value from the hashtable
void delete_value(int arr[]){
	int key, index, i, hkey2, hkey1;
	printf("\nEnter the element for deletion:- \n");
	scanf("%d",&key);
	
	hkey1 = key%MAX;
	hkey2 = prime - (key % prime);
	
	for(i=0;i<MAX;i++){
		index=(hkey1+(i * hkey2))%MAX;
		int temp=arr[index];
		if(temp==key){
			arr[index]=-1;
			printf("\nValue found at index %d has been deleted \n",index);
			break;
		}
	}
	if(i==MAX){
		printf("\nElement doesn't exist\n");
		return;
	}
}

//function to display the entire hashtable
void display(int arr[]){
	int i;
	printf("\nIndex		Value\n");
	for(i=0;i<MAX;i++){
		printf("%d		%d\n",i, arr[i]);	
	}	
}

//function that calculate loadfactor of the hashtable
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
void main(){
	int choice,i;
	printf("Implementation of hashtable (collision resolution : double hashing technique)\n");
	printf("------------------------------------------------------------------------------\n");

	printf("\nEnter size of the array:- \n");
	scanf("%d",&MAX);
	
	int arr[MAX];
	for(i=0;i<MAX;i++){
		arr[i]=0;
	}
	
	Prime();
	
	while(1){
		printf("\nEnter choice:- \n");
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
}
