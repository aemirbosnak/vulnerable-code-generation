//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of nodes in the circuit
#define MAX_NODES 100

// Define the data structure for a node in the circuit
typedef struct node {
  int id;
  int type;
  double value;
  struct node *next;
} node_t;

// Define the data structure for the circuit
typedef struct circuit {
  int num_nodes;
  node_t *nodes[MAX_NODES];
} circuit_t;

// Create a new circuit
circuit_t *create_circuit() {
  circuit_t *circuit = (circuit_t *)malloc(sizeof(circuit_t));
  circuit->num_nodes = 0;
  for (int i = 0; i < MAX_NODES; i++) {
    circuit->nodes[i] = NULL;
  }
  return circuit;
}

// Add a new node to the circuit
void add_node(circuit_t *circuit, int id, int type, double value) {
  if (circuit->num_nodes >= MAX_NODES) {
    printf("Error: Maximum number of nodes exceeded\n");
    return;
  }
  node_t *node = (node_t *)malloc(sizeof(node_t));
  node->id = id;
  node->type = type;
  node->value = value;
  node->next = NULL;
  circuit->nodes[circuit->num_nodes++] = node;
}

// Get the node with the given ID
node_t *get_node(circuit_t *circuit, int id) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    if (circuit->nodes[i]->id == id) {
      return circuit->nodes[i];
    }
  }
  return NULL;
}

// Simulate the circuit
void simulate_circuit(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    node_t *node = circuit->nodes[i];
    switch (node->type) {
      case 0: // Input node
        break;
      case 1: // Output node
        printf("Output node %d: %.2f\n", node->id, node->value);
        break;
      case 2: // Resistor node
        node->value = (node->next->value - node->value) / 100;
        break;
      case 3: // Capacitor node
        node->value += (node->next->value - node->value) / 1000;
        break;
      case 4: // Inductor node
        node->value += (node->next->value - node->value) * 1000;
        break;
      case 5: // Voltage source node
        node->value = 10;
        break;
      case 6: // Current source node
        node->value = 1;
        break;
    }
  }
}

// Free the circuit
void free_circuit(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    free(circuit->nodes[i]);
  }
  free(circuit);
}

// Main function
int main() {
  // Create a new circuit
  circuit_t *circuit = create_circuit();

  // Add nodes to the circuit
  add_node(circuit, 1, 0, 0); // Input node
  add_node(circuit, 2, 2, 0); // Resistor node
  add_node(circuit, 3, 3, 0); // Capacitor node
  add_node(circuit, 4, 4, 0); // Inductor node
  add_node(circuit, 5, 5, 0); // Voltage source node
  add_node(circuit, 6, 6, 0); // Current source node
  add_node(circuit, 7, 1, 0); // Output node

  // Connect the nodes
  get_node(circuit, 1)->next = get_node(circuit, 2);
  get_node(circuit, 2)->next = get_node(circuit, 3);
  get_node(circuit, 3)->next = get_node(circuit, 4);
  get_node(circuit, 4)->next = get_node(circuit, 5);
  get_node(circuit, 5)->next = get_node(circuit, 6);
  get_node(circuit, 6)->next = get_node(circuit, 7);

  // Simulate the circuit
  simulate_circuit(circuit);

  // Free the circuit
  free_circuit(circuit);

  return 0;
}