//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the circuit components
typedef enum {
  RESISTOR,
  CAPACITOR,
  INDUCTOR
} component_type;

typedef struct {
  component_type type;
  double value;
} component;

// Define the circuit
typedef struct {
  int num_components;
  component *components;
} circuit;

// Create a new circuit
circuit *circuit_new(int num_components) {
  circuit *c = malloc(sizeof(circuit));
  c->num_components = num_components;
  c->components = malloc(sizeof(component) * num_components);
  return c;
}

// Free the memory allocated for a circuit
void circuit_free(circuit *c) {
  free(c->components);
  free(c);
}

// Add a component to a circuit
void circuit_add_component(circuit *c, component_type type, double value) {
  c->components[c->num_components].type = type;
  c->components[c->num_components].value = value;
  c->num_components++;
}

// Simulate a circuit
void circuit_simulate(circuit *c) {
  for (int i = 0; i < c->num_components; i++) {
    component *component = &c->components[i];
    switch (component->type) {
      case RESISTOR:
        printf("Resistor with value %f ohms\n", component->value);
        break;
      case CAPACITOR:
        printf("Capacitor with value %f farads\n", component->value);
        break;
      case INDUCTOR:
        printf("Inductor with value %f henrys\n", component->value);
        break;
    }
  }
}

// Main function
int main() {
  // Create a new circuit
  circuit *c = circuit_new(3);

  // Add components to the circuit
  circuit_add_component(c, RESISTOR, 100);
  circuit_add_component(c, CAPACITOR, 10e-6);
  circuit_add_component(c, INDUCTOR, 10e-3);

  // Simulate the circuit
  circuit_simulate(c);

  // Free the memory allocated for the circuit
  circuit_free(c);

  return 0;
}