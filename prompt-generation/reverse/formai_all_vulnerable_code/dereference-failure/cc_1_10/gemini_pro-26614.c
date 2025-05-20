//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct node {
  int value;
  struct node *next;
} node;

// Circuit structure
typedef struct circuit {
  int num_nodes;
  node **nodes;
} circuit;

// Create a new circuit
circuit *new_circuit(int num_nodes) {
  circuit *c = malloc(sizeof(circuit));
  c->num_nodes = num_nodes;
  c->nodes = malloc(sizeof(node *) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    c->nodes[i] = NULL;
  }
  return c;
}

// Add a new node to the circuit
void add_node(circuit *c, int value) {
  node *n = malloc(sizeof(node));
  n->value = value;
  n->next = NULL;

  if (c->nodes[value] == NULL) {
    c->nodes[value] = n;
  } else {
    node *current = c->nodes[value];
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = n;
  }
}

// Delete a node from the circuit
void delete_node(circuit *c, int value) {
  if (c->nodes[value] == NULL) {
    return;
  }

  if (c->nodes[value]->next == NULL) {
    free(c->nodes[value]);
    c->nodes[value] = NULL;
    return;
  }

  node *current = c->nodes[value];
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

// Get the value of a node
int get_value(circuit *c, int value) {
  if (c->nodes[value] == NULL) {
    return 0;
  }

  return c->nodes[value]->value;
}

// Set the value of a node
void set_value(circuit *c, int value, int new_value) {
  if (c->nodes[value] == NULL) {
    add_node(c, value);
  }

  c->nodes[value]->value = new_value;
}

// Print the circuit
void print_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    if (c->nodes[i] != NULL) {
      printf("%d: ", i);
      node *current = c->nodes[i];
      while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
      }
      printf("\n");
    }
  }
}

// Free the circuit
void free_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    if (c->nodes[i] != NULL) {
      node *current = c->nodes[i];
      while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
      }
    }
  }
  free(c->nodes);
  free(c);
}

int main() {
  // Create a new circuit
  circuit *c = new_circuit(10);

  // Add some nodes to the circuit
  add_node(c, 0);
  add_node(c, 1);
  add_node(c, 2);
  add_node(c, 3);
  add_node(c, 4);

  // Set the value of some nodes
  set_value(c, 0, 1);
  set_value(c, 2, 3);
  set_value(c, 4, 5);

  // Print the circuit
  print_circuit(c);

  // Free the circuit
  free_circuit(c);

  return 0;
}