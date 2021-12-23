//Implementation of binary tree for traversal
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//creating a node of type structure
struct node{
	int data;
	int right_count;
	int left_count;
	struct node* left;
	struct node* right;
};

//creating a node of type structure pointer
struct node* new_node(int item){
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=item;
	n->left_count=0;
	n->right_count=0;
	n->left=NULL;
	n->right=NULL;
	
	return n;
};

//function to check for a perfect binary tree
int PerfectBT(int count){
	count += 1;
	
	while(count%2 == 0)
		count=count/2;
		
	if(count == 1)
		return 1;
	else
		return 0;
}

//function to build a binary tree 
struct node* buildTree(struct node* root,int data){
	if(root == NULL){
		struct node *n=new_node(data);
		return n;
	}
	
	if(root->right_count == root->left_count){
		root->left = buildTree(root->left,data);
		root->left_count++;
	}
	else
	if(root->right_count < root->left_count){
		
		if(PerfectBT(root->left_count)){
			root->right = buildTree(root->right,data);
			root->right_count++;
		}
		else{
			root->left = buildTree(root->left,data);
			root->left_count++;
		}
	}
	return root;
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

//function to print the inorder traversal of the binary tree
void inOrder(struct node *root){			
	if(root != NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
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

//function to print the postorder traversal of the binary tree
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
int main(){
	int arr[MAX];
	int i,length,choice,ht;
	struct node *root=NULL;
	
	printf("\nImplementation of binary tree for traversal:- ");
	printf("\n-------------------------------------------------");

	printf("\nEnter the no of elements for the binary tree: ");
	scanf("%d",&length);
	printf("\nEnter elements data: ");
	for(i=0;i<length;i++)
		scanf("%d",&arr[i]);

	while(1){
		printf("\n");
		printf("\nEnter choices:- ");
		printf("\n1.Build Binary Tree");
		printf("\n2.Height of the binary tree");
		printf("\n3.Inorder traversal");
		printf("\n4.Preorder traversal");
		printf("\n5.Postorder traversal");
		printf("\n6.Display in tree form");
		printf("\n7.Exit\n");
		scanf("%d",&choice);
		if(choice==1){
			for(i=0;i<length;i++)
				root=buildTree(root,arr[i]);
		}
		else
		if(choice==2){
			ht = height(root);
			printf("The height of the binary tree = %d\n",ht);
		}
		else
		if(choice==3){
			printf("\nInorder Traversal of the binary tree:- ");
			inOrder(root);
		}
		else
		if(choice==4){
			printf("\nPreorder Traversal of the binary tree:- ");
			preOrder(root);
		}
		else
		if(choice==5){
			printf("\nPostorder Traversal of the binary tree:- ");
			postOrder(root);
		}
		else
		if(choice==6){
			display(root);
		}
		else
		if(choice==7){
			exit(1);
		}
		else{
			printf("\nINVALID CHOICE!!\n");
		}
		
	}		
	return 0;
}
