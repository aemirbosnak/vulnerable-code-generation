//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 100

typedef struct Graph {
  int **adjList;
  int numVertices;
  int numEdges;
} Graph;

Graph* createGraph(int numVertices, int numEdges) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->adjList = (int**)malloc(numVertices * sizeof(int*));
  for (int i = 0; i < numVertices; i++) {
    graph->adjList[i] = (int*)malloc(numEdges * sizeof(int));
  }
  graph->numVertices = numVertices;
  graph->numEdges = numEdges;
  return graph;
}

void addEdge(Graph* graph, int src, int dest) {
  graph->adjList[src][dest] = 1;
}

void printGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    for (int j = 0; j < graph->numVertices; j++) {
      if (graph->adjList[i][j] == 1) {
        printf("%d ", j);
      }
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph(5, 5);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 3, 5);
  addEdge(graph, 4, 5);

  printGraph(graph);

  free(graph);
  return 0;
}