//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct Circuit {
  int numGates;
  struct Gate **gates;
} Circuit;

typedef struct Gate {
  char type;
  int numInputs;
  struct Gate **inputs;
  int output;
} Gate;

Circuit *createCircuit(int numGates) {
  Circuit *circuit = malloc(sizeof(Circuit));
  circuit->numGates = numGates;
  circuit->gates = malloc(numGates * sizeof(Gate *));

  for (int i = 0; i < numGates; i++) {
    circuit->gates[i] = malloc(sizeof(Gate));
  }

  return circuit;
}

void simulateCircuit(Circuit *circuit) {
  for (int i = 0; i < circuit->numGates; i++) {
    Gate *gate = circuit->gates[i];

    switch (gate->type) {
      case 'AND':
        gate->output = gate->inputs[0]->output && gate->inputs[1]->output;
        break;
      case 'OR':
        gate->output = gate->inputs[0]->output || gate->inputs[1]->output;
        break;
      case 'NOT':
        gate->output = !gate->inputs[0]->output;
        break;
      default:
        break;
    }
  }
}

int main() {
  Circuit *circuit = createCircuit(4);

  circuit->gates[0]->type = 'NOT';
  circuit->gates[0]->numInputs = 1;
  circuit->gates[0]->inputs[0] = circuit->gates[1];

  circuit->gates[1]->type = 'AND';
  circuit->gates[1]->numInputs = 2;
  circuit->gates[1]->inputs[0] = circuit->gates[0];
  circuit->gates[1]->inputs[1] = circuit->gates[2];

  circuit->gates[2]->type = 'OR';
  circuit->gates[2]->numInputs = 2;
  circuit->gates[2]->inputs[0] = circuit->gates[3];
  circuit->gates[2]->inputs[1] = circuit->gates[1];

  circuit->gates[3]->type = 'AND';
  circuit->gates[3]->numInputs = 2;
  circuit->gates[3]->inputs[0] = circuit->gates[0]->output;
  circuit->gates[3]->inputs[1] = circuit->gates[2]->output;

  simulateCircuit(circuit);

  printf("Output: %d\n", circuit->gates[3]->output);

  free(circuit);

  return 0;
}