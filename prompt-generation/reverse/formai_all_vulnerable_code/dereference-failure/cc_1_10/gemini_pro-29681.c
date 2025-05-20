//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the circuit elements
typedef enum {
  RESISTOR,
  CAPACITOR,
  INDUCTOR
} element_type;

typedef struct {
  element_type type;
  double value;
} element;

// Define the circuit
typedef struct {
  int num_elements;
  element *elements;
} circuit;

// Create a new circuit
circuit *create_circuit(int num_elements) {
  circuit *c = malloc(sizeof(circuit));
  c->num_elements = num_elements;
  c->elements = malloc(num_elements * sizeof(element));
  return c;
}

// Add an element to a circuit
void add_element(circuit *c, element_type type, double value) {
  c->elements[c->num_elements].type = type;
  c->elements[c->num_elements].value = value;
  c->num_elements++;
}

// Print a circuit
void print_circuit(circuit *c) {
  for (int i = 0; i < c->num_elements; i++) {
    switch (c->elements[i].type) {
      case RESISTOR:
        printf("Resistor: %f ohms\n", c->elements[i].value);
        break;
      case CAPACITOR:
        printf("Capacitor: %f farads\n", c->elements[i].value);
        break;
      case INDUCTOR:
        printf("Inductor: %f henrys\n", c->elements[i].value);
        break;
    }
  }
}

// Free a circuit
void free_circuit(circuit *c) {
  free(c->elements);
  free(c);
}

// Main function
int main() {
  // Create a new circuit
  circuit *c = create_circuit(3);

  // Add elements to the circuit
  add_element(c, RESISTOR, 100);
  add_element(c, CAPACITOR, 1e-6);
  add_element(c, INDUCTOR, 1e-3);

  // Print the circuit
  print_circuit(c);

  // Free the circuit
  free_circuit(c);

  return 0;
}