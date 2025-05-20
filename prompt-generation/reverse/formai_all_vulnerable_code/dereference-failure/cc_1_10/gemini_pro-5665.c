//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int value;
  struct _node *next;
} node;

typedef struct _circuit {
  int num_inputs;
  int num_outputs;
  node **inputs;
  node **outputs;
} circuit;

node *create_node(int value) {
  node *new_node = malloc(sizeof(node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

circuit *create_circuit(int num_inputs, int num_outputs) {
  circuit *new_circuit = malloc(sizeof(circuit));
  new_circuit->num_inputs = num_inputs;
  new_circuit->num_outputs = num_outputs;
  new_circuit->inputs = malloc(sizeof(node *) * num_inputs);
  new_circuit->outputs = malloc(sizeof(node *) * num_outputs);
  return new_circuit;
}

void connect_nodes(node *input, node *output) {
  output->next = input;
}

void set_input(circuit *circuit, int input_index, int value) {
  circuit->inputs[input_index]->value = value;
}

int get_output(circuit *circuit, int output_index) {
  return circuit->outputs[output_index]->value;
}

void simulate_circuit(circuit *circuit) {
  for (int i = 0; i < circuit->num_outputs; i++) {
    node *current_node = circuit->outputs[i];
    while (current_node != NULL) {
      if (current_node->value == 1) {
        circuit->outputs[i]->value = 1;
        break;
      }
      current_node = current_node->next;
    }
  }
}

void print_circuit(circuit *circuit) {
  for (int i = 0; i < circuit->num_inputs; i++) {
    printf("Input %d: %d\n", i, circuit->inputs[i]->value);
  }
  for (int i = 0; i < circuit->num_outputs; i++) {
    printf("Output %d: %d\n", i, circuit->outputs[i]->value);
  }
}

int main() {
  circuit *circuit = create_circuit(2, 1);

  circuit->inputs[0] = create_node(0);
  circuit->inputs[1] = create_node(0);
  circuit->outputs[0] = create_node(0);

  connect_nodes(circuit->inputs[0], circuit->outputs[0]);
  connect_nodes(circuit->inputs[1], circuit->outputs[0]);

  set_input(circuit, 0, 1);
  set_input(circuit, 1, 1);

  simulate_circuit(circuit);

  print_circuit(circuit);

  return 0;
}