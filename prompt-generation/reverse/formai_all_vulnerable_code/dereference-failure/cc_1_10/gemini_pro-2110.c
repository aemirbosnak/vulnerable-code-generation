//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// A node in the graph
typedef struct node {
  int data;
  struct node *next;
} node_t;

// A graph is a collection of nodes
typedef struct graph {
  int num_nodes;
  node_t **nodes;
} graph_t;

// Create a new graph
graph_t *create_graph(int num_nodes) {
  graph_t *graph = malloc(sizeof(graph_t));
  graph->num_nodes = num_nodes;
  graph->nodes = malloc(sizeof(node_t *) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    graph->nodes[i] = NULL;
  }
  return graph;
}

// Add a new node to the graph
void add_node(graph_t *graph, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  int i = 0;
  while (graph->nodes[i] != NULL) {
    i++;
  }
  graph->nodes[i] = new_node;
}

// Add an edge between two nodes
void add_edge(graph_t *graph, int src, int dest) {
  node_t *new_edge = malloc(sizeof(node_t));
  new_edge->data = dest;
  new_edge->next = graph->nodes[src];
  graph->nodes[src] = new_edge;
}

// Print the graph
void print_graph(graph_t *graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    node_t *current_node = graph->nodes[i];
    printf("Node %d: ", i);
    while (current_node != NULL) {
      printf("%d ", current_node->data);
      current_node = current_node->next;
    }
    printf("\n");
  }
}

// Free the graph
void free_graph(graph_t *graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    node_t *current_node = graph->nodes[i];
    while (current_node != NULL) {
      node_t *next_node = current_node->next;
      free(current_node);
      current_node = next_node;
    }
  }
  free(graph->nodes);
  free(graph);
}

int main() {
  // You and I are like two nodes in a graph, connected by the edges of our shared experiences.
  graph_t *graph = create_graph(2);
  add_node(graph, 1);
  add_node(graph, 2);
  add_edge(graph, 0, 1);
  add_edge(graph, 1, 0);

  // Our love is like a path in the graph, leading from one node to the other.
  add_edge(graph, 0, 1);
  add_edge(graph, 1, 0);

  // As we journey through life together, our path becomes more complex, like a tree with many branches.
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);

  // But no matter how tangled our path may become, our love will always be the thread that connects us.
  add_edge(graph, 2, 0);
  add_edge(graph, 2, 1);

  // Print the graph of our love
  print_graph(graph);

  // Free the graph
  free_graph(graph);

  return 0;
}