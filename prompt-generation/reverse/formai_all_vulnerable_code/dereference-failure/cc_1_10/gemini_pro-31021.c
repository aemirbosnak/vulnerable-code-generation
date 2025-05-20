//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define the boolean data type
typedef unsigned char boolean;

// Define the circuit element types
typedef enum {
  INPUT,
  OUTPUT,
  AND,
  OR,
  NOT
} circuit_element_type;

// Define the circuit element structure
typedef struct circuit_element {
  circuit_element_type type;
  int num_inputs;
  int *inputs;
  boolean output;
} circuit_element;

// Create a new circuit element
circuit_element *new_circuit_element(circuit_element_type type, int num_inputs, int *inputs) {
  circuit_element *element = malloc(sizeof(circuit_element));
  element->type = type;
  element->num_inputs = num_inputs;
  element->inputs = inputs;
  element->output = 0;
  return element;
}

// Free a circuit element
void free_circuit_element(circuit_element *element) {
  free(element->inputs);
  free(element);
}

// Evaluate a circuit element
void evaluate_circuit_element(circuit_element *element) {
  switch (element->type) {
    case INPUT:
      // Input elements have no inputs, so their output is simply their value
      element->output = element->inputs[0];
      break;
    case OUTPUT:
      // Output elements have no inputs, so their output is simply their value
      element->output = element->inputs[0];
      break;
    case AND:
      // AND elements have two inputs, and their output is 1 if both inputs are 1, and 0 otherwise
      element->output = element->inputs[0] && element->inputs[1];
      break;
    case OR:
      // OR elements have two inputs, and their output is 1 if either input is 1, and 0 otherwise
      element->output = element->inputs[0] || element->inputs[1];
      break;
    case NOT:
      // NOT elements have one input, and their output is 1 if the input is 0, and 0 otherwise
      element->output = !element->inputs[0];
      break;
  }
}

// Create a new circuit
circuit_element **new_circuit(int num_elements) {
  circuit_element **circuit = malloc(sizeof(circuit_element *) * num_elements);
  for (int i = 0; i < num_elements; i++) {
    circuit[i] = NULL;
  }
  return circuit;
}

// Free a circuit
void free_circuit(circuit_element **circuit, int num_elements) {
  for (int i = 0; i < num_elements; i++) {
    free_circuit_element(circuit[i]);
  }
  free(circuit);
}

// Evaluate a circuit
void evaluate_circuit(circuit_element **circuit, int num_elements) {
  for (int i = 0; i < num_elements; i++) {
    evaluate_circuit_element(circuit[i]);
  }
}

// Print a circuit
void print_circuit(circuit_element **circuit, int num_elements) {
  for (int i = 0; i < num_elements; i++) {
    printf("Element %d: type = %d, num_inputs = %d, inputs = [", i, circuit[i]->type, circuit[i]->num_inputs);
    for (int j = 0; j < circuit[i]->num_inputs; j++) {
      printf("%d", circuit[i]->inputs[j]);
      if (j < circuit[i]->num_inputs - 1) {
        printf(", ");
      }
    }
    printf("], output = %d\n", circuit[i]->output);
  }
}

// Main function
int main() {
  // Create a new circuit
  circuit_element **circuit = new_circuit(5);

  // Create the input elements
  circuit[0] = new_circuit_element(INPUT, 1, (int[]){0});
  circuit[1] = new_circuit_element(INPUT, 1, (int[]){1});

  // Create the output element
  circuit[2] = new_circuit_element(OUTPUT, 1, (int[]){2});

  // Create the AND element
  circuit[3] = new_circuit_element(AND, 2, (int[]){0, 1});

  // Create the OR element
  circuit[4] = new_circuit_element(OR, 2, (int[]){3, 1});

  // Evaluate the circuit
  evaluate_circuit(circuit, 5);

  // Print the circuit
  print_circuit(circuit, 5);

  // Free the circuit
  free_circuit(circuit, 5);

  return 0;
}