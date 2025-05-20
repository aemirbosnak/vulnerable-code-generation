//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
  int value;
  struct _Node *next;
} Node;

typedef struct _Circuit {
  Node *inputs;
  Node *outputs;
  int num_gates;
  int num_inputs;
  int num_outputs;
} Circuit;

Circuit *create_circuit(int num_gates, int num_inputs, int num_outputs) {
  Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
  circuit->num_gates = num_gates;
  circuit->num_inputs = num_inputs;
  circuit->num_outputs = num_outputs;
  circuit->inputs = (Node *)malloc(sizeof(Node) * num_inputs);
  circuit->outputs = (Node *)malloc(sizeof(Node) * num_outputs);
  return circuit;
}

void destroy_circuit(Circuit *circuit) {
  free(circuit->inputs);
  free(circuit->outputs);
  free(circuit);
}

void add_gate(Circuit *circuit, int type, int num_inputs, int *inputs, int output) {
  Node *gate = (Node *)malloc(sizeof(Node));
  gate->value = type;
  gate->next = NULL;

  // Add the inputs to the gate
  for (int i = 0; i < num_inputs; i++) {
    Node *input = (Node *)malloc(sizeof(Node));
    input->value = inputs[i];
    input->next = gate->next;
    gate->next = input;
  }

  // Add the output to the circuit
  Node *output_node = (Node *)malloc(sizeof(Node));
  output_node->value = output;
  output_node->next = circuit->outputs->next;
  circuit->outputs->next = output_node;
}

void simulate_circuit(Circuit *circuit) {
  // Initialize the inputs to 0
  for (int i = 0; i < circuit->num_inputs; i++) {
    circuit->inputs[i].value = 0;
  }

  // Simulate the circuit
  for (int i = 0; i < circuit->num_gates; i++) {
    Node *gate = circuit->inputs[i].next;
    int output = 0;

    switch (gate->value) {
    case 0:  // AND gate
      output = gate->next->value & gate->next->next->value;
      break;
    case 1:  // OR gate
      output = gate->next->value | gate->next->next->value;
      break;
    case 2:  // NOT gate
      output = !gate->next->value;
      break;
    }

    // Update the output
    circuit->outputs[i].value = output;
  }
}

void print_circuit(Circuit *circuit) {
  printf("Circuit:\n");
  printf("  Inputs: ");
  for (int i = 0; i < circuit->num_inputs; i++) {
    printf("%d ", circuit->inputs[i].value);
  }
  printf("\n");
  printf("  Outputs: ");
  for (int i = 0; i < circuit->num_outputs; i++) {
    printf("%d ", circuit->outputs[i].value);
  }
  printf("\n");
}

int main() {
  // Create a circuit
  Circuit *circuit = create_circuit(3, 2, 1);

  // Add the gates to the circuit
  add_gate(circuit, 0, 2, (int[]){0, 1}, 2);
  add_gate(circuit, 1, 2, (int[]){2, 3}, 4);
  add_gate(circuit, 2, 1, (int[]){4}, 5);

  // Simulate the circuit
  simulate_circuit(circuit);

  // Print the circuit
  print_circuit(circuit);

  // Destroy the circuit
  destroy_circuit(circuit);

  return 0;
}