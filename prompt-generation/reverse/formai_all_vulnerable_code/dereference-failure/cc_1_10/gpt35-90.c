//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include<stdio.h>
#include<stdlib.h>

/* Let's create a curious graph with nodes having the ASCII codes of letters as values */

typedef struct Node{
   int val;
   struct Node* next;
}Node;

void createEdge(Node** graph, int src, int dest){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = dest;
    newNode->next = graph[src];
    graph[src] = newNode;
}

void curiousDFS(Node** graph, int node, int* visited){
    printf("%c ", node); // printing the node value as an ASCII character
    visited[node] = 1;

    Node* temp = graph[node];
    while(temp!=NULL){
        int curr = temp->val;
        if(!visited[curr]){
            curiousDFS(graph, curr, visited);
        }
        temp = temp->next;
    }
}

int main(){
   Node** graph = (Node**)malloc(sizeof(Node*)*26); // create an array on heap for 26 alphabets
   
   // initialize the graph
   for(int i=0; i<26; i++){
       graph[i] = NULL;
   }
   
   createEdge(graph, 'A'-65, 'B'-65); // ASCII code of 'A'=65, 'B'=66, and so on. Subtracting 65 to get their values in the range [0, 25]
   createEdge(graph, 'A'-65, 'D'-65);
   createEdge(graph, 'B'-65, 'C'-65);
   createEdge(graph, 'B'-65, 'D'-65);
   createEdge(graph, 'C'-65, 'E'-65);
   createEdge(graph, 'D'-65, 'E'-65);
   createEdge(graph, 'D'-65, 'F'-65);
   createEdge(graph, 'E'-65, 'E'-65); // Adding a self-loop for the fun of it!
   createEdge(graph, 'E'-65, 'F'-65);
   createEdge(graph, 'E'-65, 'G'-65);
   createEdge(graph, 'F'-65, 'G'-65);

   printf("The curious graph in its DFS traversal order: ");
   int* visited = (int*)calloc(sizeof(int), 26); // create an array on heap for keeping track of visited nodes
   curiousDFS(graph, 'A'-65, visited); // starting from node A
   printf("\n"); // new line for formatting
   free(visited); // freeing heap memory used by visited array
   visited=NULL; // since memory has been freed
   for(int i=0; i<26; i++){
       Node* curr = graph[i];
       while(curr!=NULL){
           Node* temp = curr;
           curr = curr->next;
           free(temp); // freeing heap memory for all nodes in the graph
       }
       graph[i] = NULL;
   }
   free(graph); // freeing heap memory used by graph array
   graph=NULL; // since memory has been freed
   return 0;
}