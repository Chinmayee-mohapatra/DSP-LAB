/*
Question: Create a menu-driven program:-
(Take the No. of vertices from the user, enter the Node and make an adjacency matrix after that 
print the BFS and DFS traversal).
1.)Create a Graph.
2.)Do BFS traversal in the Graph
3.)Do DFS traversal in the Graph
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
int vertex, edge;
int adjMatrix[10][10];

//function to add edge between the said vertices
void addEdge(int x, int y){
    if ((x >= vertex) || (y >= vertex)) {
        printf("\nVertex does not exists");
    }
    if (x == y) {		
        printf("\nSelf loop!");
    }
    else{
        adjMatrix[y][x] = 1;
        adjMatrix[x][y] = 1;
    }
}

//function to create a graph
void createGraph(int vert){
	int i,j;
	
	for (i = 0; i < vert; ++i) {
        for (j = 0; j < vert; ++j) {
            adjMatrix[i][j] = 0;
        }
	}
	
	printf("\nEnter the number of edges: ");
	scanf("%d",&edge);
	printf("\nEnter the edges:\n");
	for(i=0;i<edge;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		addEdge(a,b);
	}
}

//function for bfs graph traversal
void bfs(int source, int vert){
	int queue[MAX], i, rear = -1, front = 0, queueCount = 0, visited[vert] , unvisited;
	
	for(i=0;i<vert;i++)
		visited[i]=0;
	
	visited[source]=1;
	printf("%d ",source);
	
	queue[++rear]=source;
	queueCount++;
	
	bool isQueueEmpty() {
   		return queueCount == 0;
	}
	
	int removeData() {
   		queueCount--;
   		return queue[front++]; 
   	}
	
	int adjUnvisitedVertex(int vertexIndex) {
   		int i;
   		for(i = 0; i<vert; i++) {
      		if(adjMatrix[vertexIndex][i] == 1 && visited[i] == 0)
         		return i;
   		}
   		return -1;
	}
	
	while(!isQueueEmpty()) {
      	int tempVertex = removeData();		//remove the unvisited vertex  

      	while((unvisited = adjUnvisitedVertex(tempVertex)) != -1) {    
         	visited[unvisited] = 1;
         	printf("%d ",unvisited);
         	queue[++rear]=unvisited;
			queueCount++;              
      	}	
   	}   	
}

//function for dfs graph traversal
void dfs(int source, int vert){
	int i, visited[vert], stack[MAX], top = -1;
	
	for(i=0;i<vert;i++)
		visited[i]=0;
	visited[source]=1;

	bool isStackEmpty() {
   		return top == -1;
	}

	int adjUnvisitedVertex(int vertexIndex) {
   		int i;
   		for(i = 0; i<vert; i++) {
      		if(adjMatrix[vertexIndex][i] == 1 && visited[i] == 0)
        	 	return i;
   			}
   			return -1;
		}
		
		printf("%d ", source);
		stack[++top] = source;

	while(!isStackEmpty()) {
	    int unvisited = adjUnvisitedVertex(stack[top]);		//unvisited vertex from stack[] is stored

      //no adjacent vertex found
      	if(unvisited == -1) {
         	stack[top--];				//pop the element from stack[]		
      	}
		else{
         	visited[unvisited] = 1;
         	printf("%d ",unvisited);
         	stack[++top] = unvisited;		//push the element into stack[] 
      	}
   	}
}

//main function
int main(){
	int choice, src;
	
	printf("\nImplemenattion of BFS and DFS for graph traversal.");
	printf("\n---------------------------------------------------");
	
	printf("\nEnter the number of vertices: ");
	scanf("%d",&vertex);
	
	createGraph(vertex);
	
	printf("\nEnter source node: ");
	scanf("%d",&src);
	
	printf("\nEnter choice:-");
	printf("\n1. BFS traversal");
	printf("\n2. DFS traversal\n");
	scanf("%d",&choice);

	if(choice==1){
		printf("Performing BFS:");
		bfs(src, vertex);		
	}
	else if(choice==2){
		printf("\nPerforming DFS:\n");	
		dfs(src, vertex);				
	}
	else{
		printf("\nInvalid choice!!");
	}
	return 0;
}
