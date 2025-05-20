//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of nodes and edges in the circuit
#define MAX_NODES 100
#define MAX_EDGES 100

// Define the data structure for a node
typedef struct node {
  int id;
  int value;
  int in_degree;
  int out_degree;
  struct node *in_edges[MAX_EDGES];
  struct node *out_edges[MAX_EDGES];
} node;

// Define the data structure for an edge
typedef struct edge {
  int id;
  node *from;
  node *to;
} edge;

// Define the data structure for the circuit
typedef struct circuit {
  int num_nodes;
  int num_edges;
  node *nodes[MAX_NODES];
  edge *edges[MAX_EDGES];
} circuit;

// Create a new circuit
circuit *new_circuit() {
  circuit *c = malloc(sizeof(circuit));
  c->num_nodes = 0;
  c->num_edges = 0;
  return c;
}

// Add a node to the circuit
void add_node(circuit *c, node *n) {
  c->nodes[c->num_nodes++] = n;
}

// Add an edge to the circuit
void add_edge(circuit *c, edge *e) {
  c->edges[c->num_edges++] = e;
}

// Print the circuit
void print_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    printf("Node %d:\n", c->nodes[i]->id);
    printf("  Value: %d\n", c->nodes[i]->value);
    printf("  In-degree: %d\n", c->nodes[i]->in_degree);
    printf("  Out-degree: %d\n", c->nodes[i]->out_degree);
    for (int j = 0; j < c->nodes[i]->in_degree; j++) {
      printf("  In-edge: %d\n", c->nodes[i]->in_edges[j]->id);
    }
    for (int j = 0; j < c->nodes[i]->out_degree; j++) {
      printf("  Out-edge: %d\n", c->nodes[i]->out_edges[j]->id);
    }
  }
}

// Simulate the circuit
void simulate_circuit(circuit *c) {
  // Initialize the node values
  for (int i = 0; i < c->num_nodes; i++) {
    c->nodes[i]->value = 0;
  }

  // Iterate over the edges and update the node values
  for (int i = 0; i < c->num_edges; i++) {
    edge *e = c->edges[i];
    e->to->value = e->from->value;
  }

  // Print the simulated circuit
  print_circuit(c);
}

// Free the circuit
void free_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    free(c->nodes[i]);
  }
  for (int i = 0; i < c->num_edges; i++) {
    free(c->edges[i]);
  }
  free(c);
}

// Main function
int main() {
  // Create a new circuit
  circuit *c = new_circuit();

  // Add nodes to the circuit
  for (int i = 0; i < 10; i++) {
    node *n = malloc(sizeof(node));
    n->id = i;
    n->value = 0;
    n->in_degree = 0;
    n->out_degree = 0;
    add_node(c, n);
  }

  // Add edges to the circuit
  for (int i = 0; i < 10; i++) {
    edge *e = malloc(sizeof(edge));
    e->id = i;
    e->from = c->nodes[i];
    e->to = c->nodes[(i + 1) % 10];
    add_edge(c, e);
  }

  // Simulate the circuit
  simulate_circuit(c);

  // Free the circuit
  free_circuit(c);

  return 0;
}