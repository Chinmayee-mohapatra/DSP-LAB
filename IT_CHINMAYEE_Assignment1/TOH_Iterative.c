// Implementation of tower of hanoi problem without recursion

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//creating a structure of type stack
struct stack{
	int c, top;
	int *arr;
};

//function to create stacks of type structure stack
struct stack *create(int disks){
	struct stack* s = (struct stack*)malloc(sizeof(struct stack));
	s->c = disks;
	s->top = -1;
	s->arr = (int *)malloc(sizeof(int) * s->c);
	return s;
}

//Function to push an item onto the stack if it isn't full else returns simply.
void push(struct stack *stack, int item){  
    if (stack->top == stack->c - 1)  	
        return;  
    
	stack->arr[++stack -> top] = item;  
}  
  
//Function to pop an item from stack if its not empty else returns the minimun number.
int pop(struct stack* stack){  
    if (stack->top == -1)  						
        return INT_MIN;  
    
	return stack->arr[stack -> top--];  
}  

//Function that shows movement of disks  
void move_disk(char t1, char t2, int disk){  
    printf("\n Move disk %d from '%c' to '%c'",disk, t1, t2);  
} 
  
// Function to perform movement between two poles  
void move_disk2(struct stack *s, struct stack *d, char src, char dest){  
    int pole1 = pop(s);  
    int pole2 = pop(d);  
  
    // When pole 1 is empty  
    if (pole1 == INT_MIN)  
    {  
        push(s, pole2);  
        move_disk(dest, src, pole2);  
    }  
  
    // When pole2 pole is empty  
    else if (pole2 == INT_MIN)  
    {  
        push(d, pole1);  
        move_disk(src, dest, pole1);  
    }  
  
    // if top disk of pole1 > top disk of pole2  
    else if (pole1 > pole2)  
    {  
        push(s, pole1);  
        push(s, pole2);  
        move_disk(dest, src, pole2);  
    }  
  
    // if top disk of pole1 < top disk of pole2  
    else
    {  
        push(d, pole2);  
        push(d, pole1);  
        move_disk(src, dest, pole1);  
    }  
}  
  
//Function to implement tower of hanoi
void towerOfHanoi(int n, struct stack *s, struct stack *a, struct stack *d)  
{  
    int i, total_mov;  
    char src = 'S', dest = 'D', aux = 'A';  
  
    //If numberOfDisk is even, swap end with aux tower
    if (n % 2 == 0)  
    {  
        char temp = dest;  
        dest = aux;  
        aux = temp;  
    }  
    
    total_mov = pow(2, n) - 1;  
  
    //Larger disks will be pushed first  
    for (i = n; i >= 1; i--)  
        push(s, i);  
  
    for (i = 1; i <= total_mov; i++)  
    {  
        if (i % 3 == 1)  
        move_disk2(s, d, src, dest);  
        else if (i % 3 == 2)  
        move_disk2(s, a, src, aux);  
        else if (i % 3 == 0)  
        move_disk2(a, d, aux, dest);  
    }  
}

  
//main function
int main(){
	int n,disks;
	struct stack *s, *a, *d;
	
	printf("Implementation of tower of hanoi problem without recursion.\n");
	printf("------------------------------------------------------------\n");
	
	while(1){
		printf("\n\nEnter the no of disks:- ");
		scanf("%d",&n);
	
    	s = create(n);  
    	a = create(n);  
    	d = create(n);  
    	
		towerOfHanoi(n,s,a,d);
	}
	
	return 0;
}
