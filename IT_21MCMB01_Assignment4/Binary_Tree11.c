/* Binary tree implementation.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100


//creating a structure of type node
struct node{
	int data;
	struct node *left, *right;
};


//creating a structure of type location
struct location{
	struct node *loc;
};


struct node *new_node(int item){
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->data = item;
	n->left = NULL;
	n->right = NULL;
	return n;
};


//function to search for a node in the binary tree
void search(struct node *root, int data, struct location *loc_searched){
	if(root == NULL)
		return;
	else{
		search(root->left,data,loc_searched);
		search(root->right,data,loc_searched);
		
		if(root->data==data){
			loc_searched->loc=root;
		}
	}
}


//function to add left child in the binary tree
void leftChild(struct node *root){
	struct node *temp;
	struct location *loc_searched = (struct location*)malloc(sizeof(struct location));
	int parent, data;
	
	loc_searched->loc=NULL;
	
	printf("\nEnter the value of the parent node:-\n");
	scanf("%d",&parent);
	
	search(root,parent,loc_searched);
	
	if(loc_searched->loc==NULL){
		printf("\n%d doesnot exist in the tree",parent);
	}
	else{
		if(loc_searched->loc->left != NULL){
			printf("\nThere already exists a value in the left node.\n");
		}
		else{
			printf("\nEnter the value for the left node:-\n");
			scanf("%d",&data);
			temp = new_node(data);
			loc_searched->loc->left = temp;
		}
	}		
}


//function to add right child in the binary tree
void rightChild(struct node *root){
	struct node *temp;
	struct location *loc_searched = (struct location*)malloc(sizeof(struct location));
	int parent, data;
	
	loc_searched->loc=NULL;
	
	printf("\nEnter the value of the parent node:-\n");
	scanf("%d",&parent);
	
	search(root,parent,loc_searched);
	
	if(loc_searched->loc==NULL){
		printf("\n%d doesnot exist in the tree",parent);
	}
	else{
		if(loc_searched->loc->right != NULL){
			printf("\nThere already exists a value in the right node.\n");
		}
		else{
			printf("\nEnter the value for the right node:-\n");
			scanf("%d",&data);
			temp = new_node(data);
			loc_searched->loc->right = temp;
		}
	}		
}


//function to find the height of the binary tree after building the tree
int height(struct node *r){
	if(r==NULL){
		return 0;
	}
	else{
		int left = height(r->left);
		int right = height(r->right);
		if(left>right)
			return (left+1);
		else
			return (right+1);
	}
}


//function to print the preorder traversal of the binary tree
void preOrder(struct node *root){
	if(root != NULL){
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}


//function to find the inorder of the binary tree
void inOrder(struct node *root){			
	if(root != NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}


//function to find the postorder of the binary tree
void postOrder(struct node *root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ",root->data);
	}
}


//function to print data present in any level
void printLevel(struct node *root,int level){
	if(root == NULL)							
		return;
	if(level==1)
		printf("  %d   ",root->data);
	else 
	if(level>1){
		printLevel(root->left,level-1);
		printLevel(root->right,level-1);
	}
}


//function to print the binary tree in tree form
void display(struct node *root){
	int h = height(root);
	int i,j;
	
	printf("\nThe binary tree looks like:- \n");
	for(i=1;i<=h;i++){
		printf("\n");
		for(j=1;j<=h-i;j++){
			printf("    ");
		}
		printLevel(root,i);
		printf("\n");
	}
}

//main function
void main(){
	int data,choice;
	struct node *root = NULL;
	
	printf("\nImplementation of binary tree:-\n");
	printf("------------------------------------\n");
	
	printf("Enter the root data:-\n");
	scanf("%d",&data);
	root = new_node(data);
	
	
	while(choice!=8){
		
		printf("\n");
		printf("1. Left child \n");
		printf("2. Right child \n");
		printf("3. Height of the binary tree \n");
		printf("4. Preorder traversal \n");
		printf("5. Inorder traversal \n");
		printf("6. Postorder traversal \n");
		printf("7. Display in tree form \n");
		printf("8. Exit\n");
		scanf("%d",&choice);
		
		if(choice==1)
			leftChild(root);
		else
		if(choice==2)
			rightChild(root);
		else
		if(choice==3)
			printf("\nHeight of the binary tree = %d",height(root));
		else
		if(choice==4){
			printf("\nPreorder Traversal of the binary tree:- ");
			preOrder(root);
		}
		else
		if(choice==5){
			printf("\nInorder Traversal of the binary tree:- ");
			inOrder(root);
		}
		else
		if(choice==6){
			printf("\nPostorder Traversal of the binary tree:- ");
			postOrder(root);
		}	
		else
		if(choice==7){
			display(root);
		}
	}
}
