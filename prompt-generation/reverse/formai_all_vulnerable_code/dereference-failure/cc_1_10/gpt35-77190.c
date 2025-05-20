//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

void addEdge(struct node *list[], int src, int dest){
  // Add an edge from src to dest
  struct node* newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = dest;
  newNode->next = list[src];
  list[src] = newNode;
}

void printGraph(struct node *list[], int vertices){
  // Print adjacency list representation of graph
  int i;
  for(i=0;i<vertices;i++){
    struct node* temp = list[i];
    printf("\n Vertex %d\n",i);
    while(temp){
      printf(" -> %d", temp->data);
      temp = temp->next;
    }
  }
}

int main(){
  // Number of vertices in graph
  int vertices = 4;
  
  // Adjacency list representation of graph
  struct node *list[vertices];
  
  // Initialize all elements of list to zero
  int i;
  for(i=0;i<vertices;i++){
    list[i] = NULL;
  }
  
  // Add edges to graph
  addEdge(list, 0, 1);
  addEdge(list, 0, 2);
  addEdge(list, 1, 2);
  addEdge(list, 2, 0);
  addEdge(list, 2, 3);
  addEdge(list, 3, 3);
  
  // Print the graph
  printGraph(list, vertices);
  
  return 0;
}