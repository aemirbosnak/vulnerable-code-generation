//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

//Define a structure to represent graph node
typedef struct GraphNode {
  int data;
  struct GraphNode* next;
} GraphNode, *GraphNodePtr;

//Define a function to create a new graph node
GraphNodePtr createGraphNode(int data) {
  GraphNodePtr newNode = (GraphNodePtr) malloc(sizeof(GraphNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

//Define a function to add an edge to a graph
void addEdge(GraphNodePtr graph[], int source, int destination) {
  GraphNodePtr newNode = createGraphNode(destination);
  newNode->next = graph[source];
  graph[source] = newNode;
}

//Define a function to print the graph representation
void printGraph(GraphNodePtr graph[], int vertices) {
  int i;
  for(i = 0; i < vertices; i++) {
    GraphNodePtr temp = graph[i];
    printf("\nAdjacency list of vertex %d:\n", i);
    while(temp) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("NULL");
  }
}

//Main function to test the program
int main() {
  //Read the number of vertices and edges from input
  int vertices, edges, i, source, destination;
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);
  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  //Create an array of graph nodes
  GraphNodePtr graph[vertices];
  for(i = 0; i < vertices; i++) {
    graph[i] = NULL;
  }

  //Add edges to the graph
  for(i = 0; i < edges; i++) {
    printf("Enter source and destination for edge %d: ", i+1);
    scanf("%d%d", &source, &destination);
    addEdge(graph, source, destination);
  }

  //Print the graph representation
  printGraph(graph, vertices);

  return 0;
}