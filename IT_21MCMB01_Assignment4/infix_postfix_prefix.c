//Infix to postfix and prefix convertor
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char infix[MAX]="(";

//creating a node of type structure
struct node{
	char data;
	struct node* left;
	struct node* right;
};

//creating a node of type structure pointer
struct node* newNode(char ch){
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->data=ch;
	n->left=NULL;
	n->right=NULL;
	return n;
}

//function to check the priority of the characters
int pri(char x){
	if(x) {
		if(x==')')
			return 0;
		else if(x=='+' || x=='-')
			return 1;
		else if(x=='*' || x=='/')
			return 2;
		else if(x=='^')
			return 3;
	}
}

//function to create an expression tree for valid infix expression
struct node* exprTree(char* str){
	struct node* stackN[MAX];
	char stackC[MAX];
	struct node* t;
	struct node* t1;
	struct node* t2;
	int i,j=-1,k=-1;
	
	for(i=1;i<strlen(str);i++){
		if(str[i]=='('){
			stackC[++j]=str[i];
		}
		else
		if(isalpha(str[i])){
			t=newNode(str[i]);
			stackN[++k]=t;
		}
		else
		if(pri(str[i])>0){
			
			while(j!=-1 && str[j]!='(' && ((str[i]!='^' && pri(stackC[j])>=pri(str[i])) || (str[i]=='^' && pri(stackC[j]) > pri(str[i])))){
				t=newNode(stackC[j]);
				stackC[--j];
				
				t1=stackN[k];
				stackN[--k];
				
				t2=stackN[k];
				stackN[--k];
				
				t->left=t2;
				t->right=t1;
				stackN[++k]=t;
			}
			stackC[++j]=str[i];
		}
		else
		if(str[i]==')'){
			while(j!=-1 && stackC[j]!='('){
				t=newNode(stackC[j]);
				stackC[--j];
				
				t1=stackN[k];
				stackN[--k];
				
				t2=stackN[k];
				stackN[--k];
				
				t->left=t2;
				t->right=t1;
				stackN[++k]=t;
			}
			stackC[--j];
		}
	}
	t=stackN[k];
	return t;
}

//function to check operators 
int isOperator(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='(' || ch==')')
		return 1;
	return 0;
}

//function to check if the given input string is a valid infix expression
int checkInfix(char* str)
{ 
	int i;
	
	for(i=0;i<strlen(str);i++)
	{
		if((!isalpha(str[i])) && (!isOperator(str[i])))
			return 1;
		if(str[i]=='(' || str[i]==')')
			continue;
		int j=i;
		jiterate:
			j++;
			if(str[j]=='(' || str[j]==')') //ignores all braces 
				goto jiterate;
		if((isOperator(str[i]) && isOperator(str[j])) || (isalpha(str[i]) && isalpha(str[j]))) //checks for repetition of operands or operators
			return 1;
	}
	return 0;	
}

//function to convert infix to postfix using tree traversal
void infix_postfix(struct node* root)
{  if (root){
        infix_postfix(root->left);
        infix_postfix(root->right);
        printf("%c",root->data);
    }
}

//function to convert infix to prefix using tree traversal
void infix_prefix(struct node* root)
{  if (root){
		printf("%c",root->data);
        infix_prefix(root->left);
        infix_prefix(root->right);   
    }
}

//main function 
void main(){
	char in[MAX],ch[1]=")";
	int choice;
	
	printf("\nInfix to prefix and postfix expression converstion.");
	printf("\n-----------------------------------------------------");
	
	printf("\n\nInput the infix expression: ");
	fscanf(stdin,"%s",in);
	strncat(infix, in, strlen(in));
	strncat(infix, ch, 1);
	struct node* root=exprTree(infix);
	
	int flag=checkInfix(infix);
	if(flag==0)
		printf("\nVALID INFIX EXPRESSION.");
	else{
		printf("\nINVALID INFIX EXPRESSION.");
		exit(1);
	}
		
 	printf("\nPostfix Expression: ");
	infix_postfix(root);
	printf("\nPrefix Expression: ");
	infix_prefix(root);
}
