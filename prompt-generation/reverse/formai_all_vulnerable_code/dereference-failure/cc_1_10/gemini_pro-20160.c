//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int num_nodes;
  int num_colors;
  int** adjacency_matrix;
} Graph;

typedef struct {
  int* colors;
} Coloring;

// Creates a new graph with the given number of nodes and colors.
Graph* create_graph(int num_nodes, int num_colors) {
  Graph* graph = malloc(sizeof(Graph));
  graph->num_nodes = num_nodes;
  graph->num_colors = num_colors;
  graph->adjacency_matrix = malloc(sizeof(int*) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    graph->adjacency_matrix[i] = malloc(sizeof(int) * num_nodes);
    for (int j = 0; j < num_nodes; j++) {
      graph->adjacency_matrix[i][j] = 0;
    }
  }
  return graph;
}

// Frees the memory allocated for the graph.
void free_graph(Graph* graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    free(graph->adjacency_matrix[i]);
  }
  free(graph->adjacency_matrix);
  free(graph);
}

// Adds an edge between the two given nodes.
void add_edge(Graph* graph, int node1, int node2) {
  graph->adjacency_matrix[node1][node2] = 1;
  graph->adjacency_matrix[node2][node1] = 1;
}

// Creates a new coloring with the given number of colors.
Coloring* create_coloring(int num_colors) {
  Coloring* coloring = malloc(sizeof(Coloring));
  coloring->colors = malloc(sizeof(int) * num_colors);
  for (int i = 0; i < num_colors; i++) {
    coloring->colors[i] = 0;
  }
  return coloring;
}

// Frees the memory allocated for the coloring.
void free_coloring(Coloring* coloring) {
  free(coloring->colors);
  free(coloring);
}

// Colors the given graph using the given coloring.
void color_graph(Graph* graph, Coloring* coloring) {
  int node_color = 0;
  int node_num = 1;
  while(node_num <= graph->num_nodes)
  {
    int node_ok = 1;
    for (int i = 0; i < graph->num_nodes; i++) {
      if (graph->adjacency_matrix[node_num - 1][i] == 1) {
        if (coloring->colors[i] == node_color) {
          node_ok = 0;
          break;
        }
      }
    }
    if (node_ok == 1)
    {
      coloring->colors[node_num - 1] = node_color;
      node_num++;
      node_color++;
      if (node_color >= graph->num_colors) node_color = 0;
    }
    else
    {
      node_color++;
      if (node_color >= graph->num_colors) node_color = 0;
    }
  }
}

// Prints the coloring of the graph.
void print_coloring(Graph* graph, Coloring* coloring) {
  for (int i = 0; i < graph->num_nodes; i++) {
    printf("Node %d: color %d\n", i + 1, coloring->colors[i] + 1);
  }
}

// Main function.
int main() {
  // Create a graph with 5 nodes and 3 colors.
  Graph* graph = create_graph(5, 3);

  // Add edges to the graph.
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);

  // Create a coloring for the graph.
  Coloring* coloring = create_coloring(3);

  // Color the graph.
  color_graph(graph, coloring);

  // Print the coloring of the graph.
  print_coloring(graph, coloring);

  // Free the memory allocated for the graph and coloring.
  free_graph(graph);
  free_coloring(coloring);

  return 0;
}