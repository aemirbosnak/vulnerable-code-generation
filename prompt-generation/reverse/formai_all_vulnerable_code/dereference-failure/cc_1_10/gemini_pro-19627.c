//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the types of nodes in the circuit.
typedef enum {
  NODE_TYPE_INPUT,
  NODE_TYPE_OUTPUT,
  NODE_TYPE_AND,
  NODE_TYPE_OR,
  NODE_TYPE_NOT
} node_type_t;

// Define the structure of a node in the circuit.
typedef struct node {
  node_type_t type;  // The type of the node.
  int num_inputs;    // The number of inputs to the node.
  int *inputs;       // The indices of the input nodes.
  int output;        // The index of the output node.
} node_t;

// Define the structure of the circuit.
typedef struct circuit {
  int num_nodes;  // The number of nodes in the circuit.
  node_t *nodes;  // The array of nodes in the circuit.
} circuit_t;

// Create a new circuit.
circuit_t *circuit_create(int num_nodes) {
  circuit_t *circuit = malloc(sizeof(circuit_t));
  circuit->num_nodes = num_nodes;
  circuit->nodes = malloc(sizeof(node_t) * num_nodes);
  return circuit;
}

// Destroy a circuit.
void circuit_destroy(circuit_t *circuit) {
  free(circuit->nodes);
  free(circuit);
}

// Add a new node to the circuit.
void circuit_add_node(circuit_t *circuit, node_type_t type, int num_inputs, int *inputs,
                        int output) {
  node_t *node = &circuit->nodes[circuit->num_nodes];
  node->type = type;
  node->num_inputs = num_inputs;
  node->inputs = inputs;
  node->output = output;
  circuit->num_nodes++;
}

// Simulate the circuit.
void circuit_simulate(circuit_t *circuit, int *inputs, int *outputs) {
  // Initialize the output values to 0.
  for (int i = 0; i < circuit->num_nodes; i++) {
    circuit->nodes[i].output = 0;
  }

  // Iterate over the nodes in the circuit.
  for (int i = 0; i < circuit->num_nodes; i++) {
    node_t *node = &circuit->nodes[i];

    // Compute the output value of the node.
    switch (node->type) {
      case NODE_TYPE_INPUT:
        node->output = inputs[i];
        break;
      case NODE_TYPE_OUTPUT:
        outputs[i] = node->output;
        break;
      case NODE_TYPE_AND:
        node->output = 1;
        for (int j = 0; j < node->num_inputs; j++) {
          node->output &= circuit->nodes[node->inputs[j]].output;
        }
        break;
      case NODE_TYPE_OR:
        node->output = 0;
        for (int j = 0; j < node->num_inputs; j++) {
          node->output |= circuit->nodes[node->inputs[j]].output;
        }
        break;
      case NODE_TYPE_NOT:
        node->output = !circuit->nodes[node->inputs[0]].output;
        break;
    }
  }
}

// Print the circuit.
void circuit_print(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    node_t *node = &circuit->nodes[i];

    printf("Node %d:\n", i);
    printf("  Type: %d\n", node->type);
    printf("  Num inputs: %d\n", node->num_inputs);
    printf("  Inputs: ");
    for (int j = 0; j < node->num_inputs; j++) {
      printf("%d ", node->inputs[j]);
    }
    printf("\n");
    printf("  Output: %d\n", node->output);
    printf("\n");
  }
}

// Main function.
int main() {
  // Create a new circuit.
  circuit_t *circuit = circuit_create(5);

  // Add nodes to the circuit.
  circuit_add_node(circuit, NODE_TYPE_INPUT, 0, NULL, 0);
  circuit_add_node(circuit, NODE_TYPE_INPUT, 0, NULL, 1);
  circuit_add_node(circuit, NODE_TYPE_AND, 2, (int[]){0, 1}, 2);
  circuit_add_node(circuit, NODE_TYPE_NOT, 1, (int[]){2}, 3);
  circuit_add_node(circuit, NODE_TYPE_OUTPUT, 1, (int[]){3}, 4);

  // Print the circuit.
  circuit_print(circuit);

  // Simulate the circuit.
  int inputs[] = {0, 1};
  int outputs[1];
  circuit_simulate(circuit, inputs, outputs);

  // Print the output of the circuit.
  printf("Output: %d\n", outputs[0]);

  // Destroy the circuit.
  circuit_destroy(circuit);

  return 0;
}