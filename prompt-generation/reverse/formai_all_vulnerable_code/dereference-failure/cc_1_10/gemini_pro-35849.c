//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the types of nodes in the circuit.
typedef enum {
  NODE_TYPE_INPUT,
  NODE_TYPE_OUTPUT,
  NODE_TYPE_AND,
  NODE_TYPE_OR,
  NODE_TYPE_NOT
} node_type;

// Define the structure of a node in the circuit.
typedef struct node {
  node_type type;
  int num_inputs;
  int *inputs;
  int output;
} node;

// Create a new node of the specified type.
node *create_node(node_type type, int num_inputs, int *inputs) {
  node *new_node = malloc(sizeof(node));
  new_node->type = type;
  new_node->num_inputs = num_inputs;
  new_node->inputs = inputs;
  new_node->output = 0;
  return new_node;
}

// Free the memory allocated for a node.
void free_node(node *node) {
  free(node->inputs);
  free(node);
}

// Evaluate the output of a node.
void evaluate_node(node *node) {
  switch (node->type) {
    case NODE_TYPE_INPUT:
      // Input nodes have no inputs, so their output is simply their input value.
      node->output = node->inputs[0];
      break;
    case NODE_TYPE_OUTPUT:
      // Output nodes have no inputs, so their output is simply their output value.
      node->output = node->inputs[0];
      break;
    case NODE_TYPE_AND:
      // AND nodes output 1 if all of their inputs are 1, and 0 otherwise.
      node->output = 1;
      for (int i = 0; i < node->num_inputs; i++) {
        if (node->inputs[i] == 0) {
          node->output = 0;
          break;
        }
      }
      break;
    case NODE_TYPE_OR:
      // OR nodes output 1 if any of their inputs are 1, and 0 otherwise.
      node->output = 0;
      for (int i = 0; i < node->num_inputs; i++) {
        if (node->inputs[i] == 1) {
          node->output = 1;
          break;
        }
      }
      break;
    case NODE_TYPE_NOT:
      // NOT nodes output 1 if their input is 0, and 0 otherwise.
      node->output = !node->inputs[0];
      break;
  }
}

// Print the circuit to the console.
void print_circuit(node *nodes, int num_nodes) {
  for (int i = 0; i < num_nodes; i++) {
    node *node = &nodes[i];
    printf("Node %d: type %d, num_inputs %d, inputs [", i, node->type, node->num_inputs);
    for (int j = 0; j < node->num_inputs; j++) {
      printf("%d, ", node->inputs[j]);
    }
    printf("], output %d\n", node->output);
  }
}

// Free the memory allocated for the circuit.
void free_circuit(node *nodes, int num_nodes) {
  for (int i = 0; i < num_nodes; i++) {
    free_node(&nodes[i]);
  }
  free(nodes);
}

// Create a simple circuit.
node *create_circuit() {
  // Create the input nodes.
  node *input_node1 = create_node(NODE_TYPE_INPUT, 1, (int[]){0});
  node *input_node2 = create_node(NODE_TYPE_INPUT, 1, (int[]){0});

  // Create the AND node.
  node *and_node = create_node(NODE_TYPE_AND, 2, (int[]){input_node1->output, input_node2->output});

  // Create the output node.
  node *output_node = create_node(NODE_TYPE_OUTPUT, 1, (int[]){and_node->output});

  // Return the array of nodes.
  return (node[]){*input_node1, *input_node2, *and_node, *output_node};
}

// Simulate the circuit.
void simulate_circuit(node *nodes, int num_nodes) {
  // Set the input values.
  nodes[0].inputs[0] = 1;
  nodes[1].inputs[0] = 0;

  // Evaluate the nodes in the circuit.
  for (int i = 0; i < num_nodes; i++) {
    evaluate_node(&nodes[i]);
  }

  // Print the output value.
  printf("Output: %d\n", nodes[num_nodes - 1].output);
}

int main() {
  // Create the circuit.
  node *nodes = create_circuit();
  int num_nodes = sizeof(nodes) / sizeof(nodes[0]);

  // Print the circuit.
  print_circuit(nodes, num_nodes);

  // Simulate the circuit.
  simulate_circuit(nodes, num_nodes);

  // Free the memory allocated for the circuit.
  free_circuit(nodes, num_nodes);

  return 0;
}