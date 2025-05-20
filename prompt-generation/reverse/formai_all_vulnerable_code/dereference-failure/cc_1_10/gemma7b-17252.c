//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10

typedef struct Graph {
  int **adj;
  int numVertices;
} Graph;

void graphColor(Graph *g) {
  int **color = malloc(g->numVertices * sizeof(int *));
  for (int i = 0; i < g->numVertices; i++) {
    color[i] = malloc(g->numVertices * sizeof(int));
  }

  for (int i = 0; i < g->numVertices; i++) {
    for (int j = 0; j < g->numVertices; j++) {
      if (g->adj[i][j] && color[i][j] == 0) {
        color[i][j] = 1 + color[j][i];
      }
    }
  }

  for (int i = 0; i < g->numVertices; i++) {
    free(color[i]);
  }
  free(color);
}

int main() {
  Graph *g = malloc(sizeof(Graph));
  g->numVertices = MAX_VERTS;
  g->adj = malloc(g->numVertices * sizeof(int *));
  for (int i = 0; i < g->numVertices; i++) {
    g->adj[i] = malloc(g->numVertices * sizeof(int));
  }

  g->adj[0][1] = 1;
  g->adj[1][2] = 1;
  g->adj[2][3] = 1;
  g->adj[3][4] = 1;
  g->adj[4][0] = 1;

  graphColor(g);

  for (int i = 0; i < g->numVertices; i++) {
    for (int j = 0; j < g->numVertices; j++) {
      printf("%d ", g->adj[i][j] + 1);
    }
    printf("\n");
  }

  free(g->adj);
  free(g);

  return 0;
}