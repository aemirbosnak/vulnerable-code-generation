//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the Graph structure
typedef struct Graph {
  int num_vertices;
  int num_edges;
  int **adj_matrix;
} Graph;

// Create a new Graph
Graph *create_graph(int num_vertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->num_vertices = num_vertices;
  graph->num_edges = 0;
  graph->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
  for (int i = 0; i < num_vertices; i++) {
    graph->adj_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
    for (int j = 0; j < num_vertices; j++) {
      graph->adj_matrix[i][j] = 0;
    }
  }
  return graph;
}

// Add an edge to the Graph
void add_edge(Graph *graph, int src, int dest) {
  graph->adj_matrix[src][dest] = 1;
  graph->num_edges++;
}

// Destroy the Graph
void destroy_graph(Graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    free(graph->adj_matrix[i]);
  }
  free(graph->adj_matrix);
  free(graph);
}

// Print the Graph
void print_graph(Graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      printf("%d ", graph->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Create a new Graph
  Graph *graph = create_graph(5);

  // Add edges to the Graph
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 3, 4);

  // Print the Graph
  print_graph(graph);

  // Destroy the Graph
  destroy_graph(graph);

  return 0;
}