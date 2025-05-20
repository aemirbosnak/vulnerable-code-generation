//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the node structure
typedef struct node {
  char *name;
  int weight;
  struct node *next;
} node;

// Define the graph structure
typedef struct graph {
  int num_nodes;
  struct node *nodes;
} graph;

// Create a new node
node *create_node(char *name, int weight) {
  node *new_node = malloc(sizeof(node));
  new_node->name = strdup(name);
  new_node->weight = weight;
  new_node->next = NULL;
  return new_node;
}

// Add a node to the graph
void add_node(graph *g, char *name, int weight) {
  node *new_node = create_node(name, weight);
  new_node->next = g->nodes;
  g->nodes = new_node;
  g->num_nodes++;
}

// Create a new graph
graph *create_graph() {
  graph *new_graph = malloc(sizeof(graph));
  new_graph->num_nodes = 0;
  new_graph->nodes = NULL;
  return new_graph;
}

// Print the graph
void print_graph(graph *g) {
  node *current_node = g->nodes;
  while (current_node != NULL) {
    printf("%s (%d)\n", current_node->name, current_node->weight);
    current_node = current_node->next;
  }
}

// Free the graph
void free_graph(graph *g) {
  node *current_node = g->nodes;
  while (current_node != NULL) {
    node *next_node = current_node->next;
    free(current_node->name);
    free(current_node);
    current_node = next_node;
  }
  free(g);
}

int main() {
  // Create a new graph
  graph *g = create_graph();

  // Add some nodes to the graph
  add_node(g, "A", 1);
  add_node(g, "B", 2);
  add_node(g, "C", 3);
  add_node(g, "D", 4);
  add_node(g, "E", 5);

  // Print the graph
  print_graph(g);

  // Free the graph
  free_graph(g);

  return 0;
}