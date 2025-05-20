//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph representation using adjacency matrix
struct Graph {
  int num_vertices;
  int num_edges;
  int** adj_matrix;
};

// Function to create a new graph
struct Graph* create_graph(int num_vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->num_vertices = num_vertices;
  graph->num_edges = 0;
  graph->adj_matrix = malloc(num_vertices * sizeof(int*));
  for (int i = 0; i < num_vertices; i++) {
    graph->adj_matrix[i] = malloc(num_vertices * sizeof(int));
    for (int j = 0; j < num_vertices; j++) {
      graph->adj_matrix[i][j] = 0;
    }
  }
  return graph;
}

// Function to add an edge to the graph
void add_edge(struct Graph* graph, int vertex1, int vertex2) {
  if (vertex1 < 0 || vertex1 >= graph->num_vertices || vertex2 < 0 || vertex2 >= graph->num_vertices) {
    printf("Invalid vertex\n");
    return;
  }
  graph->adj_matrix[vertex1][vertex2] = 1;
  graph->adj_matrix[vertex2][vertex1] = 1;
  graph->num_edges++;
}

// Function to print the graph
void print_graph(struct Graph* graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      printf("%d ", graph->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to deallocates memory allocated for the graph
void destroy_graph(struct Graph* graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    free(graph->adj_matrix[i]);
  }
  free(graph->adj_matrix);
  free(graph);
}

int main() {
  // Create a graph with 5 vertices
  struct Graph* graph = create_graph(5);

  // Add edges to the graph
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 3, 4);

  // Print the graph
  printf("Graph:\n");
  print_graph(graph);

  // Destroy the graph
  destroy_graph(graph);

  return 0;
}