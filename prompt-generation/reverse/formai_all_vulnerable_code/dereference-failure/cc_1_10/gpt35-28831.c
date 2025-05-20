//FormAI DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
 
typedef struct Graph {
  int nVertices;
  int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;
 
// function to create an empty graph
Graph* createGraph(int vertices) {
  Graph* newGraph = (Graph*)malloc(sizeof(Graph));
  newGraph->nVertices = vertices;
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      newGraph->adjMatrix[i][j] = 0;
    }
  }
  return newGraph;
}
 
// function to add an edge in the graph
void addEdge(Graph* graph, int src, int dest) {
  graph->adjMatrix[src][dest] = 1;
  graph->adjMatrix[dest][src] = 1;
}
 
// function to print the graph
void printGraph(Graph* graph) {
  for (int i = 0; i < graph->nVertices; i++) {
    printf("Vertex %d: ", i);
    for (int j = 0; j < graph->nVertices; j++) {
      printf("%d ", graph->adjMatrix[i][j]);
    }
    printf("\n");
  }
}
 
int main() {
  Graph* graph = createGraph(5);
 
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
 
  printGraph(graph);
 
  return 0;
}