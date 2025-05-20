//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the colors
enum color {RED, GREEN, BLUE, PURPLE, ORANGE, YELLOW};

// Define the graph
struct graph {
  int num_vertices;
  int num_edges;
  int **adj_matrix;
};

// Create a new graph
struct graph *create_graph(int num_vertices) {
  struct graph *graph = malloc(sizeof(struct graph));
  graph->num_vertices = num_vertices;
  graph->num_edges = 0;
  graph->adj_matrix = malloc(num_vertices * sizeof(int *));
  for (int i = 0; i < num_vertices; i++) {
    graph->adj_matrix[i] = malloc(num_vertices * sizeof(int));
    for (int j = 0; j < num_vertices; j++) {
      graph->adj_matrix[i][j] = 0;
    }
  }
  return graph;
}

// Add an edge to the graph
void add_edge(struct graph *graph, int vertex1, int vertex2) {
  graph->adj_matrix[vertex1][vertex2] = 1;
  graph->adj_matrix[vertex2][vertex1] = 1;
  graph->num_edges++;
}

// Print the graph
void print_graph(struct graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      printf("%d ", graph->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

// Color the graph
int color_graph(struct graph *graph) {
  // Initialize the colors of the vertices
  int *colors = malloc(graph->num_vertices * sizeof(int));
  for (int i = 0; i < graph->num_vertices; i++) {
    colors[i] = -1;
  }

  // Color the vertices one by one
  int color = 0;
  for (int i = 0; i < graph->num_vertices; i++) {
    if (colors[i] == -1) {
      // Try to color the vertex with the current color
      if (is_valid_coloring(graph, colors, i, color)) {
        colors[i] = color;
      } else {
        // If the current color is not valid, try the next color
        while (!is_valid_coloring(graph, colors, i, color)) {
          color++;
        }
        colors[i] = color;
      }
      color++;
    }
  }

  // Print the colors of the vertices
  for (int i = 0; i < graph->num_vertices; i++) {
    printf("Vertex %d is colored %d\n", i, colors[i]);
  }

  return color;  // Return the number of colors used
}

// Check if a coloring is valid
int is_valid_coloring(struct graph *graph, int *colors, int vertex, int color) {
  // Check if any of the adjacent vertices have the same color
  for (int i = 0; i < graph->num_vertices; i++) {
    if (graph->adj_matrix[vertex][i] == 1 && colors[i] == color) {
      return 0;
    }
  }
  return 1;
}

// Free the memory allocated for the graph
void free_graph(struct graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    free(graph->adj_matrix[i]);
  }
  free(graph->adj_matrix);
  free(graph);
}

int main() {
  // Create a graph
  struct graph *graph = create_graph(5);

  // Add edges to the graph
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);

  // Print the graph
  printf("The graph:\n");
  print_graph(graph);

  // Color the graph
  int num_colors = color_graph(graph);

  // Print the number of colors used
  printf("The graph was colored using %d colors\n", num_colors);

  // Free the memory allocated for the graph
  free_graph(graph);

  return 0;
}