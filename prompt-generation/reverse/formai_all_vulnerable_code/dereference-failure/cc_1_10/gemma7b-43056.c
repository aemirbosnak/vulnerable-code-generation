//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 10

typedef struct Graph {
  int **adj;
  int numVertices;
} Graph;

void graphColoring(Graph *graph) {
  int *colors = (int *)malloc(graph->numVertices * sizeof(int));
  for (int i = 0; i < graph->numVertices; i++) {
    colors[i] = -1;
  }

  int currentColor = 0;
  for (int i = 0; i < graph->numVertices; i++) {
    int forbiddenColors = 0;
    for (int j = 0; j < graph->adj[i][0]; j++) {
      if (colors[graph->adj[i][j]] != -1) {
        forbiddenColors++;
      }
    }

    colors[i] = currentColor - forbiddenColors;
  }

  for (int i = 0; i < graph->numVertices; i++) {
    printf("Vertex %d has color %d\n", i, colors[i]);
  }

  free(colors);
}

int main() {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = MAX_V;
  graph->adj = (int **)malloc(graph->numVertices * sizeof(int *));
  for (int i = 0; i < graph->numVertices; i++) {
    graph->adj[i] = (int *)malloc(sizeof(int) * 2);
  }

  graph->adj[0][0] = 1;
  graph->adj[0][1] = 2;
  graph->adj[1][0] = 0;
  graph->adj[1][1] = 3;
  graph->adj[2][0] = 1;
  graph->adj[2][1] = 3;
  graph->adj[3][0] = 2;
  graph->adj[3][1] = 4;

  graphColoring(graph);

  free(graph);

  return 0;
}