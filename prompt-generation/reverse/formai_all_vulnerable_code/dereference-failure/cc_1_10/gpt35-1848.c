//FormAI DATASET v1.0 Category: Graph representation ; Style: creative
/* A unique C program to represent a Graph */
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Defining a structure for adjacency list node
struct AdjListNode{
  int vertex;
  int weight;
  struct AdjListNode* next;
};

// Defining a structure for adjacency list
struct AdjList{
  struct AdjListNode* head;
};

// Defining a structure for Graph
struct Graph{
  int numVertices;
  struct AdjList* list;
};

// Function to create adjacency list node
struct AdjListNode* createNode(int vertex, int weight){
  struct AdjListNode* node = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
  node->vertex = vertex;
  node->weight = weight;
  node->next = NULL;
  return node;
}

// Function to initialize the graph
struct Graph* createGraph(int numVertices){
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = numVertices;
  graph->list = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));

  int i;
  for(i = 0; i < numVertices; i++){
    graph->list[i].head = NULL;
  }
  return graph;
}

// Function to add edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight){
  struct AdjListNode* node = createNode(dest, weight);
  node->next = graph->list[src].head;
  graph->list[src].head = node;

  node = createNode(src, weight);
  node->next = graph->list[dest].head;
  graph->list[dest].head = node;
}

// Function to print the graph
void printGraph(struct Graph* graph){
  int v;
  for(v = 0; v < graph->numVertices; v++){
    struct AdjListNode* ptr = graph->list[v].head;
    printf("\n Adjacency list of vertex %d \n head ", v);
    while(ptr){
      printf("-> %d(%d) ", ptr->vertex, ptr->weight);
      ptr = ptr->next;
    }
    printf("\n");
  }
}

// Main function
int main(){
  int numVertices = 5;
  struct Graph* graph = createGraph(numVertices);
  addEdge(graph, 0, 1, 2);
  addEdge(graph, 0, 3, 6);
  addEdge(graph, 1, 2, 3);
  addEdge(graph, 1, 3, 8);
  addEdge(graph, 1, 4, 5);
  addEdge(graph, 2, 4, 7);
  addEdge(graph, 3, 4, 9);

  printf("Graph representation using adjacency list: \n");
  printGraph(graph);

  return 0;
}