//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* A graph is a data structure that consists of a set of nodes and a set of edges. */
typedef struct graph {
  int num_nodes;
  int num_edges;
  int** adjacency_matrix;
} graph;

/* A graph coloring is an assignment of colors to the nodes of a graph such that no two adjacent nodes have the same color. */
typedef struct graph_coloring {
  int num_nodes;
  int* colors;
} graph_coloring;

/* The following function creates a new graph with the given number of nodes and edges. */
graph* create_graph(int num_nodes, int num_edges) {
  graph* g = (graph*)malloc(sizeof(graph));
  g->num_nodes = num_nodes;
  g->num_edges = num_edges;
  g->adjacency_matrix = (int**)malloc(num_nodes * sizeof(int*));
  for (int i = 0; i < num_nodes; i++) {
    g->adjacency_matrix[i] = (int*)malloc(num_nodes * sizeof(int));
    for (int j = 0; j < num_nodes; j++) {
      g->adjacency_matrix[i][j] = 0;
    }
  }
  return g;
}

/* The following function adds an edge between the two given nodes in the given graph. */
void add_edge(graph* g, int node1, int node2) {
  g->adjacency_matrix[node1][node2] = 1;
  g->adjacency_matrix[node2][node1] = 1;
}

/* The following function frees the memory allocated for the given graph. */
void free_graph(graph* g) {
  for (int i = 0; i < g->num_nodes; i++) {
    free(g->adjacency_matrix[i]);
  }
  free(g->adjacency_matrix);
  free(g);
}

/* The following function creates a new graph coloring with the given number of nodes. */
graph_coloring* create_graph_coloring(int num_nodes) {
  graph_coloring* gc = (graph_coloring*)malloc(sizeof(graph_coloring));
  gc->num_nodes = num_nodes;
  gc->colors = (int*)malloc(num_nodes * sizeof(int));
  for (int i = 0; i < num_nodes; i++) {
    gc->colors[i] = -1;
  }
  return gc;
}

/* The following function frees the memory allocated for the given graph coloring. */
void free_graph_coloring(graph_coloring* gc) {
  free(gc->colors);
  free(gc);
}

/* The following function checks if the given graph coloring is valid. */
bool is_valid_graph_coloring(graph* g, graph_coloring* gc) {
  for (int i = 0; i < g->num_nodes; i++) {
    for (int j = 0; j < g->num_nodes; j++) {
      if (g->adjacency_matrix[i][j] == 1 && gc->colors[i] == gc->colors[j]) {
        return false;
      }
    }
  }
  return true;
}

/* The following function finds a valid graph coloring for the given graph using a greedy algorithm. */
graph_coloring* greedy_graph_coloring(graph* g) {
  graph_coloring* gc = create_graph_coloring(g->num_nodes);
  int num_colors = 0;
  int colors[g->num_nodes];
  for (int i = 0; i < g->num_nodes; i++) {
    colors[i] = -1;
  }
  for (int i = 0; i < g->num_nodes; i++) {
    if (colors[i] == -1) {
      colors[i] = num_colors;
      gc->colors[i] = num_colors;
      num_colors++;
      for (int j = 0; j < g->num_nodes; j++) {
        if (g->adjacency_matrix[i][j] == 1 && colors[j] == -1) {
          bool found_color = false;
          for (int k = 0; k < num_colors; k++) {
            if (colors[j] != k) {
              found_color = true;
              colors[j] = k;
              gc->colors[j] = k;
              break;
            }
          }
          if (!found_color) {
            colors[j] = num_colors;
            gc->colors[j] = num_colors;
            num_colors++;
          }
        }
      }
    }
  }
  return gc;
}

/* The following function prints the given graph coloring to the standard output. */
void print_graph_coloring(graph_coloring* gc) {
  for (int i = 0; i < gc->num_nodes; i++) {
    printf("Node %d has color %d\n", i, gc->colors[i]);
  }
}

int main() {
  graph* g = create_graph(4, 3);
  add_edge(g, 0, 1);
  add_edge(g, 1, 2);
  add_edge(g, 2, 3);
  graph_coloring* gc = greedy_graph_coloring(g);
  if (is_valid_graph_coloring(g, gc)) {
    printf("Valid graph coloring found:\n");
    print_graph_coloring(gc);
  } else {
    printf("No valid graph coloring found.\n");
  }
  free_graph(g);
  free_graph_coloring(gc);
  return 0;
}