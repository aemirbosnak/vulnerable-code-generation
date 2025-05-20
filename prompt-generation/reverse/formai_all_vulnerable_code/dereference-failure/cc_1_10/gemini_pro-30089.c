//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the circuit elements
#define RESISTOR 1
#define CAPACITOR 2
#define INDUCTOR 3
#define VOLTAGE_SOURCE 4
#define CURRENT_SOURCE 5

// Define the circuit nodes
#define GROUND 0

// Define the maximum number of elements and nodes in the circuit
#define MAX_ELEMENTS 100
#define MAX_NODES 100

// Define the data structure for each circuit element
typedef struct {
  int type;
  int node1;
  int node2;
  double value;
} circuit_element;

// Define the data structure for the circuit
typedef struct {
  int num_elements;
  circuit_element elements[MAX_ELEMENTS];
  int num_nodes;
  int node_voltages[MAX_NODES];
} circuit;

// Create a new circuit
circuit* create_circuit() {
  circuit* c = malloc(sizeof(circuit));
  c->num_elements = 0;
  c->num_nodes = 0;
  return c;
}

// Add an element to the circuit
void add_element(circuit* c, int type, int node1, int node2, double value) {
  c->elements[c->num_elements].type = type;
  c->elements[c->num_elements].node1 = node1;
  c->elements[c->num_elements].node2 = node2;
  c->elements[c->num_elements].value = value;
  c->num_elements++;
}

// Add a node to the circuit
void add_node(circuit* c, int node) {
  c->node_voltages[c->num_nodes] = 0;
  c->num_nodes++;
}

// Solve the circuit
void solve_circuit(circuit* c) {
  // Create the matrix equation
  double A[MAX_NODES][MAX_NODES];
  double b[MAX_NODES];
  for (int i = 0; i < c->num_nodes; i++) {
    for (int j = 0; j < c->num_nodes; j++) {
      A[i][j] = 0;
    }
    b[i] = 0;
  }

  // Populate the matrix equation
  for (int i = 0; i < c->num_elements; i++) {
    int type = c->elements[i].type;
    int node1 = c->elements[i].node1;
    int node2 = c->elements[i].node2;
    double value = c->elements[i].value;

    switch (type) {
      case RESISTOR:
        A[node1][node1] += 1 / value;
        A[node1][node2] -= 1 / value;
        A[node2][node1] -= 1 / value;
        A[node2][node2] += 1 / value;
        break;
      case CAPACITOR:
        A[node1][node1] += 1 / (value * c->elements[i].value);
        A[node1][node2] -= 1 / (value * c->elements[i].value);
        A[node2][node1] -= 1 / (value * c->elements[i].value);
        A[node2][node2] += 1 / (value * c->elements[i].value);
        break;
      case INDUCTOR:
        A[node1][node1] += value * c->elements[i].value;
        A[node1][node2] -= value * c->elements[i].value;
        A[node2][node1] -= value * c->elements[i].value;
        A[node2][node2] += value * c->elements[i].value;
        break;
      case VOLTAGE_SOURCE:
        b[node1] += value;
        b[node2] -= value;
        break;
      case CURRENT_SOURCE:
        A[node1][node1] += 1;
        A[node1][node2] -= 1;
        A[node2][node1] -= 1;
        A[node2][node2] += 1;
        b[node1] -= value;
        b[node2] += value;
        break;
    }
  }

  // Solve the matrix equation
  for (int i = 0; i < c->num_nodes; i++) {
    for (int j = 0; j < c->num_nodes; j++) {
      if (i == j) {
        for (int k = i + 1; k < c->num_nodes; k++) {
          double factor = A[k][j] / A[i][j];
          for (int l = 0; l < c->num_nodes; l++) {
            A[k][l] -= factor * A[i][l];
          }
          b[k] -= factor * b[i];
        }
      }
    }
  }

  for (int i = c->num_nodes - 1; i >= 0; i--) {
    for (int j = i + 1; j < c->num_nodes; j++) {
      b[i] -= A[i][j] * c->node_voltages[j];
    }
    c->node_voltages[i] = b[i] / A[i][i];
  }
}

// Print the circuit
void print_circuit(circuit* c) {
  printf("Circuit:\n");
  printf("  Num elements: %d\n", c->num_elements);
  printf("  Num nodes: %d\n", c->num_nodes);
  for (int i = 0; i < c->num_elements; i++) {
    printf("  Element %d:\n", i);
    printf("    Type: %d\n", c->elements[i].type);
    printf("    Node 1: %d\n", c->elements[i].node1);
    printf("    Node 2: %d\n", c->elements[i].node2);
    printf("    Value: %f\n", c->elements[i].value);
  }
  for (int i = 0; i < c->num_nodes; i++) {
    printf("  Node %d:\n", i);
    printf("    Voltage: %f\n", c->node_voltages[i]);
  }
}

// Free the circuit
void free_circuit(circuit* c) {
  free(c);
}

// Main function
int main() {
  // Create a new circuit
  circuit* c = create_circuit();

  // Add elements to the circuit
  add_element(c, RESISTOR, 1, 2, 100);
  add_element(c, CAPACITOR, 2, 3, 1e-6);
  add_element(c, INDUCTOR, 3, 1, 1e-3);
  add_element(c, VOLTAGE_SOURCE, 1, 0, 10);

  // Add nodes to the circuit
  add_node(c, 1);
  add_node(c, 2);
  add_node(c, 3);

  // Solve the circuit
  solve_circuit(c);

  // Print the circuit
  print_circuit(c);

  // Free the circuit
  free_circuit(c);

  return 0;
}