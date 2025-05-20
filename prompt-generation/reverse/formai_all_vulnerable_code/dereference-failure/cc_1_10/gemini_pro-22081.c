//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: calm
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
circuit_t *circuit_create() {
  circuit_t *circuit = malloc(sizeof(circuit_t));
  circuit->num_nodes = 0;
  circuit->nodes = NULL;
  return circuit;
}

// Destroy a circuit
void circuit_destroy(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    free(circuit->nodes[i].inputs);
  }
  free(circuit->nodes);
  free(circuit);
}

// Add a node to the circuit
void circuit_add_node(circuit_t *circuit, node_type_t type, int num_inputs, int *inputs, int output) {
  circuit->num_nodes++;
  circuit->nodes = realloc(circuit->nodes, circuit->num_nodes * sizeof(node_t));
  node_t *node = &circuit->nodes[circuit->num_nodes - 1];
  node->type = type;
  node->num_inputs = num_inputs;
  node->inputs = malloc(num_inputs * sizeof(int));
  memcpy(node->inputs, inputs, num_inputs * sizeof(int));
  node->output = output;
}

// Evaluate the circuit
void circuit_evaluate(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    node_t *node = &circuit->nodes[i];
    switch (node->type) {
      case NODE_TYPE_INPUT:
        // Input nodes have no inputs, so their output is simply their own value
        node->output = node->inputs[0];
        break;
      case NODE_TYPE_OUTPUT:
        // Output nodes have no outputs, so their value is simply the value of their input
        node->output = node->inputs[0];
        break;
      case NODE_TYPE_AND:
        // AND nodes output 1 if all of their inputs are 1, otherwise they output 0
        node->output = 1;
        for (int j = 0; j < node->num_inputs; j++) {
          node->output &= circuit->nodes[node->inputs[j]].output;
        }
        break;
      case NODE_TYPE_OR:
        // OR nodes output 1 if any of their inputs are 1, otherwise they output 0
        node->output = 0;
        for (int j = 0; j < node->num_inputs; j++) {
          node->output |= circuit->nodes[node->inputs[j]].output;
        }
        break;
      case NODE_TYPE_NOT:
        // NOT nodes output 1 if their input is 0, otherwise they output 0
        node->output = !circuit->nodes[node->inputs[0]].output;
        break;
    }
  }
}

// Print the circuit
void circuit_print(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    node_t *node = &circuit->nodes[i];
    printf("Node %d: type %d, num_inputs %d, inputs [", i, node->type, node->num_inputs);
    for (int j = 0; j < node->num_inputs; j++) {
      printf("%d ", node->inputs[j]);
    }
    printf("], output %d\n", node->output);
  }
}

// Main function
int main() {
  // Create a new circuit
  circuit_t *circuit = circuit_create();

  // Add nodes to the circuit
  circuit_add_node(circuit, NODE_TYPE_INPUT, 0, NULL, 0);
  circuit_add_node(circuit, NODE_TYPE_INPUT, 0, NULL, 1);
  circuit_add_node(circuit, NODE_TYPE_AND, 2, (int[]){0, 1}, 2);
  circuit_add_node(circuit, NODE_TYPE_OUTPUT, 1, (int[]){2}, 3);

  // Evaluate the circuit
  circuit_evaluate(circuit);

  // Print the circuit
  circuit_print(circuit);

  // Destroy the circuit
  circuit_destroy(circuit);

  return 0;
}