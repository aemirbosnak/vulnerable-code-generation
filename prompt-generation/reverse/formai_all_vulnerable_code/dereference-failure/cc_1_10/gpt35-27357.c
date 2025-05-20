//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

// Number of inputs in the circuit
#define NUM_INPUTS 3

// Number of gates in the circuit
#define NUM_GATES 2

// Gate types
typedef enum {
  AND,
  XOR,
} GateType;

// Circuit gates
typedef struct {
  GateType type;
  int input1;
  int input2;
  int output;
} Gate;

// Circuit inputs
typedef struct {
  bool values[NUM_INPUTS];
} Inputs;

// Evaluate a gate and return the output value
bool evaluate_gate(Gate* gate, Inputs* inputs) {
  bool input1 = inputs->values[gate->input1];
  bool input2 = inputs->values[gate->input2];

  switch (gate->type) {
    case AND:
      return input1 && input2;
    case XOR:
      return input1 != input2;
    default:
      return false;
  }
}

// Evaluate the entire circuit and return the output value
bool evaluate_circuit(Gate* gates, Inputs* inputs) {
  bool values[NUM_INPUTS + NUM_GATES] = {0};

  // Copy input values to the values array
  for (int i = 0; i < NUM_INPUTS; i++) {
    values[i] = inputs->values[i];
  }

  // Evaluate each gate in order
  for (int i = 0; i < NUM_GATES; i++) {
    Gate* gate = &gates[i];
    bool output = evaluate_gate(gate, inputs);
    values[NUM_INPUTS + i] = output;
  }

  // Return the final output value
  return values[NUM_INPUTS + NUM_GATES - 1];
}

int main() {
  // Define circuit inputs
  Inputs inputs = {
    .values = { true, false, true },
  };

  // Define circuit gates
  Gate gates[NUM_GATES] = {
    { .type = XOR, .input1 = 0, .input2 = 1, .output = 3 },
    { .type = AND, .input1 = 2, .input2 = 3, .output = 4 },
  };

  // Evaluate the circuit and print the output
  printf("Circuit output: %d\n", evaluate_circuit(gates, &inputs));

  return 0;
}