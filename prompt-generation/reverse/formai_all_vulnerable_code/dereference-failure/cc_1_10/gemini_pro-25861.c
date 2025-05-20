//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the data structure for a node in the circuit
typedef struct node {
  int value;
  struct node *next;
} node;

// Define the data structure for a circuit
typedef struct circuit {
  int num_nodes;
  node *head;
} circuit;

// Create a new circuit
circuit *create_circuit() {
  circuit *c = malloc(sizeof(circuit));
  c->num_nodes = 0;
  c->head = NULL;
  return c;
}

// Add a node to the circuit
void add_node(circuit *c, int value) {
  node *new_node = malloc(sizeof(node));
  new_node->value = value;
  new_node->next = c->head;
  c->head = new_node;
  c->num_nodes++;
}

// Free the memory allocated for the circuit
void free_circuit(circuit *c) {
  while (c->head != NULL) {
    node *next = c->head->next;
    free(c->head);
    c->head = next;
  }
  free(c);
}

// Print the circuit to the console
void print_circuit(circuit *c) {
  printf("Circuit:\n");
  for (node *n = c->head; n != NULL; n = n->next) {
    printf("  %d\n", n->value);
  }
}

// Simulate the circuit
void simulate_circuit(circuit *c) {
  printf("Simulating circuit:\n");
  for (node *n = c->head; n != NULL; n = n->next) {
    printf("  %d\n", n->value);
  }
}

int main() {
  // Create a new circuit
  circuit *c = create_circuit();

  // Add some nodes to the circuit
  add_node(c, 1);
  add_node(c, 0);
  add_node(c, 1);
  add_node(c, 0);

  // Print the circuit to the console
  print_circuit(c);

  // Simulate the circuit
  simulate_circuit(c);

  // Free the memory allocated for the circuit
  free_circuit(c);

  return 0;
}