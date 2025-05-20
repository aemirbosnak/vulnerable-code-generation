//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// A node in a graph
struct node {
  int value;
  struct node *next;
};

// A graph is a collection of nodes
struct graph {
  struct node *head;
};

// Create a new node
struct node *create_node(int value) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->value = value;
  node->next = NULL;
  return node;
}

// Add a node to the graph
void add_node(struct graph *graph, struct node *node) {
  node->next = graph->head;
  graph->head = node;
}

// Print the graph
void print_graph(struct graph *graph) {
  struct node *node = graph->head;
  while (node != NULL) {
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n");
}

// Free the graph
void free_graph(struct graph *graph) {
  struct node *node = graph->head;
  while (node != NULL) {
    struct node *next = node->next;
    free(node);
    node = next;
  }
}

int main() {
  // Create a new graph
  struct graph *graph = (struct graph *)malloc(sizeof(struct graph));
  graph->head = NULL;

  // Add nodes to the graph
  add_node(graph, create_node(1));
  add_node(graph, create_node(2));
  add_node(graph, create_node(3));

  // Print the graph
  print_graph(graph);

  // Free the graph
  free_graph(graph);

  return 0;
}