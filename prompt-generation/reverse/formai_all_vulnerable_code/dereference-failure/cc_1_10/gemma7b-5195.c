//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Graph {
  int **adjList;
  int numVertices;
  int numEdges;
} Graph;

Graph* createGraph() {
  Graph* graph = malloc(sizeof(Graph));
  graph->adjList = malloc(MAX_VERTICES * sizeof(int*));
  for (int i = 0; i < MAX_VERTICES; i++) {
    graph->adjList[i] = NULL;
  }
  graph->numVertices = 0;
  graph->numEdges = 0;
  return graph;
}

void addVertex(Graph* graph) {
  graph->numVertices++;
  graph->adjList[graph->numVertices - 1] = malloc(MAX_EDGES * sizeof(int));
}

void addEdge(Graph* graph, int src, int dest) {
  graph->numEdges++;
  graph->adjList[src][graph->numEdges - 1] = dest;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    for (int j = 0; j < graph->numEdges; j++) {
      if (graph->adjList[i][j] != NULL) {
        printf("%d ", graph->adjList[i][j]);
      }
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph();
  addVertex(graph);
  addVertex(graph);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  traverseGraph(graph);
  return 0;
}