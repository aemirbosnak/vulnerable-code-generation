//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Graph data structure
typedef struct graph {
  int V;  // Number of vertices
  int E;  // Number of edges
  int **adj;  // Adjacency matrix
} graph_t;

// Create a new graph with V vertices
graph_t *new_graph(int V) {
  graph_t *g = malloc(sizeof(graph_t));
  g->V = V;
  g->E = 0;
  g->adj = malloc(V * sizeof(int *));
  for (int i = 0; i < V; i++) {
    g->adj[i] = malloc(V * sizeof(int));
    for (int j = 0; j < V; j++) {
      g->adj[i][j] = 0;
    }
  }
  return g;
}

// Add an edge to the graph
void add_edge(graph_t *g, int u, int v) {
  if (u < 0 || u >= g->V || v < 0 || v >= g->V) {
    printf("Error: Invalid vertex\n");
    return;
  }
  g->adj[u][v] = 1;
  g->E++;
}

// Remove an edge from the graph
void remove_edge(graph_t *g, int u, int v) {
  if (u < 0 || u >= g->V || v < 0 || v >= g->V) {
    printf("Error: Invalid vertex\n");
    return;
  }
  g->adj[u][v] = 0;
  g->E--;
}

// Check if two vertices are adjacent
bool are_adjacent(graph_t *g, int u, int v) {
  if (u < 0 || u >= g->V || v < 0 || v >= g->V) {
    printf("Error: Invalid vertex\n");
    return false;
  }
  return g->adj[u][v] == 1;
}

// Print the graph
void print_graph(graph_t *g) {
  for (int i = 0; i < g->V; i++) {
    for (int j = 0; j < g->V; j++) {
      printf("%d ", g->adj[i][j]);
    }
    printf("\n");
  }
}

// Free the graph
void free_graph(graph_t *g) {
  for (int i = 0; i < g->V; i++) {
    free(g->adj[i]);
  }
  free(g->adj);
  free(g);
}

// Graph coloring algorithm
int *graph_coloring(graph_t *g) {
  // Initialize the colors array to all zeros
  int *colors = malloc(g->V * sizeof(int));
  for (int i = 0; i < g->V; i++) {
    colors[i] = 0;
  }

  // Assign a color to each vertex
  for (int i = 0; i < g->V; i++) {
    // If the vertex is not colored yet, assign it a color
    if (colors[i] == 0) {
      // Find the smallest available color
      int color = 1;
      while (true) {
        bool found = false;
        // Check if the color is available for the vertex
        for (int j = 0; j < g->V; j++) {
          if (are_adjacent(g, i, j) && colors[j] == color) {
            found = true;
            break;
          }
        }
        // If the color is not available, increment it
        if (found) {
          color++;
        } else {
          // If the color is available, assign it to the vertex
          colors[i] = color;
          break;
        }
      }
    }
  }

  return colors;
}

// Print the graph coloring
void print_coloring(int *colors, int V) {
  for (int i = 0; i < V; i++) {
    printf("Vertex %d: Color %d\n", i, colors[i]);
  }
}

// Main function
int main() {
  // Create a new graph
  graph_t *g = new_graph(5);

  // Add edges to the graph
  add_edge(g, 0, 1);
  add_edge(g, 0, 2);
  add_edge(g, 1, 2);
  add_edge(g, 1, 3);
  add_edge(g, 2, 3);
  add_edge(g, 3, 4);

  // Print the graph
  printf("Graph:\n");
  print_graph(g);

  // Color the graph
  int *colors = graph_coloring(g);

  // Print the graph coloring
  printf("\nGraph coloring:\n");
  print_coloring(colors, g->V);

  // Free the graph and the colors array
  free_graph(g);
  free(colors);

  return 0;
}