//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: unmistakable
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define UNCOLORED -1

typedef struct graph {
  int n;
  int** adj;
} graph;

graph* new_graph(int n) {
  graph* g = malloc(sizeof(graph));
  g->n = n;
  g->adj = malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    g->adj[i] = malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
      g->adj[i][j] = 0;
    }
  }
  return g;
}

void free_graph(graph* g) {
  for (int i = 0; i < g->n; i++) {
    free(g->adj[i]);
  }
  free(g->adj);
  free(g);
}

bool is_safe(graph* g, int v, int color) {
  for (int i = 0; i < g->n; i++) {
    if (g->adj[v][i] && color == g->adj[i][v]) {
      return false;
    }
  }
  return true;
}

bool graph_color(graph* g, int v, int* colors) {
  if (v == g->n) {
    return true;
  }
  for (int c = 1; c <= g->n; c++) {
    if (is_safe(g, v, c)) {
      colors[v] = c;
      if (graph_color(g, v + 1, colors)) {
        return true;
      }
      colors[v] = UNCOLORED;
    }
  }
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  graph* g = new_graph(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int edge;
      scanf("%d", &edge);
      g->adj[i][j] = edge;
    }
  }
  int* colors = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    colors[i] = UNCOLORED;
  }
  if (graph_color(g, 0, colors)) {
    for (int i = 0; i < n; i++) {
      printf("%d ", colors[i]);
    }
    printf("\n");
  } else {
    printf("No solution\n");
  }
  free_graph(g);
  free(colors);
  return 0;
}