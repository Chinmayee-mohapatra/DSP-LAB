//Implementation of n-ary tree

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>
#define MAX 50

int l1count=0,maxfreq=INT_MIN,i;

//creating a node of structure type
struct node{
	int freq;
	char word[30];
	struct node* child;
	struct node* sibling;
};

//creating a node of type structure pointer
struct node* create_node(char *data){
	struct node* n=(struct node*)malloc(sizeof(struct node));
	strcpy(n->word,data);
	n->freq = 1;
	n->child = NULL;
	n->sibling = NULL;
	
	return n;
}

//function to check the category list present at level 1 in the tree
int check_l1(char *category, struct node* root){
	struct node* temp = root->child;
	while(!temp){
		if(strcmp(temp->word,category)==0){
			printf("\nCategory already exists.");
			return 0;
		}
		temp = temp->sibling;
	}
	return 1;
}

//function to count the depth of any node
int depth(struct node* root,char *input){
	
	if(strcmp(root->word,input)==0){
			printf("\n Depth is 0 \n");
			return 1;	
	}
	struct node *t1=root->child;
	struct node *ptr=t1;
	while(ptr!=NULL){
		if(strcmp(ptr->word,input) == 0){
			printf("\n Depth is 1 \n");
			return 1;
		}
		else{
			struct node *t2=ptr->child;
			struct node *ptr2=t2;
			while(ptr2!=NULL){
				if(strcmp(ptr2->word,input)== 0){
					printf("\n Depth is 2 \n");
					return 1;
				}
				ptr2=ptr2->sibling;
			}
		}
		ptr=ptr->sibling;
	}
	return 0;
}

//function to count the child nodes
void childcount(struct node* ptr){
	
	int count=1;
	if(ptr->child==NULL){
		printf("\n Degree of the node is 0, as it is leaf node\n");
	}
	else{
		struct node *ptr2=ptr->child;
		while(ptr2->sibling!=NULL){
			count++;
			ptr2=ptr2->sibling;
		}
		printf("\n Degree of the node is %d .\n",count);
	}
}

//function to count the degree of a node
int degree(struct node* root,char *input){
	
	if(strcmp(root->word,input)==0){
			childcount(root);
			return 1;	
	}
	struct node *t1=root->child;
	struct node *ptr=t1;
	while(ptr!=NULL){
		if(strcmp(ptr->word,input) == 0){
			childcount(ptr);
			return 1;
		}
		else{
			struct node *t2=ptr->child;
			struct node *ptr2=t2;
			while(ptr2!=NULL){
				if(strcmp(ptr2->word,input)== 0){
					childcount(ptr2);
					return 1;
				}
				ptr2=ptr2->sibling;
			}
		}
		ptr=ptr->sibling;
	}
	return 0;
}

//function to display the words in decreasing order of their frequency
void print(struct node* root){
	for(i=maxfreq;i>1;i--) {
		struct node *t1=root->child;
		while(t1!=NULL){
			if(t1->child){
				struct node *t2=t1->child; 
				while(t2!=NULL){
					if(t2->child){
						int temp=t2->child->freq;
						if(temp==i)
							printf("\n For frequency: %d the Word is: %s",i,t2->word);
					}
					t2=t2->sibling;
				}
			}
			t1=t1->sibling;
		}	
	}
	//below code print words with frequency == 1
	struct node *t1=root->child;
	while(t1!=NULL){
		if(t1->child!=NULL){
			struct node *t2=t1->child;
			while(t2!=NULL){
				if(t2->child==NULL)
					printf("\n For frequency: 1 the Word is: %s",t2->word);
				t2=t2->sibling;
			}
		}
		t1=t1->sibling;
	}
}

//main function 
int main(){
	int ch,i=0;
	char category[MAX],input[MAX];
	struct node* root = create_node("Words");
	struct node* l1 = create_node("Words");
	root->child = l1;
	
	printf("\nImplementation of n-ary tree");
	printf("\n-------------------------------");
	
	menu:
		printf("\nEnter your choice :-");
		printf("\n1: Add category");
		printf("\n2: Input words for the respective category");
		printf("\n3: Display leaf nodes");
		printf("\n4: Depth of any node");
		printf("\n5: Degree of any node ");
		printf("\n6: Display the words in descending order of frequency ");
		printf("\n0: Exit \n");
		scanf("%d",&ch);
		
		if(ch==1){
			category_input:
				printf("Enter category :-");
				scanf(" %[^\n]%*c",category);
				if(i==0){
					strcpy(l1->word,category);
					i++;
				}
				else{
					if(check_l1(category,root)==0)//check if category already exists
						goto category_input;
					
					struct node* new_node = create_node(category);
					struct node* ptr = l1;
					while(ptr->sibling != NULL)
						ptr = ptr->sibling;
					ptr->sibling = new_node;	
				}
				printf("\nCategory added to the tree succesfully");
				l1count++;
		}
		else
		if(ch==2){
			struct node* ptr = l1;
			if(l1count == 0){
				printf("\nAdd category, the list is empty for now.");
				goto menu;
			}
			printf("\nSelect category from the list :- \n");
			for(i=1;i<=l1count;i++){
				printf("%d. %s\n",i,ptr->word);
				ptr = ptr->sibling;
			}
			scanf("%d",&ch);			
			if(ch>l1count || ch<0){
				printf("Invalid Choice!! Try again");
				goto menu;
			}

			ptr = l1;
			i=1;
			while(i<ch){
				ptr = ptr->sibling;
				i++;
			}
			printf("\nEnter word for %s category : ",ptr->word);
			scanf("%s",input);
			if(ptr->child==NULL){
				struct node *newnode=create_node(input);
				ptr->child=newnode;	
			}
			else{
				struct node *l2=ptr->child;
				struct node *ptr2=l2;
				int flag=0;
				while(ptr2!=NULL){
					if(strcmp(ptr2->word,input)==0){ // word found inside the category selected.
						flag=1;
						if(ptr2->child==NULL){
							struct node *newnode=create_node("");
							newnode->freq=2;
							ptr2->child=newnode;
						}
						else{
							int temp=ptr2->child->freq;
							temp++;
							ptr2->child->freq=temp;
							if(temp>maxfreq)
								maxfreq=temp;
						}
					}
					ptr2=ptr2->sibling;
				}
				
				if(flag==0){
					ptr2=l2;
					while(ptr2->sibling!=NULL)
						ptr2=ptr2->sibling;
					struct node *newnode=create_node(input);
					ptr2->sibling=newnode;
				}
			}
		}
		else
		if(ch==3){
			struct node *l1=root->child;
			struct node *ptr=l1;
			while(ptr!=NULL){
				if(ptr->child==NULL){
					printf("%s \n",ptr->word);
				}
				else{
					struct node *l2=ptr->child;
					struct node *ptr2=l2;
					while(ptr2!=NULL){
						if(ptr2->child==NULL)
							printf("%s\n",ptr2->word);
						ptr2=ptr2->sibling;
					}
				}
				ptr=ptr->sibling;
			}
		}
		else
		if(ch==4){
			char input[MAX];
			printf("\nEnter string of the node\n");
			scanf("%s",input);
			int flag=0;
			flag=depth(root,input);
			if(flag==0)
				printf("\nThe input string didn't match with any node in the tree\n");
		}
		else
		if(ch==5){
			char input[MAX];
			printf("\nEnter string of the node\n");
			scanf("%s",input);
			int flag=0;
			flag=degree(root,input);
			if(flag==0)
				printf("\nThe input string didn't match with any node in the tree\n");
		}
		else
		if(ch==6){
			print(root);
			goto menu;
		}
		else
		if(ch==0){
			exit(1);
		}
		else{
			printf("\nInvalid Choice!! Try again");
			goto menu;
		}
		goto menu;
	return 0;
}
