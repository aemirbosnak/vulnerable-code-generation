//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Define the maximum number of nodes in the graph
#define MAX_NODES 1000

// Define the maximum number of edges in the graph
#define MAX_EDGES 10000

// Define the maximum length of a node label
#define MAX_LABEL_LENGTH 100

// Define the data structure for a node in the graph
typedef struct node {
  int id;
  char label[MAX_LABEL_LENGTH];
  struct edge *edges;
  int num_edges;
} node;

// Define the data structure for an edge in the graph
typedef struct edge {
  int id;
  node *source;
  node *destination;
  double weight;
} edge;

// Define the data structure for the graph
typedef struct graph {
  node *nodes;
  int num_nodes;
  edge *edges;
  int num_edges;
} graph;

// Create a new graph
graph *create_graph() {
  graph *g = (graph *)malloc(sizeof(graph));
  g->nodes = (node *)malloc(MAX_NODES * sizeof(node));
  g->num_nodes = 0;
  g->edges = (edge *)malloc(MAX_EDGES * sizeof(edge));
  g->num_edges = 0;
  return g;
}

// Add a new node to the graph
void add_node(graph *g, char *label) {
  node *n = &g->nodes[g->num_nodes++];
  n->id = g->num_nodes;
  strcpy(n->label, label);
  n->edges = NULL;
  n->num_edges = 0;
}

// Add a new edge to the graph
void add_edge(graph *g, node *source, node *destination, double weight) {
  edge *e = &g->edges[g->num_edges++];
  e->id = g->num_edges;
  e->source = source;
  e->destination = destination;
  e->weight = weight;
}

// Print the graph
void print_graph(graph *g) {
  for (int i = 0; i < g->num_nodes; i++) {
    node *n = &g->nodes[i];
    printf("Node %d: %s\n", n->id, n->label);
    for (int j = 0; j < n->num_edges; j++) {
      edge *e = &n->edges[j];
      printf("  Edge %d: %s -> %s (%.2f)\n", e->id, e->source->label, e->destination->label, e->weight);
    }
  }
}

// Free the graph
void free_graph(graph *g) {
  for (int i = 0; i < g->num_nodes; i++) {
    free(g->nodes[i].edges);
  }
  free(g->nodes);
  free(g->edges);
  free(g);
}

// Main function
int main() {
  // Create a new graph
  graph *g = create_graph();

  // Add some nodes to the graph
  add_node(g, "Node 1");
  add_node(g, "Node 2");
  add_node(g, "Node 3");

  // Add some edges to the graph
  add_edge(g, &g->nodes[0], &g->nodes[1], 1.0);
  add_edge(g, &g->nodes[0], &g->nodes[2], 2.0);
  add_edge(g, &g->nodes[1], &g->nodes[2], 3.0);

  // Print the graph
  print_graph(g);

  // Free the graph
  free_graph(g);

  return 0;
}