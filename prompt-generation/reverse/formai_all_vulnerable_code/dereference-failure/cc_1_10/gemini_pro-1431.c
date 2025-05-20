//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: portable
#include "stdio.h"
#include "stdlib.h"

// Circuit simulator

// Node structure
typedef struct node {
  int value;
  struct node *next;
} node;

// Circuit structure
typedef struct circuit {
  int num_nodes;
  node **nodes;
} circuit;

// Create a new circuit
circuit *create_circuit(int num_nodes) {
  circuit *c = (circuit *)malloc(sizeof(circuit));
  c->num_nodes = num_nodes;
  c->nodes = (node **)malloc(sizeof(node *) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    c->nodes[i] = NULL;
  }
  return c;
}

// Free a circuit
void free_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    node *n = c->nodes[i];
    while (n != NULL) {
      node *next = n->next;
      free(n);
      n = next;
    }
  }
  free(c->nodes);
  free(c);
}

// Add a node to a circuit
void add_node(circuit *c, int node_num, int value) {
  node *n = (node *)malloc(sizeof(node));
  n->value = value;
  n->next = c->nodes[node_num];
  c->nodes[node_num] = n;
}

// Connect two nodes in a circuit
void connect_nodes(circuit *c, int node_num1, int node_num2) {
  node *n1 = c->nodes[node_num1];
  while (n1->next != NULL) {
    n1 = n1->next;
  }
  n1->next = c->nodes[node_num2];
}

// Evaluate a circuit
void evaluate_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    node *n = c->nodes[i];
    int value = n->value;
    while (n->next != NULL) {
      n = n->next;
      value |= n->value;
    }
    n->value = value;
  }
}

// Print a circuit
void print_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    node *n = c->nodes[i];
    printf("Node %d: %d", i, n->value);
    while (n->next != NULL) {
      n = n->next;
      printf(" -> %d", n->value);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a circuit
  circuit *c = create_circuit(5);

  // Add nodes to the circuit
  add_node(c, 0, 1);
  add_node(c, 1, 2);
  add_node(c, 2, 3);
  add_node(c, 3, 4);
  add_node(c, 4, 5);

  // Connect the nodes in the circuit
  connect_nodes(c, 0, 1);
  connect_nodes(c, 1, 2);
  connect_nodes(c, 2, 3);
  connect_nodes(c, 3, 4);
  connect_nodes(c, 4, 0);

  // Evaluate the circuit
  evaluate_circuit(c);

  // Print the circuit
  print_circuit(c);

  // Free the circuit
  free_circuit(c);

  return 0;
}