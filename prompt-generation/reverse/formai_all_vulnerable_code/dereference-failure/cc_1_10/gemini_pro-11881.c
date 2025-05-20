//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Graph data structure
typedef struct graph {
  int num_vertices;
  int num_edges;
  int **adj_matrix;
} graph_t;

// Function to create a new graph
graph_t *create_graph(int num_vertices) {
  graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
  graph->num_vertices = num_vertices;
  graph->num_edges = 0;
  graph->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
  for (int i = 0; i < num_vertices; i++) {
    graph->adj_matrix[i] = (int *)calloc(num_vertices, sizeof(int));
  }
  return graph;
}

// Function to add an edge to a graph
void add_edge(graph_t *graph, int vertex1, int vertex2) {
  graph->adj_matrix[vertex1][vertex2] = 1;
  graph->adj_matrix[vertex2][vertex1] = 1;
  graph->num_edges++;
}

// Function to print the adjacency matrix of a graph
void print_adj_matrix(graph_t *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      printf("%d ", graph->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a graph is k-colorable
int is_k_colorable(graph_t *graph, int k) {
  // Initialize the colors of the vertices to -1
  int *colors = (int *)calloc(graph->num_vertices, sizeof(int));
  for (int i = 0; i < graph->num_vertices; i++) {
    colors[i] = -1;
  }

  // Try all possible colorings
  int num_colorings = 0;
  for (int i = 0; i < graph->num_vertices; i++) {
    if (colors[i] == -1) {
      num_colorings += is_k_colorable_helper(graph, i, k, colors);
    }
  }

  // Free the colors array
  free(colors);

  // Return the number of colorings
  return num_colorings;
}

// Helper function for is_k_colorable
int is_k_colorable_helper(graph_t *graph, int vertex, int k, int *colors) {
  // Try all possible colors for the vertex
  int num_colorings = 0;
  for (int color = 0; color < k; color++) {
    // Check if the color is valid
    int is_valid = 1;
    for (int i = 0; i < graph->num_vertices; i++) {
      if (graph->adj_matrix[vertex][i] == 1 && colors[i] == color) {
        is_valid = 0;
        break;
      }
    }

    // If the color is valid, assign it to the vertex and recurse
    if (is_valid) {
      colors[vertex] = color;
      num_colorings += is_k_colorable_helper(graph, vertex + 1, k, colors);
      colors[vertex] = -1;
    }
  }

  // Return the number of colorings
  return num_colorings;
}

// Function to test the is_k_colorable function
int main() {
  // Create a graph
  graph_t *graph = create_graph(4);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);

  // Print the adjacency matrix of the graph
  printf("Adjacency matrix:\n");
  print_adj_matrix(graph);

  // Check if the graph is 3-colorable
  int is_3_colorable = is_k_colorable(graph, 3);
  printf("Is the graph 3-colorable? %s\n", is_3_colorable ? "Yes" : "No");

  // Check if the graph is 4-colorable
  int is_4_colorable = is_k_colorable(graph, 4);
  printf("Is the graph 4-colorable? %s\n", is_4_colorable ? "Yes" : "No");

  // Free the graph
  for (int i = 0; i < graph->num_vertices; i++) {
    free(graph->adj_matrix[i]);
  }
  free(graph->adj_matrix);
  free(graph);

  return 0;
}