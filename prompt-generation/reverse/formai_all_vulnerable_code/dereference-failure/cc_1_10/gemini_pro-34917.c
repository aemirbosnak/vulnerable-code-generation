//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of nodes in the circuit
#define MAX_NODES 100

// Define the maximum number of inputs to a node
#define MAX_INPUTS 10

// Define the data structure for a node in the circuit
typedef struct node {
  int id;
  int type;
  int num_inputs;
  int inputs[MAX_INPUTS];
  int output;
} node_t;

// Define the data structure for the circuit
typedef struct circuit {
  int num_nodes;
  node_t nodes[MAX_NODES];
} circuit_t;

// Create a new circuit
circuit_t* create_circuit() {
  circuit_t* circuit = (circuit_t*)malloc(sizeof(circuit_t));
  circuit->num_nodes = 0;
  return circuit;
}

// Add a new node to the circuit
void add_node(circuit_t* circuit, int type, int num_inputs, int* inputs) {
  node_t* node = &circuit->nodes[circuit->num_nodes++];
  node->id = circuit->num_nodes;
  node->type = type;
  node->num_inputs = num_inputs;
  memcpy(node->inputs, inputs, sizeof(int) * num_inputs);
  node->output = 0;
}

// Evaluate the circuit
void evaluate_circuit(circuit_t* circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    node_t* node = &circuit->nodes[i];
    switch (node->type) {
      case 0: // Input node
        node->output = node->inputs[0];
        break;
      case 1: // AND gate
        node->output = 0;
        for (int j = 0; j < node->num_inputs; j++) {
          node->output &= circuit->nodes[node->inputs[j]].output;
        }
        break;
      case 2: // OR gate
        node->output = 0;
        for (int j = 0; j < node->num_inputs; j++) {
          node->output |= circuit->nodes[node->inputs[j]].output;
        }
        break;
      case 3: // NOT gate
        node->output = !circuit->nodes[node->inputs[0]].output;
        break;
    }
  }
}

// Print the circuit
void print_circuit(circuit_t* circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    node_t* node = &circuit->nodes[i];
    printf("Node %d: type %d, num_inputs %d, inputs [", node->id, node->type, node->num_inputs);
    for (int j = 0; j < node->num_inputs; j++) {
      printf("%d ", node->inputs[j]);
    }
    printf("], output %d\n", node->output);
  }
}

// Free the circuit
void free_circuit(circuit_t* circuit) {
  free(circuit);
}

// Main function
int main() {
  // Create a new circuit
  circuit_t* circuit = create_circuit();

  // Add nodes to the circuit
  add_node(circuit, 0, 1, (int[]){0}); // Input node A
  add_node(circuit, 0, 1, (int[]){1}); // Input node B
  add_node(circuit, 1, 2, (int[]){2, 3}); // AND gate C = A AND B
  add_node(circuit, 2, 2, (int[]){2, 3}); // OR gate D = A OR B
  add_node(circuit, 3, 1, (int[]){4}); // NOT gate E = NOT C

  // Evaluate the circuit
  evaluate_circuit(circuit);

  // Print the circuit
  print_circuit(circuit);

  // Free the circuit
  free_circuit(circuit);

  return 0;
}