//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of nodes in the circuit
#define MAX_NODES 100

// Define the types of nodes in the circuit
typedef enum {
  NODE_TYPE_INPUT,
  NODE_TYPE_OUTPUT,
  NODE_TYPE_AND,
  NODE_TYPE_OR,
  NODE_TYPE_NOT,
} node_type;

// Define the structure of a node in the circuit
typedef struct {
  node_type type;
  int num_inputs;
  int *inputs;
  int output;
} node;

// Define the structure of the circuit
typedef struct {
  int num_nodes;
  node *nodes;
} circuit;

// Create a new circuit
circuit *create_circuit() {
  circuit *c = malloc(sizeof(circuit));
  c->num_nodes = 0;
  c->nodes = NULL;
  return c;
}

// Destroy a circuit
void destroy_circuit(circuit *c) {
  free(c->nodes);
  free(c);
}

// Add a node to a circuit
void add_node(circuit *c, node_type type, int num_inputs, int *inputs, int output) {
  c->nodes = realloc(c->nodes, (c->num_nodes + 1) * sizeof(node));
  node *n = &c->nodes[c->num_nodes++];
  n->type = type;
  n->num_inputs = num_inputs;
  n->inputs = inputs;
  n->output = output;
}

// Evaluate a circuit
int evaluate_circuit(circuit *c) {
  int *values = malloc(c->num_nodes * sizeof(int));
  for (int i = 0; i < c->num_nodes; i++) {
    node *n = &c->nodes[i];
    switch (n->type) {
      case NODE_TYPE_INPUT:
        values[i] = n->output;
        break;
      case NODE_TYPE_OUTPUT:
        values[i] = values[n->inputs[0]];
        break;
      case NODE_TYPE_AND:
        values[i] = values[n->inputs[0]] && values[n->inputs[1]];
        break;
      case NODE_TYPE_OR:
        values[i] = values[n->inputs[0]] || values[n->inputs[1]];
        break;
      case NODE_TYPE_NOT:
        values[i] = !values[n->inputs[0]];
        break;
    }
  }
  int output = values[c->num_nodes - 1];
  free(values);
  return output;
}

// Print a circuit
void print_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    node *n = &c->nodes[i];
    printf("Node %d: ", i);
    switch (n->type) {
      case NODE_TYPE_INPUT:
        printf("INPUT");
        break;
      case NODE_TYPE_OUTPUT:
        printf("OUTPUT");
        break;
      case NODE_TYPE_AND:
        printf("AND");
        break;
      case NODE_TYPE_OR:
        printf("OR");
        break;
      case NODE_TYPE_NOT:
        printf("NOT");
        break;
    }
    printf(" (%d inputs: ", n->num_inputs);
    for (int j = 0; j < n->num_inputs; j++) {
      printf("%d ", n->inputs[j]);
    }
    printf(")\n");
  }
}

// Main function
int main() {
  // Create a new circuit
  circuit *c = create_circuit();

  // Add nodes to the circuit
  add_node(c, NODE_TYPE_INPUT, 0, NULL, 1);
  add_node(c, NODE_TYPE_INPUT, 0, NULL, 0);
  add_node(c, NODE_TYPE_AND, 2, (int[]){0, 1}, 2);
  add_node(c, NODE_TYPE_OUTPUT, 1, (int[]){2}, 3);

  // Print the circuit
  print_circuit(c);

  // Evaluate the circuit
  int output = evaluate_circuit(c);

  // Print the output
  printf("Output: %d\n", output);

  // Destroy the circuit
  destroy_circuit(c);

  return 0;
}