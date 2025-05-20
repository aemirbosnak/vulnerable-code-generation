//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// The graph structure
typedef struct graph {
  int vertices;
  int edges;
  int **adj_matrix;
} graph;

// Create a new graph
graph *create_graph(int vertices, int edges) {
  graph *g = malloc(sizeof(graph));
  g->vertices = vertices;
  g->edges = edges;
  g->adj_matrix = malloc(sizeof(int *) * vertices);
  for (int i = 0; i < vertices; i++) {
    g->adj_matrix[i] = malloc(sizeof(int) * vertices);
    for (int j = 0; j < vertices; j++) {
      g->adj_matrix[i][j] = 0;
    }
  }
  return g;
}

// Add an edge to the graph
void add_edge(graph *g, int src, int dest) {
  g->adj_matrix[src][dest] = 1;
  g->adj_matrix[dest][src] = 1;
}

// Print the graph
void print_graph(graph *g) {
  for (int i = 0; i < g->vertices; i++) {
    for (int j = 0; j < g->vertices; j++) {
      printf("%d ", g->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

// Free the graph
void free_graph(graph *g) {
  for (int i = 0; i < g->vertices; i++) {
    free(g->adj_matrix[i]);
  }
  free(g->adj_matrix);
  free(g);
}

int main() {
  // Create a new graph
  graph *g = create_graph(5, 4);

  // Add edges to the graph
  add_edge(g, 0, 1);
  add_edge(g, 0, 2);
  add_edge(g, 1, 2);
  add_edge(g, 2, 3);

  // Print the graph
  printf("The graph is:\n");
  print_graph(g);

  // Free the graph
  free_graph(g);

  return 0;
}