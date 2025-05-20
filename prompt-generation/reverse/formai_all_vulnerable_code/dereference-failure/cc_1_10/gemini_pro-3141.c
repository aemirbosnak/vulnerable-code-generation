//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of nodes and edges in the circuit
#define MAX_NODES 100
#define MAX_EDGES 1000

// Define the data structures for the nodes and edges
typedef struct node {
  int id;
  char *name;
  int num_inputs;
  int num_outputs;
  int *inputs;
  int *outputs;
} node;

typedef struct edge {
  int id;
  int source;
  int destination;
} edge;

// Define the data structure for the circuit
typedef struct circuit {
  int num_nodes;
  int num_edges;
  node *nodes;
  edge *edges;
} circuit;

// Create a new circuit
circuit *new_circuit() {
  circuit *c = malloc(sizeof(circuit));
  c->num_nodes = 0;
  c->num_edges = 0;
  c->nodes = malloc(sizeof(node) * MAX_NODES);
  c->edges = malloc(sizeof(edge) * MAX_EDGES);
  return c;
}

// Add a node to the circuit
void add_node(circuit *c, char *name, int num_inputs, int num_outputs) {
  node *n = &c->nodes[c->num_nodes];
  n->id = c->num_nodes;
  n->name = strdup(name);
  n->num_inputs = num_inputs;
  n->num_outputs = num_outputs;
  n->inputs = malloc(sizeof(int) * num_inputs);
  n->outputs = malloc(sizeof(int) * num_outputs);
  c->num_nodes++;
}

// Add an edge to the circuit
void add_edge(circuit *c, int source, int destination) {
  edge *e = &c->edges[c->num_edges];
  e->id = c->num_edges;
  e->source = source;
  e->destination = destination;
  c->num_edges++;
}

// Print the circuit
void print_circuit(circuit *c) {
  printf("Circuit:\n");
  for (int i = 0; i < c->num_nodes; i++) {
    node *n = &c->nodes[i];
    printf("Node %d: %s (%d inputs, %d outputs)\n", n->id, n->name, n->num_inputs, n->num_outputs);
    for (int j = 0; j < n->num_inputs; j++) {
      printf("  Input %d: %d\n", j, n->inputs[j]);
    }
    for (int j = 0; j < n->num_outputs; j++) {
      printf("  Output %d: %d\n", j, n->outputs[j]);
    }
  }
  for (int i = 0; i < c->num_edges; i++) {
    edge *e = &c->edges[i];
    printf("Edge %d: %d -> %d\n", e->id, e->source, e->destination);
  }
}

// Free the circuit
void free_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    node *n = &c->nodes[i];
    free(n->name);
    free(n->inputs);
    free(n->outputs);
  }
  free(c->nodes);
  free(c->edges);
  free(c);
}

// The main function
int main() {
  // Create a new circuit
  circuit *c = new_circuit();

  // Add some nodes to the circuit
  add_node(c, "Input A", 0, 1);
  add_node(c, "Input B", 0, 1);
  add_node(c, "AND Gate", 2, 1);
  add_node(c, "Output", 1, 0);

  // Add some edges to the circuit
  add_edge(c, 0, 2);
  add_edge(c, 1, 2);
  add_edge(c, 2, 3);

  // Print the circuit
  print_circuit(c);

  // Free the circuit
  free_circuit(c);

  return 0;
}