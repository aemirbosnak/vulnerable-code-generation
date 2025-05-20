//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define MAX_CONNECTIONS 10

typedef struct Graph {
  int **adjList;
  int numVertices;
} Graph;

Graph *createGraph(int numVertices) {
  Graph *graph = malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjList = malloc(numVertices * sizeof(int *));
  for (int i = 0; i < numVertices; i++) {
    graph->adjList[i] = malloc(sizeof(int *) * numVertices);
  }
  return graph;
}

void addEdge(Graph *graph, int srcVertex, int destVertex) {
  graph->adjList[srcVertex][destVertex] = 1;
}

void printGraph(Graph *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    for (int j = 0; j < graph->numVertices; j++) {
      if (graph->adjList[i][j] == 1) {
        printf("%d -> %d\n", i, j);
      }
    }
  }
}

int main() {
  int numVertices = 5;
  Graph *graph = createGraph(numVertices);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 0);

  printGraph(graph);

  return 0;
}