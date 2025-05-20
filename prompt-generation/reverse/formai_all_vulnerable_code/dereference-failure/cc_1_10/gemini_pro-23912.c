//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of nodes in the circuit
#define MAX_NODES 100

// Define the types of nodes in the circuit
typedef enum {
  NODE_TYPE_INPUT,
  NODE_TYPE_OUTPUT,
  NODE_TYPE_AND,
  NODE_TYPE_OR,
  NODE_TYPE_NOT
} node_type_t;

// Define the structure of a node in the circuit
typedef struct {
  node_type_t type;
  int num_inputs;
  int *inputs;
  int output;
} node_t;

// Define the structure of the circuit
typedef struct {
  int num_nodes;
  node_t *nodes;
} circuit_t;

// Create a new circuit
circuit_t *create_circuit() {
  circuit_t *circuit = (circuit_t *)malloc(sizeof(circuit_t));
  circuit->num_nodes = 0;
  circuit->nodes = NULL;
  return circuit;
}

// Destroy a circuit
void destroy_circuit(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    free(circuit->nodes[i].inputs);
  }
  free(circuit->nodes);
  free(circuit);
}

// Add a node to the circuit
void add_node(circuit_t *circuit, node_type_t type, int num_inputs, int *inputs, int output) {
  node_t node;
  node.type = type;
  node.num_inputs = num_inputs;
  node.inputs = inputs;
  node.output = output;
  circuit->nodes[circuit->num_nodes++] = node;
}

// Evaluate the circuit
void evaluate_circuit(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    node_t *node = &circuit->nodes[i];
    switch (node->type) {
      case NODE_TYPE_INPUT:
        node->output = node->inputs[0];
        break;
      case NODE_TYPE_OUTPUT:
        printf("Output: %d\n", node->output);
        break;
      case NODE_TYPE_AND:
        node->output = node->inputs[0] & node->inputs[1];
        break;
      case NODE_TYPE_OR:
        node->output = node->inputs[0] | node->inputs[1];
        break;
      case NODE_TYPE_NOT:
        node->output = !node->inputs[0];
        break;
    }
  }
}

// Print the circuit
void print_circuit(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    node_t *node = &circuit->nodes[i];
    printf("Node %d: type = %d, num_inputs = %d, inputs = [", i, node->type, node->num_inputs);
    for (int j = 0; j < node->num_inputs; j++) {
      printf("%d, ", node->inputs[j]);
    }
    printf("], output = %d\n", node->output);
  }
}

// Main function
int main() {
  // Create a new circuit
  circuit_t *circuit = create_circuit();

  // Add nodes to the circuit
  add_node(circuit, NODE_TYPE_INPUT, 1, (int []){0}, 0);
  add_node(circuit, NODE_TYPE_INPUT, 1, (int []){1}, 1);
  add_node(circuit, NODE_TYPE_AND, 2, (int []){0, 1}, 2);
  add_node(circuit, NODE_TYPE_OUTPUT, 1, (int []){2}, 3);

  // Evaluate the circuit
  evaluate_circuit(circuit);

  // Print the circuit
  print_circuit(circuit);

  // Destroy the circuit
  destroy_circuit(circuit);

  return 0;
}