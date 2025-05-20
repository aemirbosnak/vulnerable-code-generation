//FormAI DATASET v1.0 Category: Graph representation ; Style: mind-bending
#include <stdio.h>

// Define a struct to represent a graph node
struct Node {
  int value;
  struct Node** neighbors;
  int num_neighbors;
};

// Define a function to create a new graph node
struct Node* new_node(int value, int num_neighbors) {
  struct Node* node = malloc(sizeof(struct Node));
  node->value = value;
  node->num_neighbors = num_neighbors;
  node->neighbors = malloc(num_neighbors * sizeof(struct Node*));
  return node;
}

// Define a function to add an edge between two nodes
void add_edge(struct Node* node_a, struct Node* node_b) {
  node_a->neighbors[node_a->num_neighbors++] = node_b;
  node_b->neighbors[node_b->num_neighbors++] = node_a;
}

// Define a function to print the graph
void print_graph(struct Node* node) {
  printf("%d", node->value);
  for (int i = 0; i < node->num_neighbors; i++) {
    printf(" -> ");
    print_graph(node->neighbors[i]);
  }
}

int main() {
  // Create some test nodes
  struct Node* node1 = new_node(1, 3);
  struct Node* node2 = new_node(2, 2);
  struct Node* node3 = new_node(3, 2);
  struct Node* node4 = new_node(4, 1);

  // Add edges between the nodes
  add_edge(node1, node2);
  add_edge(node1, node3);
  add_edge(node1, node4);
  add_edge(node2, node3);
  add_edge(node3, node4);

  // Print the graph
  print_graph(node1);

  // Free memory allocated for nodes
  free(node1);
  free(node2);
  free(node3);
  free(node4);

  return 0;
}