//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 100

typedef struct Graph {
  int **adj;
  int numVertices;
} Graph;

Graph* graph_create(int numVertices) {
  Graph* g = malloc(sizeof(Graph));
  g->numVertices = numVertices;
  g->adj = malloc(numVertices * sizeof(int*));
  for (int i = 0; i < numVertices; i++) {
    g->adj[i] = malloc(numVertices * sizeof(int));
  }
  return g;
}

void graph_add_edge(Graph* g, int u, int v) {
  g->adj[u][v] = 1;
}

int graph_color(Graph* g) {
  int* colors = malloc(g->numVertices * sizeof(int));
  for (int i = 0; i < g->numVertices; i++) {
    colors[i] = -1;
  }

  int chromaticNumber = 0;
  for (int i = 0; i < g->numVertices; i++) {
    int availableColors = 0;
    for (int j = 0; j < g->numVertices; j++) {
      if (g->adj[i][j] && colors[j] != -1) {
        availableColors--;
      }
    }

    colors[i] = availableColors;
  }

  for (int i = 0; i < g->numVertices; i++) {
    chromaticNumber = fmax(chromaticNumber, colors[i]);
  }

  free(colors);
  return chromaticNumber;
}

int main() {
  Graph* g = graph_create(5);
  graph_add_edge(g, 0, 1);
  graph_add_edge(g, 0, 2);
  graph_add_edge(g, 1, 2);
  graph_add_edge(g, 2, 3);
  graph_add_edge(g, 3, 4);

  int chromaticNumber = graph_color(g);

  printf("Chromatic number of the graph: %d\n", chromaticNumber);

  return 0;
}