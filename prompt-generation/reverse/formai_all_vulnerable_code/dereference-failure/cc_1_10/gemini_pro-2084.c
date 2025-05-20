//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Graph coloring algorithm:
// Input: graph represented as adjacency matrix, number of colors
// Output: coloring of graph or error message if not possible
bool color_graph(int **adj_matrix, int num_vertices, int num_colors) {
  // Allocate memory for color array
  int *colors = malloc(num_vertices * sizeof(int));

  // Initialize color array to -1 (uncolored)
  for (int i = 0; i < num_vertices; i++) {
    colors[i] = -1;
  }

  // Color graph using greedy algorithm
  bool colored = true;
  for (int vertex = 0; vertex < num_vertices; vertex++) {
    if (colors[vertex] == -1) {
      // Get available colors for vertex
      bool available_colors[num_colors];
      for (int i = 0; i < num_colors; i++) {
        available_colors[i] = true;
      }
      for (int neighbor = 0; neighbor < num_vertices; neighbor++) {
        if (adj_matrix[vertex][neighbor] && colors[neighbor] != -1) {
          available_colors[colors[neighbor]] = false;
        }
      }

      // Assign first available color to vertex
      int color = -1;
      for (int i = 0; i < num_colors; i++) {
        if (available_colors[i]) {
          color = i;
          break;
        }
      }

      if (color == -1) {
        // No available colors for vertex
        colored = false;
        break;
      } else {
        colors[vertex] = color;
      }
    }
  }

  // Print coloring if graph was successfully colored
  if (colored) {
    printf("Graph colored using %d colors: ", num_colors);
    for (int i = 0; i < num_vertices; i++) {
      printf("%d ", colors[i]);
    }
    printf("\n");
  } else {
    printf("Graph cannot be colored using %d colors.\n", num_colors);
  }

  // Free allocated memory
  free(colors);

  return colored;
}

int main() {
  // 5-vertex graph
  int num_vertices = 5;
  int **adj_matrix = malloc(num_vertices * sizeof(int *));
  for (int i = 0; i < num_vertices; i++) {
    adj_matrix[i] = malloc(num_vertices * sizeof(int));
  }

  // Initialize adjacency matrix
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      adj_matrix[i][j] = 0;
    }
  }

  // Add edges to graph
  adj_matrix[0][1] = 1;
  adj_matrix[0][2] = 1;
  adj_matrix[1][2] = 1;
  adj_matrix[1][3] = 1;
  adj_matrix[2][3] = 1;
  adj_matrix[2][4] = 1;
  adj_matrix[3][4] = 1;

  // Try coloring graph with 3 colors
  int num_colors = 3;
  if (color_graph(adj_matrix, num_vertices, num_colors)) {
    printf("Graph colored successfully!\n");
  } else {
    printf("Graph cannot be colored with %d colors.\n", num_colors);
  }

  // Free allocated memory
  for (int i = 0; i < num_vertices; i++) {
    free(adj_matrix[i]);
  }
  free(adj_matrix);

  return 0;
}