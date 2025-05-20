//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

/* Node structure */
typedef struct node {
  int value;
  struct node *next;
} node;

/* Circuit structure */
typedef struct circuit {
  int num_nodes;
  node *nodes;
} circuit;

/* Create a new circuit */
circuit *new_circuit(int num_nodes) {
  circuit *c = malloc(sizeof(circuit));
  c->num_nodes = num_nodes;
  c->nodes = malloc(sizeof(node) * num_nodes);
  return c;
}

/* Free a circuit */
void free_circuit(circuit *c) {
  free(c->nodes);
  free(c);
}

/* Add a node to a circuit */
void add_node(circuit *c, int value) {
  c->nodes[c->num_nodes].value = value;
  c->nodes[c->num_nodes].next = NULL;
  c->num_nodes++;
}

/* Connect two nodes in a circuit */
void connect_nodes(circuit *c, int node1, int node2) {
  c->nodes[node1].next = &c->nodes[node2];
}

/* Simulate a circuit */
int simulate_circuit(circuit *c) {
  int i;
  int output = 0;
  for (i = 0; i < c->num_nodes; i++) {
    if (c->nodes[i].value == 1) {
      output = 1;
      break;
    }
  }
  return output;
}

/* Print a circuit */
void print_circuit(circuit *c) {
  int i;
  for (i = 0; i < c->num_nodes; i++) {
    printf("Node %d: %d\n", i, c->nodes[i].value);
    if (c->nodes[i].next != NULL) {
      printf("  Connected to: %d\n", c->nodes[i].next->value);
    }
  }
}

/* Main function */
int main() {
  circuit *c = new_circuit(5);
  add_node(c, 0);
  add_node(c, 0);
  add_node(c, 0);
  add_node(c, 0);
  add_node(c, 0);
  connect_nodes(c, 0, 1);
  connect_nodes(c, 1, 2);
  connect_nodes(c, 2, 3);
  connect_nodes(c, 3, 4);
  print_circuit(c);
  printf("Output: %d\n", simulate_circuit(c));
  free_circuit(c);
  return 0;
}