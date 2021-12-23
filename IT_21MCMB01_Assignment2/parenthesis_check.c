/*Question 1: */

#include<stdio.h>
#include<string.h>
#define MAX 100

int t=-1;
char stack[MAX];

//function to push an item into the stack
void push(char s){
	stack[++t]=s;
}

//function to pop from the stack
char pop(){
	return stack[t--];
}

//main function
void main(){
	char str[MAX];
	char ch;
	
	printf("\nProgram to check for paranthesis:- \n");
	printf("--------------------------------------\n");
	
	while(1){
		printf("\nEnter the string (string length: %d):-",MAX);
		scanf("%s",str);
		int p=1,i=0;
		
		while(str[i]!='\0'){
			if(str[i]=='(' || str[i]=='{' || str[i]=='[')
				push(str[i]);
		
			if(str[i]==')' || str[i]=='}' || str[i]==']'){
				if(t==-1)
					p=0;
				else{
					ch=pop();
					if(str[i]==')' && ch!='(')
						p=0;
					if(str[i]=='}' && ch!='{')
						p=0;
					if(str[i]==']' && ch!='[')
						p=0;
				}	
			}
			i++;
		}
		if(t>=0)
			p=0;
		if(p==1)
			printf("\nTRUE");
		else
			printf("\nFALSE");
	}
}
