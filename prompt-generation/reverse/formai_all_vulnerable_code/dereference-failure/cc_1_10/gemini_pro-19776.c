//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_COLORS 10

typedef struct {
  int num_nodes;
  int num_edges;
  int adj_matrix[MAX_NODES][MAX_NODES];
} Graph;

typedef struct {
  int node;
  int color;
} NodeColoring;

// Allocate a new graph with the given number of nodes and edges.
Graph *new_graph(int num_nodes, int num_edges) {
  Graph *graph = malloc(sizeof(Graph));
  graph->num_nodes = num_nodes;
  graph->num_edges = num_edges;
  for (int i = 0; i < num_nodes; i++) {
    for (int j = 0; j < num_nodes; j++) {
      graph->adj_matrix[i][j] = 0;
    }
  }
  return graph;
}

// Free the given graph.
void free_graph(Graph *graph) {
  free(graph);
}

// Add an edge between the two given nodes in the given graph.
void add_edge(Graph *graph, int node1, int node2) {
  graph->adj_matrix[node1][node2] = 1;
  graph->adj_matrix[node2][node1] = 1;
}

// Print the given graph.
void print_graph(Graph *graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    for (int j = 0; j < graph->num_nodes; j++) {
      printf("%d ", graph->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

// Allocate a new node coloring with the given node and color.
NodeColoring *new_node_coloring(int node, int color) {
  NodeColoring *node_coloring = malloc(sizeof(NodeColoring));
  node_coloring->node = node;
  node_coloring->color = color;
  return node_coloring;
}

// Free the given node coloring.
void free_node_coloring(NodeColoring *node_coloring) {
  free(node_coloring);
}

// Color the given graph using the greedy algorithm.
NodeColoring **greedy_graph_coloring(Graph *graph) {
  NodeColoring **node_colorings = malloc(sizeof(NodeColoring *) * graph->num_nodes);
  int colors[MAX_COLORS];
  for (int i = 0; i < MAX_COLORS; i++) {
    colors[i] = 0;
  }
  for (int i = 0; i < graph->num_nodes; i++) {
    // Find the smallest color that is not used by any of the node's neighbors.
    int color = 0;
    while (colors[color] == 1) {
      color++;
    }
    // Color the node with the smallest available color.
    node_colorings[i] = new_node_coloring(i, color);
    // Mark the color as used.
    colors[color] = 1;
  }
  return node_colorings;
}

// Print the given node coloring.
void print_node_coloring(NodeColoring **node_colorings, int num_nodes) {
  for (int i = 0; i < num_nodes; i++) {
    printf("Node %d: Color %d\n", node_colorings[i]->node, node_colorings[i]->color);
  }
}

int main() {
  // Create a new graph.
  Graph *graph = new_graph(5, 4);

  // Add edges to the graph.
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);

  // Print the graph.
  printf("Graph:\n");
  print_graph(graph);

  // Color the graph using the greedy algorithm.
  NodeColoring **node_colorings = greedy_graph_coloring(graph);

  // Print the node coloring.
  printf("\nNode Coloring:\n");
  print_node_coloring(node_colorings, graph->num_nodes);

  // Free the graph and the node coloring.
  free_graph(graph);
  for (int i = 0; i < graph->num_nodes; i++) {
    free_node_coloring(node_colorings[i]);
  }
  free(node_colorings);

  return 0;
}