/* Infix to postfix and then evaluate postfix. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1,k=-1;

//function to push an item into the stack
void push(char a){
	stack[++top]=a;
}

//function to pop an item from the stack
int pop(){
	if(top==-1)
		return -1;
	else
		return stack[top--];
}

//function to get the precedence of the operators
int precedence(char a){
	if(a=='(')
		return 0;
	if(a=='+'||a=='-')
		return 1;
	if(a=='*'||a=='/')
		return 2;
}

int isOperator(char a){
	if(a=='+' ||a=='-'||a=='*'||a=='/'||a=='('||a==')'){
		return 1;
	}
	else{
		printf("Invalid Operator\n");
		exit(1);
	}
}

//function to evaluate postfix expression
int eval_postfix(char *postfix) {
	char ch;
 	int i = 0, op1, op2;
 	while((ch = postfix[i++]) != 0) {
		if(isdigit(ch)) 
			push(ch-'0');
		else { 
			op2 = pop();
			op1 = pop();
			if(ch) {
				if(ch=='+')
					push(op1+op2); 
		
 				else if(ch=='-')
				 	push(op1-op2); 
							
 				else if(ch=='*')
				 	push(op1*op2);
 				
 				else if(ch=='/')
				 	push(op1/op2);
 			}
 		}
 	}
 	return stack[top];
}

//main function
void main(){
	char infix[50],postfix[50];
	char x;
	int k=0;
	printf("Enter the expression:- \n");
	scanf("%s",infix);
	char *e = infix;
	
	printf("\nPostfix Expression:- \n");
	while(*e != '\0'){
		if(isalpha(*e)){
			printf("%c",*e);
			postfix[k++]=*e;
		}	
		else if(*e=='('){
			push(*e);
		}
			
		else if(*e==')'){
			while((x=pop())!='('){
				printf("%c",x);
				postfix[k++]=x;
			}
		}
		else{
			while(precedence(stack[top]) >= precedence(*e)){
				printf("%c",x=pop());
				postfix[k++]=x;
			}
			push(*e);
		}
		e++;
	}
	while(top != -1){
		printf("%c",x=pop());
		postfix[k++]=x;
	}
	
	printf("\nEvaluation of postfix expression : %d\n",eval_postfix(postfix));
}
