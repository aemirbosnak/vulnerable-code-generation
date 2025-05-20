//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 100

typedef struct Graph {
  int **adjList;
  int numVertices;
  int numEdges;
} Graph;

Graph* graph_create(int numVertices) {
  Graph* graph = malloc(sizeof(Graph));
  graph->adjList = malloc(numVertices * sizeof(int*));
  for (int i = 0; i < numVertices; i++) {
    graph->adjList[i] = malloc(sizeof(int) * MAX_VERTS);
  }
  graph->numVertices = numVertices;
  graph->numEdges = 0;
  return graph;
}

void graph_add_edge(Graph* graph, int src, int dest) {
  graph->adjList[src][dest] = 1;
  graph->numEdges++;
}

void graph_print(Graph* graph) {
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
  Graph* graph = graph_create(5);
  graph_add_edge(graph, 0, 1);
  graph_add_edge(graph, 0, 2);
  graph_add_edge(graph, 1, 2);
  graph_add_edge(graph, 2, 3);
  graph_add_edge(graph, 3, 4);
  graph_add_edge(graph, 4, 0);

  graph_print(graph);

  free(graph->adjList);
  free(graph);

  return 0;
}