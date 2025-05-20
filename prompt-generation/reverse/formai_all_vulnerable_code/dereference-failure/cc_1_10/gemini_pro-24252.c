//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of nodes in the circuit
#define MAX_NODES 100

// Define the types of nodes in the circuit
typedef enum {
  INPUT,
  OUTPUT,
  AND,
  OR,
  NOT
} node_type;

// Define the structure of a node in the circuit
typedef struct node {
  node_type type;
  int value;
  int num_inputs;
  int *inputs;
} node;

// Define the structure of the circuit
typedef struct circuit {
  int num_nodes;
  node *nodes;
} circuit;

// Create a new circuit
circuit *create_circuit() {
  circuit *c = malloc(sizeof(circuit));
  c->num_nodes = 0;
  c->nodes = malloc(MAX_NODES * sizeof(node));
  return c;
}

// Destroy a circuit
void destroy_circuit(circuit *c) {
  free(c->nodes);
  free(c);
}

// Add a new node to the circuit
void add_node(circuit *c, node_type type, int num_inputs, int *inputs) {
  node *n = &c->nodes[c->num_nodes++];
  n->type = type;
  n->value = 0;
  n->num_inputs = num_inputs;
  n->inputs = inputs;
}

// Evaluate the circuit
void evaluate_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    node *n = &c->nodes[i];
    switch (n->type) {
      case INPUT:
        // Do nothing
        break;
      case OUTPUT:
        // Set the value of the output node to the value of its input node
        n->value = c->nodes[n->inputs[0]].value;
        break;
      case AND:
        // Set the value of the AND node to the AND of its input nodes
        n->value = c->nodes[n->inputs[0]].value && c->nodes[n->inputs[1]].value;
        break;
      case OR:
        // Set the value of the OR node to the OR of its input nodes
        n->value = c->nodes[n->inputs[0]].value || c->nodes[n->inputs[1]].value;
        break;
      case NOT:
        // Set the value of the NOT node to the NOT of its input node
        n->value = !c->nodes[n->inputs[0]].value;
        break;
    }
  }
}

// Print the circuit
void print_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    node *n = &c->nodes[i];
    printf("Node %d: type = %d, value = %d, inputs = ", i, n->type, n->value);
    for (int j = 0; j < n->num_inputs; j++) {
      printf("%d ", n->inputs[j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a new circuit
  circuit *c = create_circuit();

  // Add input nodes to the circuit
  int input1 = 0;
  int input2 = 1;
  add_node(c, INPUT, 0, &input1);
  add_node(c, INPUT, 0, &input2);

  // Add an AND node to the circuit
  int and_output = 2;
  add_node(c, AND, 2, (int[]){0, 1});

  // Add an OR node to the circuit
  int or_output = 3;
  add_node(c, OR, 2, (int[]){0, 1});

  // Add a NOT node to the circuit
  int not_output = 4;
  add_node(c, NOT, 1, (int[]){0});

  // Evaluate the circuit
  evaluate_circuit(c);

  // Print the circuit
  print_circuit(c);

  // Destroy the circuit
  destroy_circuit(c);

  return 0;
}